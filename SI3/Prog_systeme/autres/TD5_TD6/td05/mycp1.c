#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "util.h"
#include <dirent.h>


const int MAX = 200;

void cp(char* filename1, char* filename2){ // cp filename2 filename1
	char buffer[MAX];
	int n;
	int fd1 = open(filename1, O_WRONLY|O_TRUNC|O_CREAT, 0600);
	int fd2 = open(filename2,O_RDONLY|O_EXCL);

	while((n = read(fd2, buffer, MAX)) != 0){
		write(fd1, buffer, n);
	}
	close(fd1);
	close(fd2);
}

void file_to_foler(const char* filename, const char* foldername){
	char dest[MAX];
	char buffer[MAX];
	int n;
	char* slash = "/";
	strcpy(dest, foldername);
	strcat(dest, slash);
	strcat(dest, filename);

	int fd1, fd2;
	fd1 = open(dest, O_WRONLY|O_TRUNC|O_CREAT, 0600);
	fd2 = open(filename,O_RDONLY|O_EXCL);

	while((n = read(fd2, buffer, MAX)) != 0){
		write(fd1, buffer, n);
	}
	close(fd1);
	close(fd2);
}



int main(int argc, char **argv){
	if(argc>3){
		for(int i = 1; i<argc - 1; i++){
			printf("%s\n",argv[argc - 1]);
			file_to_foler(argv[i], argv[argc - 1]);
		}
	}
	else if(argc == 3)cp(argv[2], argv[1]);
	return 0;
}
