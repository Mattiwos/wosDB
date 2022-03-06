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
  if (!manfest){//checks if manfest exists
    perror("Manfest file does not exist \n");
    exit(EXIT_FAILURE);
  }
	struct Database database;
	
	while(fread(&database,sizeof(struct Database),1,manfest) == 1 )
		printf("DBname: %s || ID: %d\n",database.name,database.id);

	fclose(manfest);
  printf("finished printing list");
	return 0;
};

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
	return 0;

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
  return 0;
}


int createDatabase(char* name){
  printf("Checking if %s exists\n", name);
	//dbExistsCheck(name);
  
	printf("Creating Database\n");
	//mkdir(name, 0777);//creates folder in Storage (default)	
  
  //registerDatabase(name);//Registers Database to manfest

	//listManfest(); //lists existing values in DB
	return 0;
};
