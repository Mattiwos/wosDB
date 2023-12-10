#include "serverDB.h"

#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <thread>
//#include <fstream>      // std::ifstream
#include <cstring>
#include <mutex>
#include <unistd.h>
std::mutex mtx;

#define PORT        8080
#define BUFFER_SIZE 2048

using namespace std;

void serverDB ::startServer() {
    int opt = 1;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "socket failed" << endl;
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        cout << "setsockopt" << endl;
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    // Forcefully attaching socket to the port 8080
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        cout << "bind failed" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Starting Server" << endl;
    return;
}
void serverDB ::listenServer(int threadcount) {
    nthreads = threadcount; //create nthread in h file
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

            // Parse connection with a class (not implemented in your provided code)
            // Read it
            int total_read = 0;
            char buffer[BUFFER_SIZE];
            while (total_read < BUFFER_SIZE && strstr(buffer, "\r\n\r\n") == NULL) {
                int bytes_read = 0;
                bytes_read = read(conn, buffer + total_read, BUFFER_SIZE - total_read);

                total_read += bytes_read;
                if (bytes_read == 0) {
                    break;
                } else if (bytes_read == -1) {
                    // Handle error
                    break;
                }
            }
            cout << "Read: " << buffer << endl;

            // Process the read data or perform other tasks

            // Close the connection (you might want to add proper handling here)
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
