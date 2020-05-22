#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void lecture(int fd){
    char buff[100];
    int nb_lu;
    while((nb_lu=read(fd,buff,3))){
        write(1,buff,nb_lu);
    }
}

int main(){
    int p[2];
    pipe(p);

    char *alphabet_maj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *alphabet_min = "abcdefghijklmnopqrstuvwxyz";

    for (int i=0;i<2;i++){
        switch (fork())
        {
        case 0:
            close(p[0]);
            if (i==0){
                for (int j=0;j<26;j=j+2){
                    write(p[1],&alphabet_maj[j],2);
                    sleep(1);
                }
            }
            else{
                for (int j=0;j<26;j=j+2){
                    write(p[1],&alphabet_min[j],2);
                    sleep(2);
                }
            }
            close(p[1]);
            exit(0);
            break;
        default:
            break;
        }
    }

    close(p[1]);
    lecture(p[0]);
    close(p[0]);
    printf("\n");

    return 0;
}
