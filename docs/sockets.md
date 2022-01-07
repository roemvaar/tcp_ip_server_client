# Socket Programming

Sockets let apps attach to the local network at different ports.

## Server/Client Applications

The basic mechanisms of a client-server setup are:
  
  1. A client app send a request to a server app
  2. The server app returns a reply
  3. Some of the basic data communications between client and server are:
      - File Transfer - sends name and gets a file
      - Web Page - sends url and gets a page
      - Echo - sends a message and gets it back

## Server Socket

  1. Create a **socket** - get the file descriptor!
  2. **bind** to an address - what port am I on?
  3. **listen** on a port, and wait for a connection to be established
  4. **accept** the connection from a client
  5. **send/recv** - the same way we read and write for a file
  6. **shutdown** - to end read/write
  7. **close** to releases data

## Client Socket

  1. create a **socket**
  2. **bind** - this is probably unnecesary because you're the client not the server
  3. **connect** to a server
  4. **send/recv** - repeat until we have or receive data
  5. **shutdown** to end read/write
  6. **close** to realeases data

## References

- https://www.bogotobogo.com/cplusplus/sockets_server_client.php
