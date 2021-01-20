#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include <time.h>
#define festloc "manfest.bin"
#include "structDB.h"
/*
int main(void){

	return 0;
}
*/
int listManfest(){
	FILE *manfest = fopen(festloc,"r");
	struct Database database;
	
	while(fread(&database,sizeof(struct Database),1,manfest) )
		printf("DBname: %s, ID: %d ||\n",database.name,database.id);
	fclose(manfest);
	return 0;
};

int dbExistsCheck(char* name){
	FILE *manfest = fopen(festloc,"r");
	struct Database database;
	
	while(fread(&database,sizeof(struct Database),1,manfest) )
		if (strcmp(database.name,name) == 0){
			printf("Database already exists\n");
			perror("Database already exists \n");
			exit(EXIT_FAILURE); 
		}
			
	fclose(manfest);
	return 0;

};


int createDatabase(char* name){
	dbExistsCheck(name);
	printf("Creating Database\n");
	struct Database database;
	mkdir(name, 0777);	
	FILE *manfest = fopen(festloc,"ab");
	strcpy(database.name ,name);
	srand((unsigned)time(NULL));
	database.id = rand();
	fwrite(&database, sizeof(struct Database),1,manfest);
	fclose(manfest);
	listManfest();
	return 0;
};
