#include "db_interface.h"


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
int Database :: connectDatase (OP_CONNECT data){
  assert(data);
  const char* test = "test";
  if (strcmp(data.user, test) == 0 && strcmp(data.pass, test)){
    verified = 1;
    return 0;
  }
  return 1;
}




