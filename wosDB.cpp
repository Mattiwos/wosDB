#include <iostream> //to print to console
#include <stdexcept>
#include <string> //check string is empty
#include <cstring>//to use strlen
#include <unistd.h> //for getopt()
#include "include/serverDB.h"
//#include "utility.h"
// Vars
#define OPTIONS         "slh"

using namespace std;

void startServer(){
    //start working on serverDB class
    serverDB wosServer;
    wosServer.startServer();
    //startServer using serverDB function

    return;
}
void listAllDatabases(){ //lists all databases on server 
    return;
}

int main(int argc, char* argv[]){

    cout << "Begin parsing" <<endl;
    //Argument Parser
    int opt;
    while ((opt = getopt(argc,argv, OPTIONS)) != -1) {
        switch (opt) {
            case 's':
                startServer();
                break;
            case 'l':
                listAllDatabases();
                break;
            case 'h':
                cout << "Usage: ./wosDB -[flags]" << endl;\
                cout << "Flags:" << endl;
                cout << "-s: Starts the database Server" << endl;
                cout << "-l: Lists all dataBases on server" << endl;
                cout << "-h: Prints Instruction on using wosDB" << endl;
                break;
            default:
                break;
        }
    }

    return EXIT_SUCCESS;

}