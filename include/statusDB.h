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
  printf("Finished printing list \n");

	return EXIT_SUCCESS;
};


