#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(){
    int fd = open("foo", O_CREAT|O_TRUNC|O_WRONLY|S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    dup2(fd, 1);
    close(fd);
    execlp("ls", "ls", "-l", 0);
    /*switch(fork()){
        case -1:
            fprintf(stderr, "fork !");
            break;
        case 0:
            execlp("ls", "ls", "-l", 0);
            exit(EXIT_SUCCESS);
        default:
            wait(NULL);
            break;
    }*/
    return 0;
}