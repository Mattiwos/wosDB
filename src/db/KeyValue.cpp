#include "db/db_interface.h"

#include "messageProtocol.h"

#include <iostream>
#include <map>
#include <string.h>
#include <vector>

// class KeyValue : public Database {
// private: //store data in a folder storage under class name
//     std::map<std::string, Collection> collections;

//     friend class boost::serialization::access;

//     template <class Archive>
//     void serialize(Archive &ar, const unsigned int version) {
//         // ar & boost::serialization::base_object<Database>(*this);
//         ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Database);
//         ar & collections;
//     }

// public:
//     void createEmptyCollection(std::string name);
//     void listCollection();
//     void insert(const std::string &collName, const std::string &key, const std::string &value) override {};
//     std::string read(const std::string &collName, const std::string &key){};
//     void update(const std::string &collName, const std::string &key, const std::string &value) override {};
//     void remove(const std::string &collName, const std::string &key) override {};
// };


void wosDB::KeyValue::listCollection() {
    // std::map<std::string, std::vector<Collection>>::iterator itr; // Declare the iterator variable
    for (auto itr = collections.begin(); itr != collections.end(); ++itr) {
        std::string name = itr->first;
        std::cout << "Collection name: " << name << '\n';
    }
};
void wosDB::KeyValue::createEmptyCollection(std::string name) {
    // std::cout << "Creating Collection" << std::endl;

    // std::map<std::string, std::vector<Collection>> collections; // Map of database name to list of Collections
    if (collections.find(name) == collections.end()) { // If the collection does not exist
        Collection newCollection(name);
        // collections[name].push_back(newCollection);
        collections.insert(make_pair(name, newCollection));
    } //Else I need to send a error message back
};
void wosDB::KeyValue::insert(const std::string &collName, const std::string &key, const std::string &value) {
    if (collections.find(collName) != collections.end()) {
        collections[collName].insertData(key, value);
    } else {
        std::cout << "Collection does not exist" << std::endl;
    }
};
std::string wosDB::KeyValue::read(const std::string &collName, const std::string &key) {
    if (collections.find(collName) != collections.end()) {
        return collections[collName].readData(key);
    } else {
        std::cout << "Collection does not exist" << std::endl;
    }
};
void wosDB::KeyValue::update(const std::string &collName, const std::string &key, const std::string &value) {
    if (collections.find(collName) != collections.end()) {
        collections[collName].updateData(key, value);
    } else {
        std::cout << "Collection does not exist" << std::endl;
    }
};
void wosDB::KeyValue::remove(const std::string &collName, const std::string &key) {
    if (collections.find(collName) != collections.end()) {
        collections[collName].deleteData(key);
    } else {
        std::cout << "Collection does not exist" << std::endl;
    }
};
