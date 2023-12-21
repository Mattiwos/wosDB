#ifndef messageProtcol_H 
#define messageProtcol_H 
#include <sys/types.h>
#include <string>

using namespace std;

typedef enum typeDatabases {
  KV_DB, DO_DN, HYBRID_DO
} typeDB;
//base header 
struct MsgHeader {
    int32_t   messageLength; // total message size, including this
    int32_t   requestID;     // identifier for this message
    int32_t   responseTo;    // requestID from the original request
                           //   (used in responses from db)
    int32_t  opCode;        // request type - see table below for details
};
//OP_Connect : 0
struct OP_CONNECT {//connection needs to be SSL/TLS
  //store locally after hashing password
  //search local file for password and etc 
  //might not need to encrupt it since ssl will take care of that
  string username;
  string password; 
};
// OP_createDB 1:
struct OP_CREATE {
 typeDB type; //just create KV_DB 
 int32_t ZERO; // future use
 string fullCollectionName;
 int32_t flags; //encyption, compress, ???. etc
};




//OP_insert 

//OP_update


//OP_delete

//OP_reply
#endif
