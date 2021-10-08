/******************************************************************************
*   Ismael Holguin 
*   Assignment 1
*   EE5379 Network Protocols
*   Develop a network application that performs computation.
*   Fall 2021 Electrical Engineering Undergraduate 
*   CLIENT FILE
*******************************************************************************/
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080

int main(int argc, char ** argv){
    char message[20] = "Jesus Client...";
    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if(client_socket < 0){
        printf("Error creating the socket\n");
        return -1;
    }

    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htons(0);

   
    if( connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address)) < 0){
        printf("Error connecting to server\n");
        return -1;
    }
    
    char buffer[20];
    while(1){
        printf("Enter message: ");
        scanf("%s", buffer);
        send(client_socket,buffer, sizeof(buffer),0);
    }

    close(client_socket);

    return 0;
}