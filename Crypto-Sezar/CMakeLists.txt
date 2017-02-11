cmake_minimum_required(VERSION 3.6)
project(Crypto_Sezar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp headers/chrypto.h functions/chrypto.cpp)
add_executable(Crypto_Sezar ${SOURCE_FILES})