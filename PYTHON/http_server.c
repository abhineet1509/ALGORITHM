#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in server, client;
    int c;
    char buffer[1024];
    
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        return 1;
    }
    printf("Winsock initialized.\n");

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
        return 1;
    }
    printf("Socket created.\n");

    // Prepare sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    printf("Bind done.\n");

    // Listen
    listen(server_fd, 3);
    printf("Server running on http://127.0.0.1:8080\n");

    // Accept and incoming connection
    c = sizeof(struct sockaddr_in);
    new_socket = accept(server_fd, (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET) {
        printf("accept failed with error code : %d", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    printf("Connection accepted.\n");

    // Receive request
    recv(new_socket, buffer, sizeof(buffer), 0);
    printf("Request received:\n%s\n", buffer);

    // Send HTTP response
    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html><body><h1>Welcome!</h1>"
        "<p>Name: Avaneet Kumar</p>"
        "<p>Scholar No: 2311201126</p>"
        "</body></html>";

    send(new_socket, response, strlen(response), 0);

    // Close sockets
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
