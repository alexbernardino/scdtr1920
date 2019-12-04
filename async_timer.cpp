//
// Created by Alexandre Bernardino on 01/12/2019.
//

#include <iostream>
#include <boost/asio.hpp>
using boost::asio::chrono::milliseconds;
boost::asio::io_context io;
boost::asio::steady_timer tim {io};
int count = 0;
void deadline_handler(const boost::system::error_code & ec)
{
    std::cout << count++ << std::endl;
    tim.expires_from_now(milliseconds{1000});
    tim.async_wait(deadline_handler);
}
int main()
{
    tim.expires_from_now(milliseconds{1000});
    tim.async_wait(deadline_handler);
    io.run();
}
