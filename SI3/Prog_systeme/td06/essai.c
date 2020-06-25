#include <stdio.h>


void print_tab(char **tab){
    int i=0;
    while (tab[i]!=NULL){
        printf("%s  ",tab[i]);
        i++;
    }
    printf("\n");
}

void inverser(int argc, char **argv){
    char *file = argv[2];
    for (int i = 3; i < argc; i++)
    {
        argv[i-2]=argv[i];
    }
    argv[argc-2]="<";
    argv[argc-1]=file;
}

void redirection(int argc, char** argv, char* rw){
    inverser(argc,argv);
    argv=argv+1;
    print_tab(argv);
    execvp(argv[0],argv);
}

int main(int argc, char **argv){
    char **t=argv;
    print_tab(argv);
    t=t+3;
    inverser(argc,argv);
    print_tab(argv);
    return 0;
}