cmake_minimum_required(VERSION 3.17)
project(superMarket)

set(CMAKE_CXX_STANDARD 14)

add_executable(superMarket main.cpp itemOps.cpp itemOps.h transactionOps.cpp)