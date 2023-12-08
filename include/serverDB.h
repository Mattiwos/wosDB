#ifndef serverDB_H
#define serverDB_H

#include <sys/socket.h>
#include <netinet/in.h>


class serverDB{

    public:
        int sockfd;    
        int nthreads;
        struct sockaddr_in address;
        void startServer();
        void stopServer();
        void listenServer(int threadcount);


};

#endif
