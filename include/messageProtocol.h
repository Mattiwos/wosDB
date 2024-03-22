#ifndef messageProtcol_H
#define messageProtcol_H
#include <string>
#include <sys/types.h>
#include <any>

using namespace std;

typedef enum typeDatabases { KV_DB, DO_DN, HYBRID_DO } typeDB;

#pragma pack(push, 1) // Set alignment to 1 byte

//base header
struct MsgHeader {
    int32_t messageLength; // total message size, including this
    int32_t requestID; // identifier for this message
    int32_t responseTo; // requestID from the original request
        //   (used in responses from db)
    int32_t opCode; // request type - see table below for details
};
//OP_Connect : 0
#pragma pack(pop) // Restore default alignment

#pragma pack(push, 1) // Set alignment to 1 byte

struct OP_CONNECT { //connection needs to be SSL/TLS
    //store locally after hashing password
    //search local file for password and etc
    //might not need to encrupt it since ssl will take care of that
    MsgHeader header;
    char username[200];
    char password[200];
};
#pragma pack(pop) // Restore default alignment

#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_CREATE {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string databaseName;
    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment

//OP_insert

//OP_update

//OP_delete
#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_DELETE {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string databaseName;
    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment OP_CREATE_COLLECTION

#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_CREATE_COLLECTION {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string collectionName;
    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment OP_CREATE_COLLECTION

#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_DELETE_COLLECTION {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string collectionName;
    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment OP_INSERT_COLLECTION

#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_INSERT_COLLECTION {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string collectionName;
    std::string key;
    std::string value; //change the value to and from binary whenever needed

    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment OP_UPDATE_COLLECTION
#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_UPDATE_COLLECTION {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string collectionName;
    std::string key;
    std::string value; //change the value to and from binary whenever needed

    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment OP_UPDATE_COLLECTION
//OP_reply


#pragma pack(push, 1) // Set alignment to 1 byte

// OP_createDB 1:
struct OP_CREATE_DATABASE {
    typeDB type; //just create KV_DB
    int32_t ZERO; // future use
    string databaseName;
    // std::string key; //This could be users and auths
    // std::string value; //change the value to and from binary whenever needed

    int32_t flags; //encyption, compress, ???. etc
};

#pragma pack(pop) // Restore default alignment OP_UPDATE_COLLECTION
//OP_reply

#endif
