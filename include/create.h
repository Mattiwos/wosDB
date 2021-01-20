#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include <time.h>
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
/*
int main(void){

	return 0;
}
*/
int dbCheck(){
	FILE *manfest = fopen("manfest.bin","r");
	struct Database database;
	
	while(fread(&database,sizeof(struct Database),1,manfest) )
		printf("DBname: %s, ID: %d ||\n",database.name,database.id);
	fclose(manfest);
	return 0;
};

int createDatabase(char* name){
	printf("Creating Database\n");
	mkdir(name, 0777);	

	FILE *manfest = fopen("manfest.bin","ab");
	struct Database database;
	strcpy(database.name ,name);
	srand((unsigned)time(NULL));
	database.id = rand();
	fwrite(&database, sizeof(struct Database),1,manfest);
	fclose(manfest);
	dbCheck();
	return 0;
};
