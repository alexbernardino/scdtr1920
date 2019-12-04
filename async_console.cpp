//
// Created by Alexandre Bernardino on 01/12/2019.
//

//ASYNC_CONSOLE
#include <iostream>
#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
#include <boost/asio.hpp>
#include <unistd.h>
using ec = const boost::system::error_code;
using sz = std::size_t;
using boost::asio::chrono::seconds;
//globals
boost::asio::io_service io;
boost::asio::steady_timer tim {io};
boost::asio::posix::stream_descriptor
        stm_desc{io, ::dup(STDIN_FILENO)};
boost::asio::streambuf stm_buff { 1024 };
//forward declarations required for handlers
void start_timer ();
void start_read_input ();
//handlers
void handle_timer (ec & err)  {
    std::cout << '*' << std::endl;
    start_timer();
}
void handle_read_input (ec & err, sz len)           {
    std::cout << &stm_buff << std::endl;
    start_read_input();
}
//async initiators
void start_timer() {
    tim.expires_from_now(seconds{ 1 });
    tim.async_wait(handle_timer);
}
void start_read_input()  {
    async_read_until(stm_desc, stm_buff, '\n',
                     handle_read_input);
}
//main
int main (int argc, char* argv[])   {
    start_timer();
    start_read_input();
    io.run();
}
