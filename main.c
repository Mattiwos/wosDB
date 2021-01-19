#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	//char filename[] = "mattiwos";
	//createDatabase(filename);
	mkdir("test", 0700);
	printf("Making folder");
	return 0;
};
