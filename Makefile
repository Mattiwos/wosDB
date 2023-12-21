CXX = g++ 
DEPS = include
CXXFLAGS = -Wall -std=c++11 

FILE = /home/wos/Repos/github.com/mattiwos/wosDB/.clang-format
OBJECTS := wosDB.o utility.o serverDB.o handleRequests.o db_interface.o

TARGET = wosDB 

client: clientDB
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ wosDB.o utility.o serverDB.o handleRequests.o db_interface.o

wosDB.o: wosDB.cpp
	$(CXX) -g $(CXXFLAGS) -c wosDB.cpp

utility.o: $(DEPS)/utility.cpp  $(DEPS)/utility.h
	$(CXX) -g $(CXXFLAGS) -c  $(DEPS)/utility.cpp

serverDB.o: $(DEPS)/serverDB.cpp $(DEPS)/serverDB.h
	$(CXX) -g $(CXXFLAGS) -c $(DEPS)/serverDB.cpp

handleRequests.o: $(DEPS)/handleRequests.cpp $(DEPS)/handleRequests.h
	$(CXX) -g $(CXXFLAGS) -c $(DEPS)/handleRequests.cpp

db_interface.o: $(DEPS)/db_interface.cpp $(DEPS)/db_interface.h
	$(CXX) -g $(CXXFLAGS) -c $(DEPS)/db_interface.cpp

clean:
	rm -f *.o 
	rm wosDB 

scan-build: clean
	scan-build make

format:
	clang-format -i -style=FILE *.c *.cpp include/*.h include/*.cpp
