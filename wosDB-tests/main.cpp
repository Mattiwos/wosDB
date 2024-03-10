// test executable
#include "gtest/gtest.h"
#include "client/clientDB.h"

TEST(ClientDBTest, TestGetClientData) {
    std::cout << "Starting TestGetClientData" << std::endl;
    int result = clientDB(8080);
    EXPECT_EQ(result, 416);
    // ...
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}