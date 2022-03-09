#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#ifndef CLASSIC_DB
#define CLASSIC_DB
#define festloc "manfest.bin"
#include "structDB.h"
#endif

#ifndef STATUS_H
#define STATUS_H
#include "statusDB.h"
#endif

#include <dirent.h>
#include <fcntl.h>
#include <ftw.h> //used to delete directory
#include <unistd.h>

int unregisterDatabase(char *dbName) {
    printf("Registering Database to Main Manfest \n");

    //Read old then write it to new except new data
    FILE *manfest = fopen(festloc, "rb"); //Main Manfest Location (writ in b)
    if (!manfest) { //checks if manfest exists
        perror("Manfest file does not exist \n");
        exit(EXIT_FAILURE);
    }
    FILE *tmp = fopen("tmp.bin", "ab");

    struct Database database;
    while (fread(&database, sizeof(struct Database), 1, manfest) == 1) {
        if (strcmp(database.name, dbName) != 0)
            fwrite(&database, sizeof(struct Database), 1, tmp);
    }
    fclose(tmp);
    fclose(manfest);
    //Deletes old manfest and rename tmp to previous
    remove(festloc);
    rename("tmp.bin", festloc);

    return EXIT_SUCCESS;
}

//Stack overflow solution to removing filled directory
//Will implement my on in the future
int remove_directory(const char *path) {
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d) {
        struct dirent *p;

        r = 0;
        while (!r && (p = readdir(d))) {
            int r2 = -1;
            char *buf;
            size_t len;

            /* Skip the names "." and ".." as we don't want to recurse on them. */
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2;
            buf = malloc(len);

            if (buf) {
                struct stat statbuf;

                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode))
                        r2 = remove_directory(buf);
                    else
                        r2 = unlink(buf);
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }

    if (!r)
        r = rmdir(path);

    return r;
}
//in the future add destroyDatabase
//which deletes database and rewrites over it
//to remove all traces
int deleteDatabase(char *name) {
    printf("Checking if %s exists\n", name);

    dbExistsCheck(name);

    printf("Deleting Database\n");
    remove_directory(name); //deletes database

    unregisterDatabase(name); //Registers Database to manfest

    return EXIT_SUCCESS;
}
