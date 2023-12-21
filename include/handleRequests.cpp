#include "handleRequests.h"
#include "messageProtocol.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
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
  int total_read = 0;
  while (total_read < BUFFER_SIZE && strstr(buffer, "\r\n\r\n") == NULL) {
      int bytes_read = 0;
      bytes_read = read(connid, buffer + total_read, BUFFER_SIZE - total_read);
  
      total_read += bytes_read;
      if (bytes_read == 0) {
          break;
      } else if (bytes_read == -1) {
          // Handle error
          break;
      }
  }
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
  struct MsgHeader header;
  //create a database in private
  memcpy(&header, buffer, sizeof(MsgHeader));
  printMsg(header);
  cout << "buffer: " << buffer << endl;
  if (header.opCode == 0){
    struct OP_CONNECT conn;
    memcpy(&conn, buffer, sizeof(OP_CONNECT));
    //int status = db.connectDatabase(conn);
    cout << "User: " << *conn.username << endl;
    //cout << "Connection status: " << status << endl;
  }
  cout << "Parse this: " << buffer << endl;
  return;
}
