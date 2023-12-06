CXX = g++ 
DEPS = include
CXXFLAGS = -Wall -std=c++11 

FILE = /home/wos/Repos/github.com/mattiwos/wosDB/.clang-format
OBJECTS := wosDB.o utility.o serverDB.o

TARGET = wosDB 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ wosDB.o utility.o serverDB.o 

wosDB.o: wosDB.cpp
	$(CXX) -g $(CXXFLAGS) -c wosDB.cpp

utility.o: $(DEPS)/utility.cpp  $(DEPS)/utility.h
	$(CXX) -g $(CXXFLAGS) -c  $(DEPS)/utility.cpp

serverDB.o: $(DEPS)/serverDB.cpp $(DEPS)/serverDB.h
	$(CXX) -g $(CXXFLAGS) -c $(DEPS)/serverDB.cpp



clean:
	rm -f *.o 
	rm wosDB 

scan-build: clean
	scan-build make

format:
	clang-format -i -style=FILE *.c *.cpp include/*.h
