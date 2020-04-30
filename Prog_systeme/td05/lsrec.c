#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

void lsrec(char *path){
    struct dirent *dentry;
    struct stat sbuf;
    DIR *dirp= opendir(path);
    if (dirp== NULL) {
        perror("Répertoire inaccessible\n");
        exit(EXIT_FAILURE);
    }

    printf("%s:\n",path);
    // Premier passage
    while((dentry = readdir(dirp)) != NULL) {
        if (strcmp(dentry->d_name,"..") && strcmp(dentry->d_name,"."))
        {
            printf("%s \n", dentry-> d_name);
        }
    }

    rewinddir(dirp);
    printf("\n");
    // Deuxième passage
    while((dentry = readdir(dirp)) != NULL) {
        if (strcmp(dentry->d_name,"..") && strcmp(dentry->d_name,"."))
        {
            char new_path[1000];
            sprintf(new_path,"%s/%s",path,dentry->d_name);      // on construit un nouveau chemin
            if (stat(new_path, &sbuf)>=0){
                int m = sbuf.st_mode;
                if (S_ISDIR(m)){
                    lsrec(new_path);
                }
            }
        } 
    }
    
    closedir(dirp);  
}

int main(int argc, char **argv){
    if (argc==1){
        lsrec(".");
    }
    else{
        for (int i = 1; i < argc; i++){
            lsrec(argv[i]);
        }  
    }

    return EXIT_SUCCESS;
}