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
            for (int i = 0; i < 3; i++){
                // On affiche le pid du père
                printf("père pid = %d\n",getppid());   
                sleep(1);
                }
                exit(1);
        default :
            break;
    }
    
    return 0;
}