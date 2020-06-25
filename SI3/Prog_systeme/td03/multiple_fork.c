#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int P=10;

void print(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",i);
    }
}

int main(){
    int status;
    int pid;
    for (int i = 0; i < P; i++)
    {
        switch (pid=fork()) {
        case -1 :       // Cas d'erreur
            perror("fork");
            exit(1);
        case 0 :        // Processus fils
            print(P);   // On fait l'affichage
            //sleep(1);

            exit(1);    // On sort de la fonction pour éviter les duplications
        default :
            waitpid(pid, &status,0);
            printf("père\n");
            break;
        }
    }
    return 0;
}