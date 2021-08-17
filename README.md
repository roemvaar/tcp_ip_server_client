# TCP Server/Client in C++

TCP Server/Client written in C++.

This code was written to run on Linux machines, and to compile with C++ 11.

The server class supports multiple clients.

## Build Instructions

This project is set to use CMake. In addition, CMake builds a static library
file to hold the common code to both server and client.

To build for the single client:

```
$ git clone https://github.com/roemvaar/tcp_server_client.git
$ cd tcp_server_client
$ mkdir build
$ cmake ..
$ make
```

The commands above generate three files: ```libtcp_client_server.a```,
```tcp_client``` and ```tcp_server```.

## Usage

### Examples - Single Client

To run the single client example, open a terminal, move to the build folder and execute:

```./tcp_server```

In another termina, move to the build folder and execute the client by:

```./tcp_client```

### Examples - Multiclient

For the multiclient example, you have to pass ```--multiclient``` to make as argument,
and then, you will end up with four files: ```libtcp_client_server.a```, ```tcp_client_1```,
```tcp_client_2```, ```tcp_client_3``` and ```tcp_server```.

Inspiration: github.com/elhayra/tcp_server_client
