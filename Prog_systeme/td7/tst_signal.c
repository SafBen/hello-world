#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int count=0;

void on_signal(int sig)
{
    printf("*** signal %d\n", sig);
    if (sig==SIGINT) count++;
}
int main()
{
    printf("pid = %d\n",getpid());
    void (*ph)(int);
    signal(SIGSEGV, SIG_IGN);
    ph = signal(SIGINT, SIG_IGN);
    printf("INT et SEGV piégés\n");
    /*
    while (1){
        if (count>=5){
            return 0;
        }
        else{
            signal(SIGSEGV, on_signal);
            signal(SIGINT, on_signal);
        }
    }
    */
   //sleep(5);
   if (count>=5){
            return 0;
        }
        else{
            signal(SIGSEGV, on_signal);
            signal(SIGINT, on_signal);
        }
    sleep(5);
    return 0;
}