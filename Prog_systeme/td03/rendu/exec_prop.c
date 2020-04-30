#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void){
    switch (fork()){
        case -1:
            perror("fork");
            exit(1);
        case 0:
            printf("pid avant execXX() = %d\n",getpid());   // On affiche le pid avant le execXX()
            printf("ceci flushe\n");                        // Avec \n on vide le buffer donc on fait l'affichage
            printf("ceci ne flushe pas");                   // Sans \n on ne vide pas le flushe donc rien n'est affiché             
            execlp("./exec_prop-aux.exe","coucou", NULL);   // Appel du programme exec_prop-aux.exe
            printf("code pas exécuté\n");                   // Après execXX() le code n'est pas exécuté
            exit(1);
        default:            
            break;
        }
}