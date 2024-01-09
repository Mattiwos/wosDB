// Doesnt work

#include <gtest/gtest.h>
#include "client/clientDB.h"  // Adjust the include path based on your project structure
TEST(ClientDBTest, TestGetClientData) {
    // Arrange: Set up any necessary preconditions or variables

    // Act: Call the function you want to test
    int result = clientDB(8080);

    // Assert: Check the result against expectations
    EXPECT_EQ(result, 0);
}

// Add more test cases as needed

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
