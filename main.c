#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include "include/createDB.h"
#include <unistd.h> //used for gitop()

//Vars
#define OPTIONS "c:"
#define StorageLocation "Storage/"

char *conStr(char *s, char *t){
  char *u = (char*)malloc(strlen(s)+strlen(t)+1);
  strcat(u, s);
  strcat(u, t);
  return u;

}

int main(int argc, char *argv[]){
  //Var
	char storageLoc[] = StorageLocation;
  //Argument Parser
  int opt;
  while( (opt = getopt(argc,argv, OPTIONS)) != -1){
    switch(opt) {
      case 'c':
        createDatabase(conStr(storageLoc, optarg));
        printf("Finished creating Database at %s \n",
        conStr(storageLoc, optarg));
        break;
      default:
        break;
     }
    }
	return 0;
};
