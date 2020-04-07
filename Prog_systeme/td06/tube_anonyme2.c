#include <unistd.h>


void lecture(int fd){
    char buff[10];
    while(read(fd,buff,1)!=0){
        write(1,buff,1);
    }
}

int main(){
    int p[2];
    pipe(p);

    switch (fork())
    {
    case 0:
        close(p[1]);
        lecture(p[0]);
        close(p[0]);
        break;

    default:
        sleep(1);
        close(p[0]);
        write(p[1],"0123456789",sizeof("0123456789"));
        close(p[1]);
        break;
    }

    return 0;
}
