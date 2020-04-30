#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void print(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",i);
    }
    
}
int main(){
    switch (fork()) {
        case -1 :       // Cas d'erreur
            perror("fork");
            exit(1);
        case 0 :        // Processus fils
            print(10);   // On fait l'affichage   
            exit(1);    // On sort de la fonction pour éviter les duplications
        default :
            sleep(1);
            break;
    }
    
    return 0;
}