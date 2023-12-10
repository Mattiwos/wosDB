#include "handleRequests.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>

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
void HandleConnection :: parseRequest(char buffer[BUFFER_SIZE]){
  cout << "Parse this: " << buffer << endl;
  return;
}
