#include <stdlib.h>

struct Data { // Une structure de données
 char nom[100];
 int age;
};

int main(){
    printf("%d\n",sizeof(struct Data));
    printf("int = %d\nchar = %d\n",sizeof(int),sizeof(char));
    int *t = malloc(1);
    t[0]=2;
    printf("%d\n",t);
    char str[5]="abcdefghijkl";
    printf("%s\n",str[6]);
    return 0;
}