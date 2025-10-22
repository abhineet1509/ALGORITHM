#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUF_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in server_addr;
    int addr_len = sizeof(server_addr);
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
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    printf("Enter message (type 'exit' to quit):\n");

    while (1) {
        printf("Message: ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strncmp(buffer, "exit", 4) == 0) break;

        buffer[strcspn(buffer, "\n")] = 0; // Remove newline

        // Send message
        if (sendto(sockfd, buffer, strlen(buffer), 0,
                   (struct sockaddr*)&server_addr, addr_len) == SOCKET_ERROR) {
            printf("sendto failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        // Receive response
        int n = recvfrom(sockfd, buffer, BUF_SIZE - 1, 0,
                         (struct sockaddr*)&server_addr, &addr_len);
        if (n == SOCKET_ERROR) {
            printf("recvfrom failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        buffer[n] = '\0';
        printf("Uppercase from server: %s\n", buffer);
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
