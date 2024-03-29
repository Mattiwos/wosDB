#ifndef serverDB_H
#define serverDB_H

#include "threadsafequeue.h"

#include <netinet/in.h>
#include <queue>
#include <sys/socket.h>
#define QUEUE_BUFFER 20

class serverDB {
private:
    int sockfd;

    int nthreads;

    ThreadSafeQueue<int> req_queue {
        QUEUE_BUFFER
    }; //set it to bounded buffer later to retrain overload
    struct sockaddr_in address;
    void thread_worker(int thread_id);

public:
    void startServer(int port);
    void stopServer();
    void listenServer(int threadcount);
};

#endif
