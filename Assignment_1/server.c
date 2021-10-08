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

    // if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    // {
    //     printf("error on socket opt\n");
    //     return -1;
    // }
   
    server_address.sin_family = AF_INET;            //Ip4 mode        
    server_address.sin_port = htons(PORT);          //port number
    server_address.sin_addr.s_addr = INADDR_ANY;    //any address    


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

    char buffer[20];
    while(1){
        recv(client_socket,buffer, sizeof(buffer),0);
        printf("Message recieved: %s\n", buffer);
    }
  

    
    return 0;
}