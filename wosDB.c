#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#ifndef STATUS_H
#define STATUS_H
#include "include/statusDB.h"
#endif

#include "include/createDB.h"
#include "include/deleteDB.h"

// Main
#include <unistd.h> //used for gitop()

// Vars
#define OPTIONS         "c:ld:"
#define StorageLocation "Storage/"

char *conStr(char *s, char *t) {
    char *u = (char *) malloc(strlen(s) + strlen(t) + 1);
    strcat(u, s);
    strcat(u, t);
    return u;
}

int main(int argc, char *argv[]) {
    // Var
    char storageLoc[] = StorageLocation;
    // Argument Parser
    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'c': createDatabase(conStr(storageLoc, optarg)); break;
        case 'd': deleteDatabase(conStr(storageLoc, optarg)); break;
        case 'l':
            listManfest(); // lists existing values in DB
            break;
        default: break;
        }
    }

    return EXIT_SUCCESS;
}
