/***************************************************************
*   Name:       Ismael Holguin
*   Course:     EE4393 Network Protocols
*   Assignment: SERVER FILE
*   Semester:   Fall 2021 
*   BS Electrical Engineering Undergraduate
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>


#define OP_SUM  0
#define OP_MEAN 1
#define OP_MIN  2
#define OP_MAX  3

#define MAX_SIZE 10
typedef struct Computation_t{
    int operation;
    double number[MAX_SIZE];
}Computation_t;


#define PORT 8080
int main(int argc, char **argv){
    int server_socket,client_socket;
    int opt = 1;
     struct sockaddr_in server_address, client_address;
   socklen_t  client_address_size = sizeof(client_address);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if( server_socket < 0){
        printf("Could not create the socket...\n");
        return -1;
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if( bind(server_socket, (struct sockaddr*)&server_address,sizeof(server_address)) < 0){
        printf("Error during binding...\n");
        return -1;
    }
    if(listen(server_socket,3) < 0){
        printf("Error during listening...\n");
        return -1;
    }
    client_socket = accept(server_socket,(struct sockaddr*)&client_address, (socklen_t*)&client_address_size);
    if( client_socket< 0){
        printf("Error during acceptance\n");
        return -1;
    }


    Computation_t server_com;

    recv(client_socket, &server_com, sizeof(server_com),0);

    double data = 0.0;

    if(server_com.operation == OP_SUM){
        double sum = 0;
        for(int i =0; i < MAX_SIZE; i++){
            sum += server_com.number[i];
        }
        data = sum;
    }else if(server_com.operation == OP_MEAN){
        double sum = 0;
        for(int i =0; i < MAX_SIZE; i++){
            sum += server_com.number[i];
        }
        data = sum / MAX_SIZE;
    }else if(server_com.operation == OP_MIN){
        double min_val = server_com.number[0];
        for(int i =0; i < MAX_SIZE; i++){
            if(server_com.number[i] < min_val){
                min_val = server_com.number[i];
            }
        }
        data = min_val;
        //find min
    }else if(server_com.operation == OP_MAX){
        double max_val = server_com.number[0];
        for(int i =0; i < MAX_SIZE; i++){
            if(server_com.number[i] > max_val){
                max_val = server_com.number[i];
            }
        }
        data = max_val;
        //find max
    }else{
        return 0;
        //error handle return -1
    }

    send(client_socket, &data,sizeof(data), 0);
    
    return 0;
}
