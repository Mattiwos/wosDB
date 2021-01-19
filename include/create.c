#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#endif
struct Database
{
	char name[69];
  int space;
	int id;
	char location[];
};
struct Table{
	char name[69];
	int space;
	int id;
	char location[];
};
struct Record{
	char name[69];
	int space;
	int id;
	char location[];
};
struct Field{
	char name[69];
	int space;
	int id;
	char data[];
};
char* root = "storage/";
int createDatabase(char* name){
	printf("creating database");
	system(strcat("mkdir",name));
	FILE *manfest = fopen("manfest.bin","wb");
	struct Database database;
	strcpy(database.name ,name);
	fwrite(&database, sizeof(struct Database),1,manfest);
	fclose(manfest);
	return 0;
};
