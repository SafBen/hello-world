/*
 * Exercice 3
 */

#include "exo3.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
JNIEXPORT int JNICALL Java_exo3_fork(JNIEnv *env, jobject obj)
{
    int f=fork();
    switch (f) {
        case -1 :       // Cas d'erreur
            perror("fork");
            exit(1);
        case 0 :        // Processus fils
            printf("fils %d\n",f);   // On fait l'affichage
            return f;   // On sort de la fonction pour éviter les duplications
        default :
            printf("père %d\n",f);
            break;
        }
    return f;
}