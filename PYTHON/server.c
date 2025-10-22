#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 3490
#define BUF_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sockfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    int addr_size;
    char buffer[BUF_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Could not create socket. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Listen
    if (listen(sockfd, 5) == SOCKET_ERROR) {
        printf("Listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("Server started on port %d. Waiting for clients...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
        if (new_fd == INVALID_SOCKET) {
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        printf("Client connected!\n");

        while (1) {
            int n = recv(new_fd, buffer, BUF_SIZE - 1, 0);
            if (n <= 0) break; // client disconnected

            buffer[n] = '\0';
            printf("Client says: %s", buffer);
        }

        printf("Client disconnected.\n");
        closesocket(new_fd);
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
