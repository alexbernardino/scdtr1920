cmake_minimum_required(VERSION 3.12)
project(scdtr1920)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

add_executable(sizeof sizeof.cpp)

add_executable(hello hello.cpp)

add_executable(pid pid.cpp main_pid.cpp)

add_executable(sync_timer sync_timer.cpp)
target_link_libraries(sync_timer ${Boost_LIBRARIES})

add_executable(async_timer async_timer.cpp)
target_link_libraries(async_timer ${Boost_LIBRARIES})

add_executable(async_console async_console.cpp)
target_link_libraries(async_console ${Boost_LIBRARIES})

add_executable(async_serial async_serial.cpp)
target_link_libraries(async_serial ${Boost_LIBRARIES})

