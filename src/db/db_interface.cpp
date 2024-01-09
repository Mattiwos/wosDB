#include "db/db_interface.h"

#include "messageProtocol.h"

#include <string.h>

using namespace std;
//class Database {
//  private:
//    registerDatabase(char *dbName);
//  public:
//    connectDatabase(OP_CONNECT data);
//    createDatabase(OP_CREATE base);
//    deleteDatabase(OP_DELETE base);
//    readDatabase(OP_QUERY msg);
//    updateDatabase(OP_UPDATE msg);
//    insertDatabase(OP_INSERT msg);
//}

//return 0 if all ok
//return 1 if an error has occured
//establish its own variable for verified user
int Database::connectDatabase(OP_CONNECT data) {
    char *test = "test";
    if (strcmp(data.username, test) == 0 && strcmp(data.password, test)) {
        verified = 1;
        return 0;
    }
    return 1;
};
