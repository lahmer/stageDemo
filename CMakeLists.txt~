cmake_minimum_required(VERSION 3.6)
project(FileServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES main.cpp FileServer.cpp FileServer.h File.cpp File.h Server.cpp Server.h)
add_executable(FileServer ${SOURCE_FILES})


target_link_libraries( FileServer ndn-cxx boost_system boost_thread pthread crypto++ sqlite3 boost_filesystem boost_random boost_regex
        boost_chrono)
