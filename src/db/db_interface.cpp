#include "db/db_interface.h"

#include "messageProtocol.h"

#include <iostream>
#include <map>
#include <string.h>
#include <vector>

BOOST_CLASS_EXPORT(wosDB::Collection)
BOOST_CLASS_EXPORT(wosDB::KeyValue)
BOOST_CLASS_EXPORT(wosDB::Document)
// BOOST_CLASS_EXPORT(wosDB::DatabaseFactory)


void wosDB::KeyValue::listCollection() {
    // std::map<std::string, std::vector<Collection>>::iterator itr; // Declare the iterator variable
    for (auto itr = collections.begin(); itr != collections.end(); ++itr) {
        std::string name = itr->first;
        std::cout << "Collection name: " << name << '\n';
    }
};

wosDB::Collection::Collection(std::string name) {
    std::cout << "Creating Collection" << std::endl;
    collName = name;
};
void wosDB::Collection::insertData(string key, string value) {
    entries[key] = value;
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

void wosDB::DatabaseFactory::listDatabases() {
    for (auto itr = databases.begin(); itr != databases.end(); ++itr) {
        std::string name = itr->first;
        std::cout << "Database name: " << name << '\n';
    }
    // for (const auto&[name, database]: databases){ //range based for loop
    //     std::cout << "Database name: " << name << '\n';
    // }
};