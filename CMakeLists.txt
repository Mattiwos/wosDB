# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(wosDB)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# specify the source directory and the final executable
set(SOURCE_DIR "src")
set(INCLUDE_DIR "include")
set(TEST_DIR "wosDB-tests")
set(SERVER_SRC_DIR "${SOURCE_DIR}/server")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Find the Boost libraries
find_package(Boost REQUIRED COMPONENTS serialization)

# add the executable
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/server/*.cpp" "${SOURCE_DIR}/client/*.cpp")
add_executable(wosDB ${SOURCES})

# include directories
target_include_directories(wosDB PRIVATE ${INCLUDE_DIR} ${INCLUDE_DIR}/server ${INCLUDE_DIR}/client ${INCLUDE_DIR}/db ${Boost_INCLUDE_DIRS})

# Link against the Boost libraries
target_link_libraries(wosDB ${Boost_LIBRARIES} Boost::serialization)

# Find the Google Test libraries
find_package(GTest REQUIRED)

# add the test subdirectory
# Get all the source files

# Add the test executable
file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp" "${SOURCE_DIR}/server/*.cpp" "${SOURCE_DIR}/client/*.cpp" "${SOURCE_DIR}/db/*.cpp")
add_executable(wosDB-tests ${TEST_SOURCES})
target_include_directories(wosDB-tests PRIVATE ${INCLUDE_DIR} ${INCLUDE_DIR}/server ${INCLUDE_DIR}/client ${INCLUDE_DIR}/db)
# Link against the Google Test libraries
target_link_libraries(wosDB-tests GTest::GTest GTest::Main pthread ${Boost_LIBRARIES} Boost::serialization)

# enable testing
enable_testing()