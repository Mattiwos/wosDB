#ifndef DB_INTERFACE
#define DB_INTERFACE

#include "messageProtocol.h"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <filesystem> // Include this at the top of your file
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

enum DatabaseType { KeyValue, Document };

namespace wosDB {

class Collection {
private: //stored under class name folder in storage folder
    std::string collName;
    std::map<std::string, std::string> entries;

public:
    template <class Archive> void serialize(Archive &ar, const unsigned int version) {
        ar & collName;
        ar & entries;
    }
    Collection() {
            // Initialize your object here
        }
    Collection(std::string name);
    void insertData(std::string key, std::string value);
    void deleteData(std::string key);
    void updateData(std::string key, std::string value);
    std::string readData(std::string key);
};

class Database { //Implement the Database interface methods
public:
    virtual ~Database() {
    }
    virtual void insert(const std::string &collName, const std::string &key, const std::string &value) = 0;
    virtual std::string read(const std::string &collName, const std::string &key) = 0;
    virtual void update(const std::string &collName, const std::string &key, const std::string &value) = 0;
    virtual void remove(const std::string &collName, const std::string &key) = 0;
    template <class Archive>
    void serialize(Archive & /*ar*/, const unsigned int /*version*/) {
        // No data members to serialize
    }
};

class KeyValue : public Database {
private: //store data in a folder storage under class name
    std::map<std::string, Collection> collections;

    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        // ar & boost::serialization::base_object<Database>(*this);
        ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Database);
        ar & collections;
    }

public:
    void createEmptyCollection(std::string name);
    void listCollection();
    void insert(const std::string &collName, const std::string &key, const std::string &value);
    std::string read(const std::string &collName, const std::string &key);
    void update(const std::string &collName, const std::string &key, const std::string &value);
    void remove(const std::string &collName, const std::string &key);
};

class Document : public Database {
    std::map<std::string, std::string> entries;
public:
    void insert(const std::string &collName, const std::string &key, const std::string &value) override {};
    std::string read(const std::string &collName, const std::string &key) override {};
    void update(const std::string &collName, const std::string &key, const std::string &value) override {};
    void remove(const std::string &collName, const std::string &key) override {};
    
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        // Add serialization for any member variables of Document if needed
        // ar & boost::serialization::base_object<Database>(*this);
        ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Database);

        ar & entries;
    }
};

class DatabaseFactory {
private:
    std::map<std::string, std::shared_ptr<Database>> databases;

public:
    DatabaseFactory() {
        loadDatabasesFromFile();
    }

    ~DatabaseFactory() {
        saveDatabasesToFile();
    }
    void listDatabases();

    std::shared_ptr<Database> createDatabase(const std::string &name, DatabaseType type) {
        auto it = databases.find(name);
        if (it != databases.end()) {
            // Database with this name already exists, return it
            return it->second;
        } else {
            // Create a new database, store it in the map, and return it
            std::shared_ptr<Database> db;
            if (type == DatabaseType::KeyValue) {
                db = std::make_shared<KeyValue>(); // Pass in name here
                
            }
            else if (type == DatabaseType::Document) {
                db = std::make_shared<Document>();
            }
            databases[name] = db;
            return db;
        }
    }

private:
    void loadDatabasesFromFile() {
        std::ifstream ifs("databases.bin");
        if (ifs.good()) {
            boost::archive::text_iarchive ia(ifs);
            try {
                ia >> databases;
            } catch (const boost::archive::archive_exception &e) {
                throw std::runtime_error(
                    std::string("Error deserializing databases: ") + std::string(e.what()));
            }
        }
    }

    void saveDatabasesToFile() {
        std::ofstream ofs("databases.bin");
        if (!ofs) {
            throw std::runtime_error(
                std::string("Could not open file for writing: ") + std::strerror(errno));
        }
        boost::archive::text_oarchive oa(ofs);
        try {
            oa << databases;
        } catch (const boost::archive::archive_exception &e) {
            throw std::runtime_error(
                std::string("Error serializing databases: ") + std::string(e.what()));
        }
        if (!ofs.good()) {
            throw std::runtime_error(std::string("Error writing to file: ") + std::strerror(errno));
        }
    }
};


} // namespace wosDB




#endif
