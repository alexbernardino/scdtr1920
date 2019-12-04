//
// Created by Alexandre Bernardino on 01/12/2019.
//

#include <iostream>
#include <string>
#include <sstream>
#include <boost/asio.hpp>
using namespace boost::system;
using namespace boost::asio;
//GLOBALS
io_context io;
serial_port sp {io};
deadline_timer tim {io};
streambuf read_buf; //read buffer
int counter = 0;
//HANDLERS FOR ASYNC CALLBACKS
//forward declaration of write_handler to timer_handler
void write_handler(const error_code &ec, size_t nbytes);
//timer_handler
void timer_handler(const error_code &ec) {
   //timer expired – launch new write operation
   std::ostringstream os;
   os << "Counter = " << ++counter;
   async_write(sp, buffer(os.str()), write_handler);
}
void write_handler(const error_code &ec, size_t nbytes) {
    //writer done – program new deadline
    tim.expires_from_now(boost::posix_time::seconds(5));
    tim.async_wait(timer_handler);
}
void read_handler(const error_code &ec, size_t nbytes) {
    //data is now available at read_buf
    std::cout << &read_buf;
    //program new read cycle
    async_read_until(sp,read_buf,'\n',read_handler);
}
//MAIN : ERROR CHECKING ABSENT FOR SIMPLICITY
int main() {
    boost::system::error_code ec;
    sp.open("/dev/cu.usbmodem14101", ec);    //connect to port
    if(ec) {
        std::cout << "Can not open serial port" << std::endl;
        return -1;
    }
    sp.set_option(serial_port_base::baud_rate(9600),ec);
    //program timer for write operations
    tim.expires_from_now(boost::posix_time::seconds(5));
    tim.async_wait(timer_handler);
    //program chain of read operations
    async_read_until(sp,read_buf,'\n',read_handler);
    io.run(); //get things rolling
}
