#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


void lecture(int fd){
    char buff[10];
    char c;
    while(read(fd,buff,1)!=0){
        write(1,buff,10);
    }
}

int main(){
int p[2];
pipe(p);
char buff[100] = "0123456789";

write(p[1],buff,100);
close(p[1]);

lecture(p[0]);
close(p[0]);


return 0;
}