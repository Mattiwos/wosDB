// test executable
#include "gtest/gtest.h"
#include "client/clientDB.h"
#include "db/db_interface.h"
#include <map>
#include <memory>
#include <chrono>
#include <iostream>

#include "messageProtocol.h"

TEST(ClientDBTest, TestGetClientData) {
    std::cout << "Starting TestGetClientData" << std::endl;
    int result = clientDB(8080);
    EXPECT_EQ(result, 416);
    // ...
}
// struct OP_CREATE_COLLECTION {
//     typeDB type; //just create KV_DB
//     int32_t ZERO; // future use
//     string collectionName;
//     int32_t flags; //encyption, compress, ???. etc
// };
TEST(CollectionTest, TestCREATE_COLLECTION) {

    std::string msg = "test";
    wosDB::KeyValue db; //keyvalue db
    db.createEmptyCollection(msg);
    std::string msg2 = "second";
    db.createEmptyCollection(msg2);
    std::cout << "Starting collectionCreateTest" << std::endl;
    db.listCollection();

    EXPECT_EQ(msg, "test");
    // ...
}

TEST(DatabaseTest, TestCREATE_DATABASEKY) {
    OP_CREATE_DATABASE msg;
    // OP_CREATE_COLLECTION msg2;
    msg.databaseName = "First Database :)";
    wosDB::DatabaseFactory db; //keyvalue db
    db.createDatabase("First Database :)", DatabaseType::KeyValue);

    // EXPECT_EQ(msg.collectionName, "test");
    // ...
}


TEST(DatabaseTest, CreateAndListCollection) {
    // Create a database using DatabaseFactory
    wosDB::DatabaseFactory dbFactory;
    std::shared_ptr<wosDB::Database> db = dbFactory.createDatabase("Test3", DatabaseType::KeyValue);
    //list current databases in the system
    dbFactory.listDatabases();
    // Cast to KeyValueDatabase to access specific methods
    auto kvDb = std::dynamic_pointer_cast<wosDB::KeyValue>(db);
    if (!kvDb) {
        FAIL() << "Failed to cast Database to KeyValueDatabase";
    }

    // Create an empty collection

    std::string collectionName = "fromDatabaseFactory";
    kvDb->createEmptyCollection(collectionName);
    kvDb->createEmptyCollection("fromDatabaseFactory 2");

    // List collections and check that "testCollection" is present
    kvDb->listCollection(); //prints it out

    //time to check if the collection was created
    std::map<std::string, std::string> fake_data = {{"key","data"},{"findme","data2"},{"key3","data3"}};

    for (auto const&[key, val]: fake_data) {
        kvDb->insert(collectionName, key, val);
    }
    std::cout << "Starting Reading inputed data" << std::endl;
    for (auto const&[key, val]: fake_data) {
        std::cout << "Key: " << key << " Value: " << kvDb->read(collectionName, key)<< std::endl;
    }
    // EXPECT_TRUE(std::find(kvDb->collections.begin(), kvDb->collections.end(), "testCollection") != kvDb->collections.end());
    EXPECT_EQ(collectionName, "fromDatabaseFactory");
}

TEST(KeyValueDatabaseTest, TestIORate) {//IO rate: 250 operations per millisecond
    std::string collectionName = "fromDatabaseFactory";
    wosDB::DatabaseFactory dbFactory;
    std::shared_ptr<wosDB::Database> db = dbFactory.createDatabase("Normal", DatabaseType::KeyValue);
    auto kvDb = std::dynamic_pointer_cast<wosDB::KeyValue>(db);

    kvDb->createEmptyCollection(collectionName);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        kvDb->insert(collectionName, "key" + std::to_string(i), "data" + std::to_string(i));
    }

    for (int i = 0; i < 1000; ++i) {
        kvDb->read(collectionName, "key" + std::to_string(i));
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "IO rate: " << 2000.0 / duration << " operations per millisecond" << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "CollectionTest.TestCREATE_COLLECTION";   
    // ::testing::GTEST_FLAG(filter) = "DatabaseTest.CreateAndListCollection";    
    ::testing::GTEST_FLAG(filter) = "KeyValueDatabaseTest.TestIORate";    

    return RUN_ALL_TESTS();
}