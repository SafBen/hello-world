#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int main() { 
    switch (fork())
    {
    case 0:
        printf("$ who\n");
        execlp("who","who",NULL);
    default:
        wait(0);
        printf("$ ls -ls\n");
        execlp("ls","ls","-ls",NULL);
    }
}