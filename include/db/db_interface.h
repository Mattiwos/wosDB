#ifndef DB_INTERFACE
#define DB_INTERFACE

#include "messageProtocol.h"
#include <map>
#include <vector>
#include <string>

namespace wosDB {
class Collection {
    //eachCollects has a list of data
    private:
            std::string collName;
            std::map<std::string, std::string> entries;
        // Collection properties and methods...
        public:
            Collection(std::string name); // Renamed the member function to a valid constructor name
            void insertData(std::string key, std::string value);
            void deleteData(std::string key);
            void updateData(std::string key, std::string value);
            std::string readData(std::string key);
        //void addAuth(OP_ADD_AUTH msg);
        //void removeAuth(OP_REMOVE_AUTH msg);
        //void verifyAuth(OP_VERIFY_AUTH msg);
        //void readDatabase(OP_QUERY msg);
        //void updateDatabase(OP_UPDATE msg);
        //void insertDatabase(OP_INSERT msg);
};

class Database {

private:
    void registerDatabase(char *dbName);
    int verified = 1;
    std::map<std::string, std::vector<Collection>> collections; // Map of database name to list of Collections

    //list of collections
    

public:
    int connectDatabase(OP_CONNECT data);
    void createEmptyCollection(OP_CREATE_COLLECTION msg);
    void listCollection();

    //creates a colleciton and adds it with a name
    void deleteCollection(OP_DELETE_COLLECTION msg);
    //deletes the colleciton 
    //void readCollection(OP_READ_COLLECTION msg);
    void updateCollection(OP_UPDATE_COLLECTION msg);
    void insertCollection(OP_INSERT_COLLECTION msg);
    //identify which location to insert the data
    //then add the data to the collection by passing in key and value
    void deleteCollection(OP_INSERT_COLLECTION msg);
    //void addAuth(OP_ADD_AUTH msg);
    //void removeAuth(OP_REMOVE_AUTH msg);
    //void verifyAuth(OP_VERIFY_AUTH msg);
    //void readDatabase(OP_QUERY msg);
    //void updateDatabase(OP_UPDATE msg);
    //void insertDatabase(OP_INSERT msg);
};




class User {
    // User properties and methods...
};

class Permission {
    // Permission properties and methods...
};

class DatabaseLibrary { //main class for the database
//interface for the database
private:
    std::map<std::string, Database> databases; // Map of database name to Database object
    std::map<std::string, std::vector<User>> users; // Map of database name to list of Users
    std::map<std::string, std::vector<Permission>> permissions; // Map of database name to list of Permissions

public:
    void createDatabase(OP_CREATE base); //create a database first
    //this will add 
    void deleteDatabase(OP_DELETE base);
    // Methods to manipulate the databases, collections, users, and permissions...
    //Create database sets the defaults for the database
        //return database
    //dete database
        //removes the database from the map and performs clean up

};
}// namespace wosDB


#endif
