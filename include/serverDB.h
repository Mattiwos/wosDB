#ifndef serverDB_H
#define serverDB_H

#include <netinet/in.h>
#include <queue>
#include <sys/socket.h>
#include "threadsafequeue.h"

class serverDB {

public:
    int sockfd;
    int nthreads;
    ThreadSafeQueue<int> req_queue; //set it to bounded buffer later to retrain overload
    struct sockaddr_in address;
    void startServer();
    void stopServer();
    void listenServer(int threadcount);
    void thread_worker(int thread_id);
};

#endif
