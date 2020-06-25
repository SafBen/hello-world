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
}
int main()
{
    for (int i = 0;i<=1;i++){
        switch (fork())
        {
        case 0:
        if (i==1)
        {
            printf("pid = %d\n",getpid());
            struct sigaction sigact;
            sigset_t msk_usr2;

            sigemptyset(&msk_usr2);
            sigaddset(&msk_usr2, SIGUSR2);
            sigact.sa_handler = on_signal;
            sigact.sa_mask = msk_usr2;
            sigaction(SIGUSR2, &sigact, NULL);
        }

        if (i==0)
        {
            printf("pid = %d\n",getpid());
            struct sigaction sigact;
            sigset_t msk_usr1;

            sigemptyset(&msk_usr1);
            sigaddset(&msk_usr1, SIGUSR1);
            sigact.sa_handler = on_signal;
            sigact.sa_mask = msk_usr1;
            sigaction(SIGUSR1, &sigact, NULL);
        }
            break;
        
        default:
        wait(NULL);
            break;
        }
    }
    return 0;
}