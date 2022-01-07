# TCP/IP Internet Protocol Suite 

The internet protocol suite, aka TCP/IP, is a set of communications protocols used in the Internet and similar
computer networks. The current foundational protocols in the suite are the Transmission Control Protocol (TCP)
and the Internet Protocol (IP).

TCP/IP was designed to be independent of networking hardware and shouold run accross any connection media. The most
common use is over Ethernet networks.

![image](https://user-images.githubusercontent.com/20572328/148590724-8f063f51-8a13-4e1d-9726-f543beb2de31.png)

On a TCP/IP network every device must have an **IP address**. This address **identifies the device**. However, an IP
address alone is not sufficient for running network applications, as a computer can run **multiple applications**
and/or **services**.

Just as the IP address identifies the computer, the network **port** identifies the **application or service** running
on the computer.

```The use of ports allow computers/devices to run multiple services/applications```

![image](https://user-images.githubusercontent.com/20572328/148590901-58a5e0d8-183f-4aad-8982-689cf4ce55f9.png)

## Port Numbers

A port uses 16 bits and so can therefore have a value from 0 to 65535 decimal

Port numbers are divided into ranges as follows:

  - Ports 0-1023 - Well known ports: Allocated to server services
    - Port 80 - HTTP - Web traffic
    - Port 443 - HTTPS - Secure web traffic
    - Ports 20, 21 - FTP - File Transfer
    - Port 53 - DNS - Domain Name Resolution
    - Port 22 - SSH - Secure Shell
  - Ports 1024-49151 - Registered ports: semi-reserved. User written programs should not use these ports.
  - Ports 49152-65535 - Used by client programs. When a web browser connects to a web server the browser will alllocate itself a port in this range.

## TCP Sockets

A connection between two computers uses a socket.

```A socket is the combination of IP address plus port```

Example: Connecting from your laptop to Google from one browser window, and connecting from another browser window to Facebook.

  - First connection - laptop to Google

The connection would be:

Your PC IP1 + port-60200 <------------> Google IP2 + port-80 (HTTP port)

Client socket = IP1 + 60200
Server socket = IP2 + 80

  - Second connection - laptop to Facebook

The connection would be:

Your PC IP1 + port-60401 <------------> Facebook IP3 + port-443 (HTTPs port)

Client socket = IP1 + 60401
Server socket = IP3 + 443

```Note: IP1 is the IP address on your PC. Client port numbers are dynamically assigned, and can be reused once the session is closed```

## Networking Equipment

- Gateway: converts information, data or other communications from one protocol or format to another. A router may perform some functions of a gateway.
- Router (level 3): operates at networking layer. It routes incoming packets to it's destination using IP/IPx addresses.
- Switch (level 2): operates at the Ethernet layer. It routes incoming messages using MAC addresses.

## References

- http://www.steves-internet-guide.com/tcpip-ports-sockets/
