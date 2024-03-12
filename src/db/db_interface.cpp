#include "db/db_interface.h"

#include "messageProtocol.h"

#include <string.h>
#include <iostream>

using namespace std;
//class Database {
//  private:
//    registerDatabase(char *dbName);
//  public:
//    connectDatabase(OP_CONNECT data);
//    createDatabase(OP_CREATE base);
//    deleteDatabase(OP_DELETE base);
//    readDatabase(OP_QUERY msg);
//    updateDatabase(OP_UPDATE msg);
//    insertDatabase(OP_INSERT msg);
//}

//return 0 if all ok
//return 1 if an error has occured
//establish its own variable for verified user
int wosDB::Database::connectDatabase(OP_CONNECT data) {
    char *test = "test";
    if (strcmp(data.username, test) == 0 && strcmp(data.password, test)) {
        verified = 1;
        return 0;
    }
    return 1;
};

// struct OP_CREATE_COLLECTION {
//     typeDB type; //just create KV_DB
//     int32_t ZERO; // future use
//     string collectionName;
//     int32_t flags; //encyption, compress, ???. etc
// };
void wosDB::Database::createEmptyCollection(OP_CREATE_COLLECTION msg) {
    std::cout << "Creating Collection" << std::endl;
    string name = msg.collectionName;
    // std::map<std::string, std::vector<Collection>> collections; // Map of database name to list of Collections
    if (collections.find(name) == collections.end()) { // If the collection does not exist
        Collection newCollection(name);
        collections[name].push_back(newCollection);
    } //Else I need to send a error message back
};

void wosDB::Database::listCollection() {
    std::map<std::string, std::vector<Collection>>::iterator itr; // Declare the iterator variable
    for (itr = collections.begin(); itr != collections.end(); ++itr) {
        cout << "\t " << itr->first << "\t";
        std::cout << '\n';
    }
};

wosDB::Collection::Collection(string name) {
    std::cout << "Creating Collection" << std::endl;
    collName = name;
};
