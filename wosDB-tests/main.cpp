// test executable
#include "gtest/gtest.h"
#include "client/clientDB.h"
#include "db/db_interface.h"

#include "messageProtocol.h"

// TEST(ClientDBTest, TestGetClientData) {
//     std::cout << "Starting TestGetClientData" << std::endl;
//     int result = clientDB(8080);
//     EXPECT_EQ(result, 416);
//     // ...
// }
// // struct OP_CREATE_COLLECTION {
// //     typeDB type; //just create KV_DB
// //     int32_t ZERO; // future use
// //     string collectionName;
// //     int32_t flags; //encyption, compress, ???. etc
// // };
// TEST(CollectionTest, TestCREATE_COLLECTION) {
//     OP_CREATE_COLLECTION msg;
//     OP_CREATE_COLLECTION msg2;
//     msg.collectionName = "test";
//     wosDB::Database db;
//     db.createEmptyCollection(msg);
//     msg2.collectionName = "second";
//     db.createEmptyCollection(msg2);
//     std::cout << "Starting collectionCreateTest" << std::endl;
//     db.listCollection();

//     EXPECT_EQ(msg.collectionName, "test");
//     // ...
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "CollectionTest.TestCREATE_COLLECTION";    
    return RUN_ALL_TESTS();
}