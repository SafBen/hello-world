#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fds[2],nbr;
    char lu[4];
    char seq2[]="abcdefghijklmnopqrstuvwxyz";
    char seq1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    pipe(fds);
    for (int i = 0; i < 2; i++)
    {
        switch (fork() )
        {
        case -1:
            printf("erreur fork f1");
            exit(-1);
            break;
        case 0:
        if (i==0)
        {
            close(fds[0]);
            for (int j = 0; j < 26; j+=2)
            {
                write(fds[1], &seq1[j], 2);
                sleep(1);
            }
            close(fds[1]);
        }
        else
        {
            close(fds[0]);
            for (int k = 0; k < 26; k+=2)
            {
                write(fds[1], &seq2[k], 2);
                sleep(2);
            }
            close(fds[1]);
        }
        default:
        break;
        }
    }
    close(fds[1]);
    while ((nbr=read(fds[0],lu,3))){
        write(1,lu,nbr);
    }
    close(fds[0]);
    printf("\n");
    return 0;
}