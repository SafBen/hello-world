#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
    printf("pid après execXX() = %d et argv[0] = %s\n",getpid(),argv[0]);   // Le pid est inchangé après le exec
    return 0;
}