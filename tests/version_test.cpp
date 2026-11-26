#include "wosdb/version.hpp"

#include <gtest/gtest.h>

TEST(Version, ReportsCurrentVersion) { EXPECT_EQ(wosdb::version(), "0.1.0"); }
