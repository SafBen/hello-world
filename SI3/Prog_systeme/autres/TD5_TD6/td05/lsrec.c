#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "util.h"
#include <sys/stat.h>



void ls(){
    struct dirent *dentry;
    DIR *dirp = opendir(".");
    if (dirp == NULL) {
        perror("Répertoire inaccessible\n");
        exit(EXIT_FAILURE);
    }
    while ((dentry = readdir(dirp)) != NULL) {
        printf("%s\n", dentry->d_name);
    }
    closedir(dirp);
}

void ls_recurssion(char* filename){
    struct dirent *dentry;
    DIR *dirp = opendir(filename);
    if (dirp == NULL) {
        perror("Répertoire inaccessible\n");
        exit(EXIT_FAILURE);
    }
    printf("voici le contenu du fichier %s:\n", filename);
    while ((dentry = readdir(dirp)) != NULL) {
        printf("%s\n", dentry->d_name);        
    }
    rewinddir(dirp);
    printf("----------------fin----------------\n");
    while(dentry = readdir(dirp)){
        if(is_dir(dentry->d_name) && !is_dot_dir(dentry->d_name)){
            ls_recurssion(dentry->d_name);
        }
    }
}


int main(int argc, char **argv){
    if(argc >= 2){
        ls_recurssion(".");
    }
    else ls();
    return 0;
}