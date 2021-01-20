#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include "include/createDB.h"


int main(int argc, char *argv[]){
	char storageloc[] = "storage/";
	strcat(storageloc,argv[1]);
	printf("Location of file %s",storageloc);
	createDatabase(storageloc);
	return 0;
};
