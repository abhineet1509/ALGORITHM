#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 8080
#define BUF_SIZE 2048

int main() {
    WSADATA wsa;
    SOCKET server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int addr_size;
    char buffer[BUF_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        printf("Could not create socket. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Listen
    if (listen(server_fd, 5) == SOCKET_ERROR) {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    printf("HTTP server started on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (client_fd == INVALID_SOCKET) {
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        // Receive HTTP request (optional)
        int n = recv(client_fd, buffer, BUF_SIZE - 1, 0);
        if (n > 0) {
            buffer[n] = '\0';
            printf("Request:\n%s\n", buffer);
        }

        // Prepare HTTP response
        const char *http_response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<!DOCTYPE html>"
            "<html>"
            "<head>"
            "<title>Welcome Page</title>"
            "<style>"
            "body { text-align: center; font-family: Arial, sans-serif; background-color: #ffffff; }"
            "h1 { color: #333; }"
            "p { font-size: 20px; }"
            "</style>"
            "</head>"
            "<body>"
            "<h1>Welcome to My Page</h1>"
            "<p>Name: Avaneet Kumar</p>"
            "<p>Scholar Number: 2311201126</p>"
            "<p>Enjoy your visit!</p>"
            "</body>"
            "</html>";

        send(client_fd, http_response, strlen(http_response), 0);

        closesocket(client_fd);
    }

    closesocket(server_fd);
    WSACleanup();
    return 0;
}
