# Specify the minimum version for CMake
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.2)

# Project's name
project(tcp_ip_server_client)

# Executable for client
add_executable(client src/client.cpp)

# Executable for server
add_executable(server src/server.cpp)
