#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>


int main(int argc, char* argv[]) {
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cerr << "Can't create a socket!";
        return -1;
    }

    // Bind the socket to an IP port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);   // htons - take cares of little and big endiannes
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);    // inet_pton - from ip address to number
    
    if(bind(listening, AF_INET, (sockaddr*)&hint, sizeof(hint)) == -1) {
        cerr << "Can't bind to IP/Port";
        return -2;
    }

    // Mark the socket for listening in
    if(listen(listening, SOMAXCONN) == -1) {
        cerr << "Can't listen!";
        return -3;
    }

    // Accept a call
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    if(clientSocket == -1) {
        cerr << "Problem with client connecting!";
        return -4;
    }

    // Close the listening socket
    close(listening);

    memset(host, 0, NI_MAXHOST); // Clean memory before getting any input data from client
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, 0);

    if(result) {
        cout << host << " connected on " << service << endl;
    } else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on " << ntohs(client.sin_port) << endl;
    }

    // While receiving display message, echo message
    char buf[4096];
    while(true) {
        // Clear the buffer
        memset(buf, 0, 4096);

        // Wait for a message
        int bytesRecv = recv(clientSocket, buf, 4096, 0);
        if(bytesRecv == -1) {
            cerr << "There was a connection issue" << endl;
            break;
        }

        if(bytesRecv == 0) {
            cout << "The client disconnected" << endl;
            break;
        }

        // Display message
        cout << "Received: " << string(buf, 0, bytesRecv) << endl;
        
        // Resend message
        send(clientSocket, buf, bytesRecv + 1, 0);
    }

    // Close socket
    close(clientSocket);

    return 0;
}
