#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void print(int n){
    for (int i = 0; i < n; i++)
    {
        // On affiche le pid du père
        printf("père pid = %d\n",getppid());
        sleep(1);
    }
    
}
int main(){
    switch (fork()) {
        case -1 :       // Cas d'erreur
            perror("fork");
            exit(1);
        case 0 :        // Processus fils
            print(3);   // On fait l'affichage
            exit(1);    // On sort de la fonction pour éviter les duplications
        default :
            break;
    }
    
    return 0;
}

/*

OUTPUT:

père pid = 17938
père pid = 1
père pid = 1

*/
