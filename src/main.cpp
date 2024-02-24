#include "client/clientDB.h"
#include "server/serverDB.h"

#include <cstring> //to use strlen
#include <iostream> //to print to console
#include <stdexcept>
#include <string> //check string is empty
#include <unistd.h> //for getopt()
//#include "utility.h"
// Vars
#define OPTIONS "slhc:"
#define PORT    8081

using namespace std;

void startServer() {
    //start working on serverDB class
    serverDB wosServer;
    wosServer.startServer(PORT); //input port number
    wosServer.listenServer(1); //number of threads
    //startServer using serverDB function

    return;
}
void listAllDatabases() { //lists all databases on server
    return;
}

int main(int argc, char *argv[]) {

    cout << "Begin parsing" << endl;
    //Argument Parser
    int option;
    while ((option = getopt(argc, argv, OPTIONS)) != -1) {
        switch (option) {
        case 's': startServer(); break;
        case 'l': listAllDatabases(); break;
        case 'c': clientDB(stoi(optarg)); break;
        case 'h':
            cout << "Usage: ./wosDB -[flags]" << endl;
            cout << "Flags:" << endl;
            cout << "-s: Starts the database Server" << endl;
            cout << "-l: Lists all dataBases on server" << endl;
            cout << "-h: Prints Instruction on using wosDB" << endl;
            break;
        default: break;
        }
    }

    return EXIT_SUCCESS;
}
