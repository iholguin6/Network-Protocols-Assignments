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
// MACROs
#define OP_SUM  0
#define OP_MEAN 1
#define OP_MIN  2
#define OP_MAX  3

#define MAX_SIZE 10
typedef struct Computation_t{
    int operation;
    double number[MAX_SIZE];
}Computation_t;

int main(int argc, char ** argv){
    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if(client_socket < 0){
        printf("Error creating the socket\n");
        return -1;
    }
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if( connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address)) < 0){
        printf("Error connecting to server\n");
        return -1;
    }
    
    Computation_t client_com;

    printf("Enter OPERATION:\t\n"
                "OP_SUM  0\n"
                "OP_MEAN 1\n"
                "OP_MIN  2\n"
                "OP_MAX  3\n"
                );
    scanf("%d", &client_com.operation);
    int i;
    for(i =0; i < MAX_SIZE; i++){
        printf("Enter number[%i]: ", i);
        scanf("%lf",&client_com.number[i]);
    }

    send(client_socket, &client_com, sizeof(client_com), 0);

    double data;
    recv(client_socket, &data, sizeof(data),0);
    
    printf("The data is: %lf\n", data);

    return 0;
}