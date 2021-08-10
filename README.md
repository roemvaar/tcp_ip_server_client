# TCP Server/Client in C++

TCP Server/Client written in C++.

This code was written to run on Linux machines, and to compile with C++ 11.

The server class supports multiple clients.

## Build Instructions

This project is set to use CMake. In addition, CMake builds a static library
file to hold the common code to both server and client.

To build:

```
$ git clone https://github.com/roemvaar/sockets.git
$ cd sockets
$ mkdir build
$ cmake ..
$ make
```

## Usage

### Examples - Single Client

### Examples - Multiclient

Inspiration: github.com/elhayra/tcp_server_client
