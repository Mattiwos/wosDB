#include "serverDB.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>


#define PORT 8080

using namespace std;

void serverDB :: startServer(){
  int opt = 1;
  if ((sockfd= socket(AF_INET,SOCK_STREAM,0))<0){
    cout << "socket failed" <<endl;
  }
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    cout << "setsockopt" <<endl;
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  // Forcefully attaching socket to the port 8080
  if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
      cout << "bind failed" << endl;
      exit(EXIT_FAILURE);
    }

  cout << "Starting Server" << endl;
  return;

}
void serverDB :: listenServer(int threadcount){
  nthreads = threadcount; //create nthread in h file
  //create threads
  //call worker threads
  if (listen(sockfd, 3) < 0){
    cout << "error with listening" << endl;
  }
  int new_socket;
  socklen_t addrlen = sizeof(address);

  while (1){
    new_socket = accept(sockfd, (struct sockaddr*)&address, &addrlen);
    //push to queue and contuine listening
      
  }
}
//configure the start server to dedicate number of threads 
//createServer(ip address)
//^ maybe in listen(threadcount = ?)
//listen
//accept
//dispath it to worker threads, push to to threadsafe queue
//afterwards the works,pop the queue, will handle the connection
//they will parse the connection and get method and data etc..
//
//
//send the command to DB class where it will have its own rwlock just in case of non atomic functiosn

