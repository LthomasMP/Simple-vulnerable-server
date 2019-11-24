
// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>

#define PORT 12345
#define BUFFER 32

int main(int argc, char const *argv[])
{
    // Connection
    int server_fd, new_socket, valread;
    struct sockaddr_in address; 
    int opt = 1;
    int addrlen = sizeof(address);

    // Credentials
    uint8_t identification_state = 0;
    char buffer [32] = {0};
    char username[32] = {0};
    char password[32] = {0};

    // Shell
    char command[32] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) 
    {
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE); 
    }

    send(new_socket, "decline you identity please\n", 28, 0);
    valread = read( new_socket , buffer, BUFFER);

    strcpy(buffer, username);

    send(new_socket, "password:\n", 11, 0);
    valread = read( new_socket, password, BUFFER);


    if (strcmp(username, "la_ruche\n") == 0 && strcmp(password, "azerty\n") == 0){
        send(new_socket, "Hi la Ruche!\n", 13, 0);
        identification_state = 1;
    }
    else if (strcmp(username, "admin\n") == 0 && strcmp(password, "dojo\n") == 0){
        send(new_socket, "Hi admin!\n", 10, 0);
        identification_state = 2;    }
    else {
        send(new_socket, "Bad authentication\n", 20, 0);
        identification_state = 0;
        return 0;
    }
}
