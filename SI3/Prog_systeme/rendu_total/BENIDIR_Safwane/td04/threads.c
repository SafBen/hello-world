#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

void f(int n){
    if (n<0){
        pthread_exit((void *) 1);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("pid = %d    poisx = %ld\n",getpid(),pthread_self());
        printf("Linux Thread ID: %ld\n", syscall(SYS_gettid));
        sleep(n);
    }
    pthread_exit((void *) 0);
}

void f1(int n1, int n2){
    printf("%d %d\n",n1,n2);
}

int main(int argc, char **argv){
    long n1=atoi(argv[1]);
    long n2=atoi(argv[2]);

    pthread_t th1;
    pthread_t th2;
    long retour1;
    long retour2;

    printf("pid = %d\n",getpid());

    pthread_create(&th1, NULL,(void *) f,(int *) n1);
    pthread_create(&th2, NULL,(void *) f,(int *) n2);

    pthread_join(th1, (void*) &retour1);
    pthread_join(th2, (void*) &retour2);

    return 0;
}