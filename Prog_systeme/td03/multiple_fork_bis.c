#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int P=10;

void print(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",i);
        sleep(1);
    }
    
}
int main(){
    for (int i = 0; i < P; i++)
    {
        switch (fork()) {
        case -1 :       // Cas d'erreur
            perror("fork");
            exit(1);
        case 0 :        // Processus fils
            print(P);   // On fait l'affichage   
            exit(1);    // On sort de la fonction pour éviter les duplications
        default :
            break;
        }
    }
    return 0;
}