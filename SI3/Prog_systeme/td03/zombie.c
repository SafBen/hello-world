#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    switch (fork()) {
        case -1 :       // Cas d'erreur
            perror("fork");
            exit(1);
        case 0 :        // Processus fils
            for(int j = 0; j<10; j++){
                printf("%d \n",j);
                }   
            exit(1);
        default :
            sleep(5);   // sleep assez long pour voir le zombie
            break;
    }
    return 0;
}