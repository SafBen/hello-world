#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int count=0;

void on_signal(int sig)
{
    printf("*** signal %d\n", sig);
    sleep(1);
    printf("*** fin handler\n");
    if (sig==SIGINT) count++;
}
int main()
{
    printf("pid = %d\n",getpid());
    struct sigaction sigact;
    sigset_t msk_int, msk_segv;

    sigemptyset(&msk_int);
    sigaddset(&msk_int, SIGINT);
    sigemptyset(&msk_segv);
    sigaddset(&msk_segv, SIGSEGV);
    sigact.sa_handler = on_signal;
    sigact.sa_mask = msk_segv;
    sigaction(SIGSEGV, &sigact, NULL);
    sigact.sa_mask = msk_int;
    sigaction(SIGINT, &sigact, NULL);
    printf("INT et SEGV piégés\n");
    /*
    while (1){
        if (count>=5){
            return 0;
        }
        else{

        }
    }
    */
   sleep(5);

    return 0;
}