include(FetchContent)

# GoogleTest is a test-only dependency; the engine itself stays dependency-free.
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
    URL_HASH SHA256=65fab701d9829d38cb77c14acdc431d2108bfdbf8979e40eb8ae567edf10b27c
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(wosdb_tests
    version_test.cpp)
target_link_libraries(wosdb_tests PRIVATE wosdb wosdb_warnings GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(wosdb_tests)
