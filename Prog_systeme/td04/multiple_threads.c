#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>


#include "timer.h"

#define NTHREADS 100


void wait_threads(int,pthread_t[]); // Définition du prototype de fonction pour l'utiliser

void f(){
    pthread_exit((void *) 0);
}

long create_threads(int n) {
	struct timespec vartime = timer_start(); /* Démarrage de la mesure temporelle */
    /* Création de n threads s'exécutant en parallèle */
	pthread_t tab_th[n];

    for (int i = 0; i < n; i++) {
        pthread_t th;
        pthread_create(&th, NULL,(void *) f,NULL);
		tab_th[i]=th;
	}
	/* On mesure le temps écoulé pour la création des n threads */
	long time = timer_end(vartime);
	
	/* On attend la fin des threads créés par mesure sociale et pour éviter un impact sur les prochaine mesures */
	wait_threads(n,tab_th);

	return time; /* Retourne le temps écoulé pour réaliser la création des n threads */
}

void wait_threads(int n,pthread_t th[]) {
    /* Mesure de salubrité sociale, le père attend la fin de tous ses fils */
    for (int i = 0; i < n; i++) 
		pthread_join(th[i], NULL);
}

int main(int argc, char *argv[]) {
	int n = NTHREADS;

    for (int i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			n = atoi(argv[i]);
		}
	}
	
	long time_threads = create_threads(n);
	
	printf("Time taken for creating %d threads (nanoseconds): %ld\n", n, time_threads);
	printf("Time taken for creating %d threads (milliseconds): %ld\n", n, time_threads / NANO_TO_MILLI);

    /* On flushe la sortie standard */
    fflush(stdout);

    /* Fin du père */
    exit(0);
}

