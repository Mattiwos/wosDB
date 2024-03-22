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




void wosDB::DatabaseFactory::listDatabases() {
    for (auto itr = databases.begin(); itr != databases.end(); ++itr) {
        std::string name = itr->first;
        std::cout << "Database name: " << name << '\n';
    }
    // for (const auto&[name, database]: databases){ //range based for loop
    //     std::cout << "Database name: " << name << '\n';
    // }
};