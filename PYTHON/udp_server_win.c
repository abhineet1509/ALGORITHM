#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);
    char buffer[BUF_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Could not create socket. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("UDP Server started on port %d...\n", PORT);

    while (1) {
        int n = recvfrom(sockfd, buffer, BUF_SIZE - 1, 0,
                         (struct sockaddr*)&client_addr, &addr_len);
        if (n == SOCKET_ERROR) {
            printf("recvfrom failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        buffer[n] = '\0';
        printf("Received from client: %s\n", buffer);

        // Convert to uppercase
        for (int i = 0; i < n; i++)
            buffer[i] = toupper(buffer[i]);

        // Send back to client
        sendto(sockfd, buffer, n, 0, (struct sockaddr*)&client_addr, addr_len);
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
