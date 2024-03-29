#include "server/serverDB.h"

#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <thread>
//#include <fstream>      // std::ifstream
#include "server/handleRequests.h"

#include <cstdlib> // For std::getenv
#include <mutex>
#include <unistd.h>

#define BUFFER_SIZE 2048

using namespace std;

void serverDB ::startServer(int port) {
    int opt = 1;
    //const char* db_port = (getenv("DB_PORT"));
    // cout << "Port: " << db_port << endl;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "socket failed" << endl;
    }
#ifdef __APPLE__
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        cout << "setsockopt(SO_REUSEADDR) failed" << endl;
        exit(EXIT_FAILURE);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        cout << "setsockopt(SO_REUSEPORT) failed" << endl;
        exit(EXIT_FAILURE);
    }
#else
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        cout << "setsockopt(SO_REUSEADDR | SO_REUSEPORT) failed" << endl;
        exit(EXIT_FAILURE);
    }
#endif
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    // Forcefully attaching socket to the port 8080
    if (::bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cout << "bind failed" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Starting Server" << endl;
    return;
}
void serverDB ::listenServer(int threadcount) {
    nthreads = threadcount; //// Adjust as needed
    //create nthread in h file
    //create threads
    //call worker threads
    if (listen(sockfd, 3) < 0) {
        cout << "error with listening" << endl;
    }
    int new_socket;
    socklen_t addrlen = sizeof(address);
    //create threads
    thread thread_ids[nthreads];
    for (int i = 0; i < nthreads; ++i) {
        thread_ids[i] = thread(&serverDB::thread_worker, this, i);
    }

    while (1) {
        new_socket = accept(sockfd, (struct sockaddr *) &address, &addrlen);
        //push to queue and contuine listening
        req_queue.enqueue(new_socket);
        //creates a queue for requests
    }
    ////join threads
    for (int i = 0; i < nthreads; i++) {
        thread_ids[i].join();
    }
}
void serverDB ::thread_worker(int thread_id) {
    try {
        cout << "Thread " << thread_id << " starting" << endl;
        while (1) {
            int conn = req_queue.dequeue();
            HandleConnection handle(conn);
            close(conn);
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception in thread " << thread_id << ": " << e.what() << std::endl;
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
