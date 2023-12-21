#ifndef DB_INTERFACE
#define DB_INTERFACE



class Database {

  private:
    void registerDatabase(char *dbName);
    int verified = 1;

  public:
    int connectDatabase(OP_CONNECT data);
    void createDatabase(OP_CREATE base);
    void deleteDatabase(OP_DELETE base);
    void readDatabase(OP_QUERY msg);
    void updateDatabase(OP_UPDATE msg);
    void insertDatabase(OP_INSERT msg);



}







#endif
