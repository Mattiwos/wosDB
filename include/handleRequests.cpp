#include "handleRequests.h"
#include "messageProtocol.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include "db_interface.h"

//todo`
//create a verified variable to confim a connection OP has been sent and established


HandleConnection::HandleConnection() : connid(-1) {
  cout << "Error handling connection" << endl;
}
HandleConnection::HandleConnection(int conn) : connid(conn) {
  handle();
}
void HandleConnection :: handle(){
  //read into the buffer
  char buffer[BUFFER_SIZE];
  readConn(buffer);
  //parse it 
  parseRequest(buffer);
  
  //build struct 
  //identify res
  //send res
  //follow the command parsed
  return;
}
void HandleConnection :: readConn(char buffer[BUFFER_SIZE]){
  //int total_read = 0;
  //while (total_read < BUFFER_SIZE ) {
  //    int bytes_read = 0;
  //    bytes_read = read(connid, buffer + total_read, BUFFER_SIZE - total_read);
  //
  //    total_read += bytes_read;
  //    if (bytes_read == 0) {
  //        break;
  //    } else if (bytes_read == -1) {
  //        // Handle error
  //        break;
  //    }
  //}
  return;
  
} 
//struct MsgHeader {
//    int32_t   messageLength; // total message size, including this
//    int32_t   requestID;     // identifier for this message
//    int32_t   responseTo;    // requestID from the original request
//                           //   (used in responses from db)
//    int32_t  opCode;        // request type - see table below for details
//} 
void HandleConnection :: printMsg (MsgHeader x){
  cout << "Printing Message Header" << endl;
  cout << "MessageLength: " << x.messageLength <<endl;
  cout << "requestID: " << x.requestID <<endl;
  cout << "ResponseTo: " << x.responseTo <<endl;
  cout << "OpCode: " << x.opCode <<endl;
  //Op code
  
}
void HandleConnection :: parseRequest(char buffer[BUFFER_SIZE]){
  //read msg headero
  MsgHeader header;
    // Receive data into a buffer
  int bytesRead = recv(connid, &header, sizeof(MsgHeader),0);
  //create a database in private
  //memcpy(&header, buffer, sizeof(MsgHeader));
  printMsg(header);
  //cout << "buffer: " << buffer << endl;
  //cout << "Buffer_size: "<< sizeof(buffer) << endl;
  cout << "header_size: "<< sizeof(MsgHeader) << endl;
  if (header.opCode == 0){
    cout << "CONNECT" << endl;
    OP_CONNECT connectData;
    ssize_t bytesRead = recv(connid, &connectData, sizeof(OP_CONNECT), 0);
    if (bytesRead == -1) {
        perror("Error receiving data");
        return;
    } else if (bytesRead == 0) {
        std::cerr << "Connection closed by the client\n";
        return;
    } else if (bytesRead != sizeof(OP_CONNECT)) {
        std::cerr << "Received incomplete data\n";
        return;
    }
    //while (bytesReceived < sizeof(OP_CONNECT)) {
    //  ssize_t bytesRead = recv(connid, reinterpret_cast<char*>(&connectData) + bytesReceived, sizeof(OP_CONNECT) - bytesReceived, 0);
    //  if (bytesRead <= 0) {
    //      // Handle error or connection closed
    //      break;
    //  }
    //  bytesReceived += bytesRead;
    //}
    //bytesRead += recv(connid, &conn, sizeof(OP_CONNECT),0);
    //memcpy(&conn, buffer, sizeof(OP_CONNECT));
    //int status = db.connectDatabase(conn);
    cout << "User: " << connectData.password << endl;
    //cout << "Connection status: " << status << endl;
  }
  //cout << "Parse this: " << buffer << endl;
  return;
}
