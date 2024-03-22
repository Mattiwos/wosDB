#include "db/db_interface.h"

#include "messageProtocol.h"

#include <iostream>
#include <map>
#include <string.h>
#include <vector>

// class Collection {
// private: //stored under class name folder in storage folder
//     std::string collName;
//     std::map<std::string, std::string> entries;

// public:
//     template <class Archive> void serialize(Archive &ar, const unsigned int version) {
//         ar & collName;
//         ar & entries;
//     }
//     Collection() {
//             // Initialize your object here
//         }
//     Collection(std::string name);
//     void insertData(std::string key, std::string value);
//     void deleteData(std::string key);
//     void updateData(std::string key, std::string value);
//     std::string readData(std::string key);
// };


wosDB::Collection::Collection(std::string name) {
    std::cout << "Creating Collection" << std::endl;
    collName = name;
};
void wosDB::Collection::insertData(string key, string value) {
    entries[key] = value;
};
void wosDB::Collection::deleteData(string key) {
    entries.erase(key);// = value;
};
void wosDB::Collection::updateData(string key, string value) {
    entries[key] = value;
};
std::string wosDB::Collection::readData(std::string key){
    return entries[key];
};



