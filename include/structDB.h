
typedef enum typeDatabases {
  KV_DB, DO_DN, HYBRID_DO
} typeDB;

struct Database {
    char name[69];//Database name
    int space;//Amount of Space database uses
    int id;//Random ID
    typeDB type;
    char location[];
};
struct Table {
    char name[69];
    int space;
    int id;
    char location[];
};
struct Record {
    char name[69];
    int space;
    int id;
    char location[];
};
struct Field {
    char name[69];
    int space;
    int id;
    char data[];
};
