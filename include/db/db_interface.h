#ifndef DB_INTERFACE
#define DB_INTERFACE

#include "messageProtocol.h"

#include <map>
#include <string>
#include <vector>
#include <memory>

struct DatabaseType {
    enum type { KeyValue, Document };
};

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

class Database { //prototype for the database

private:
    // void registerDatabase(char *dbName);
    // int verified = 1;
    // std::map<std::string, std::vector<Collection>> collections; // Map of database name to list of Collections

    //list of collections

public:
    virtual ~Database() {}
    virtual void insert(const std::string &key, const std::string &value) = 0;
    virtual std::string read(const std::string &key) = 0;
    virtual void update(const std::string &key, const std::string &value) = 0;
    virtual void remove(const std::string &key) = 0;

    // int connectDatabase(OP_CONNECT data);
    // void createEmptyCollection(OP_CREATE_COLLECTION msg);
    // void listCollection();

    // //creates a colleciton and adds it with a name
    // void deleteCollection(OP_DELETE_COLLECTION msg);
    // //deletes the colleciton
    // //void readCollection(OP_READ_COLLECTION msg);
    // void updateCollection(OP_UPDATE_COLLECTION msg);
    // void insertCollection(OP_INSERT_COLLECTION msg);
    // //identify which location to insert the data
    // //then add the data to the collection by passing in key and value
    // void deleteCollection(OP_INSERT_COLLECTION msg);
    // //void addAuth(OP_ADD_AUTH msg);
    // //void removeAuth(OP_REMOVE_AUTH msg);
    // //void verifyAuth(OP_VERIFY_AUTH msg);
    // //void readDatabase(OP_QUERY msg);
    // //void updateDatabase(OP_UPDATE msg);
    // //void insertDatabase(OP_INSERT msg);
};
class KeyValue : public Database {
private:
    std::map<std::string, Collection> collections; // Map of collection name to Collection

public:
    int connectDatabase(OP_CONNECT data);
    void createEmptyCollection(OP_CREATE_COLLECTION msg);
    void listCollection();
    void insert(const std::string& key, const std::string& value) override;
    std::string read(const std::string& key) const override;
    void update(const std::string& key, const std::string& value) override;
    void remove(const std::string& key) override;
};
class Document : public Database { //inherets database
    // Implement the Database interface methods
};

class DatabaseFactory {
private:
    std::map<std::string, std::shared_ptr<Database>> databases;

public:
    std::shared_ptr<Database> createDatabase(const std::string &name, DatabaseType type) {
        auto it = databases.find(name);
        // DatabaseType::type type = DatabaseType::KeyValue;
        if (it != databases.end()) {
            // Database with this name already exists, return it
            return it->second;
        } else {
            // Create a new database, store it in the map, and return it
            std::shared_ptr<Database> db;
            // if (type == DatabaseType::KeyValue) {
            db = std::make_shared<KeyValue>();
            // } else if (type == DatabaseType::Document) {
                // db = std::make_shared<Document>();
            // }
            databases[name] = db;
            return db;
        }
    }
};

} // namespace wosDB

#endif
