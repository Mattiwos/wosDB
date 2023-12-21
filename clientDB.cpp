#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

#include <stdio.h>
#include "include/messageProtocol.h"
#include <netinet/in.h>

#define PORT 8080


using namespace std;
//struct MsgHeader {
//    int32_t   messageLength; // total message size, including this
//    int32_t   requestID;     // identifier for this message
//    int32_t   responseTo;    // requestID from the original request
//                           //   (used in responses from db)
//    int32_t  opCode;        // request type - see table below for details
//};

int main(){
  //https://www.geeksforgeeks.org/socket-programming-cc/
   int status, client_fd;
   struct sockaddr_in serv_addr;
   char* hello = "Hello from client";
   if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
       cout << "failed" << endl;
       return -1;
   }
 
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;

   serv_addr.sin_port = htons(PORT);
   if ((status = connect (client_fd, (struct sockaddr*) &serv_addr,sizeof(serv_addr))) < 0) {
     cout << "failed" << endl;
     return -1;
    
   }
   //message
   //build message using messageProtocol
   MsgHeader message;
   message.messageLength = 10;
   message.opCode = 0;
   //OP_CONNECT conn;
   ////conn.header = message;
   //memcpy(&conn.header,&message,sizeof(MsgHeader));
   //conn.username = "test";
   //conn.password = "test";
   send(client_fd, &message, sizeof(message),0);
   //cout << sizeof(conn) << endl;
   //close(client_fd);
    // Prepare OP_CONNECT data
   OP_CONNECT connectData;
   connectData.header.messageLength = sizeof(OP_CONNECT);
   connectData.header.requestID = 1; // Replace with a suitable request ID
   connectData.header.responseTo = 0; // Replace with a suitable response ID
   connectData.header.opCode = 0; // Replace with the appropriate OpCode for OP_CONNECT
   connectData.username = "your_username";
   connectData.password = "your_password";
   ssize_t bytesSent = send(client_fd, &connectData, sizeof(OP_CONNECT), 0);
   close(client_fd);
  return 0;
}
