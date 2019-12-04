//
// Created by Alexandre Bernardino on 01/12/2019.
//
//TIMER_SYNC.

#include <iostream>
#include <boost/asio.hpp>

int main() {
   boost::asio::io_context io;
   boost::asio::steady_timer tim {io};
   int count = 0;
   for(;;) {
      tim.expires_from_now(boost::asio::chrono::milliseconds {1000} );
      tim.wait();  //blocks here
      std::cout << count++ << std::endl;
   }
}
