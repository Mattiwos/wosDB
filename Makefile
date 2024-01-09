CXX := g++
CXXFLAGS := -std=c++11 -Wall
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin
TEST_DIR := test

# Directories
SERVER_SRC_DIR := $(SRC_DIR)/server

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/server/*.cpp $(SRC_DIR)/client/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TARGET := $(BIN_DIR)/main

INCLUDES := -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/server -I$(INCLUDE_DIR)/client -I$(INCLUDE_DIR)/db

# Test source files
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))
TEST_TARGET := $(BIN_DIR)/test_main

# Server
SERVER_SRCS := $(wildcard $(SERVER_SRC_DIR)/*.cpp)
SERVER_OBJS := $(patsubst $(SERVER_SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SERVER_SRCS))
SERVER_TARGET := $(BIN_DIR)/server

.PHONY: all test clean server format

# Main Application
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c -o $@ $<

# Testing
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c -o $@ $<

# Server
server: $(SERVER_TARGET)

$(SERVER_TARGET): $(SERVER_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Cleaning
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Dependency inclusion
-include $(DEPS)

# Code formatting
format:
	find $(SRC_DIR) $(INCLUDE_DIR) -name '*.cpp' -o -name '*.h' | xargs clang-format -i -style=file
