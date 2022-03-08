#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#ifndef CLASSIC_DB
#define CLASSIC_DB
#define festloc "manfest.bin"
#include "structDB.h"
#endif

#include <time.h>
int dbExistsCheck(char* name){
	FILE *manfest = fopen(festloc,"r");
  if (!manfest){//checks if manfest exists
    perror("Manfest file does not exist \n");
    exit(EXIT_FAILURE);
  }
	struct Database database;
	while(fread(&database,sizeof(struct Database),1,manfest) == 1)
		if (strcmp(database.name,name) == 0){
			perror("Database already exists \n");
			exit(EXIT_FAILURE); 
		}
	fclose(manfest);

	return EXIT_SUCCESS;
};

int registerDatabase(char* dbName){
  printf("Registering Database to Main Manfest \n");
	FILE *manfest = fopen(festloc,"ab");//Main Manfest Location (writ in b)
  if (!manfest){//checks if manfest exists
    perror("Manfest file does not exist \n");
    exit(EXIT_FAILURE);
  }
	struct Database database;
	strcpy(database.name, dbName);//sets database name
	srand((unsigned)time(NULL));//seed
	database.id = rand();//random id number
	fwrite(&database, sizeof(struct Database),1,manfest); //database struct

	fclose(manfest);

	return EXIT_SUCCESS;
}


int createDatabase(char* name){
  printf("Checking if %s exists\n", name);
	dbExistsCheck(name);
  
	printf("Creating Database\n");
	mkdir(name, 0777);//creates folder in Storage (default)	
  
  registerDatabase(name);//Registers Database to manfest

	return 0;
};
