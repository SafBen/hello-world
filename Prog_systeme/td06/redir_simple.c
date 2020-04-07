#include <unistd.h>
#include <fcntl.h>

int main(void){
    int fd = open("foo",O_WRONLY|O_CREAT|O_TRUNC);
    dup2(fd, 1);
    close(fd);
    execlp("ls", "ls", "-l",NULL);  // "">"", "foo", NULL);
    return 0;
}