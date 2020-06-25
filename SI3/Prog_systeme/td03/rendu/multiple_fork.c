#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int P=10;

int main(int argc, char** argv){ 
    int pid;
    for(int i = 0; i<P; i++){
        switch (pid = fork()){
        case -1:
            perror("fork error\n");
            exit(1);
        case 0:
            for(int j = 0; j<P; j++){
                printf("%d \n",j);
                sleep(1);
                }
            exit(1);
        default:
            break;
        }
    }
    return 0;
}