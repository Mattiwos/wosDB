#ifndef handleDB_H
#define handleDB_H

#include "db_interface.h"
#include "messageProtocol.h"

#include <string>
#include <unordered_map>

#define BUFFER_SIZE 2048

using namespace std;
struct Request {
    std::string method; // HTTP method (GET, POST, etc.)
    std::string path; // Requested path
    std::unordered_map<std::string, std::string> headers; // HTTP headers
    std::string body; // Request body (for POST requests, etc.)
};
typedef struct Response Response_t;

extern const Response_t RESPONSE_OK; //200
extern const Response_t RESPONSE_CREATED; //201
extern const Response_t RESPONSE_BAD_REQUEST; //400
extern const Response_t RESPONSE_FORBIDDEN; //403?
extern const Response_t RESPONSE_NOT_FOUND; //404
extern const Response_t RESPONSE_INTERNAL_SERVER_ERROR; //500?
extern const Response_t RESPONSE_NOT_IMPLEMENTED; //501?
extern const Response_t RESPONSE_VERSION_NOT_SUPPORTED; //505?

class HandleConnection {
private:
    int connid;
    struct Request request;
    Database db;
    //parses buffer with regex
    void parseRequest(char buffer[BUFFER_SIZE]);
    //Innput header line
    //Output data containing it
    void getHeader(char buffer[BUFFER_SIZE]);
    //writes content of socket into the buffer passed in
    void readConn(char buffer[BUFFER_SIZE]);
    //responses
    void respond(); //maybe take in code
    //writes out to buffer about bytes time
    void write_n_bytes(int socketid, char *buffer, int length);
    //parses emssag header
    void printMsg(MsgHeader x);

    void handle();

public:
    HandleConnection();
    HandleConnection(int conn);
    //create connection will get connid
    //build a connection request struct containaining information about the request
    //create an enum for it
};

#endif
