#include <stdio.h>

void afficher_tab(int n,long tab[n]){
    printf("&t = %d\n",&tab);
    for (int i = 0; i < n; i++) {
        //printf("t[%d] = %ld   *t[%d] = %ld\n",i,tab[i],i,*(tab+i));
    }
    for (int i = 0; i < n; i++) {
        printf("&t[%d] = %d\n",i,&tab[i]);
    }
    printf("&t = %d\n",&tab);
}

void afficher_tableau(int n,int tab[n][n]){
    for (int i = 0; i < n*n; i++) {
        if (!(i%10)) printf("\n");
        printf("%d  ",tab[i/10][i%10]);
    }
}

typedef int tab10[10];

int main() {
    /*
    tab10 tab101={1,2,3};
    printf("%d\n",tab101[1]);

    int tab[10][10];
    int *p=tab[0];
    while (p<=&tab[9][9]) *p++=7;
    //afficher_tableau(10,tab);
    tab[1][0]=9;
    printf("%d\n",(**tab)==8);
    int t[10]={0};
    int *a=3;
    printf("(*t)++%d\nt[*t]%d\n",++*t,t[*t]==a);

    char str[]={'a','b','c'};
    printf("str = %c\nstr = %s\n",str,str);
    char s[]="hello";
    printf("s = %c\ns = %s\n",s,s);
    /*
    int n=10;
    int *p=&n;
    int *q=&p;
    int *r=&p;
    printf("n = %d\n&n = %d\np = %d\n*p = %d\n&p = %d\nq = %d\n*q = %d\n&q = %d\nr = %d\n*r = %d\n&r = %d\n%d",n,&n,p,*p,&p,q,*q,&q,r,*r,&r,sizeof(p));

    char str[]="hello";
    printf("%c  %s",*str,*str);

     */
/*
    long t[] = {10,20,30,40};
    long *p = t+1;
    long *q = t+2;

    printf("q-p = %d\np = %d\n*p = %d\n&p = %d\nq = %d\n*q = %d\n&q = %d\n",q-p,p,*p,&p,q,*q,&q);
    printf("t = %d\n&t = %d\nt[0] = %d\n&t[0] = %d\n&t[1] = %d\nt+1 = %d\n*t = %d\n++*t = %d\n*t = %d\n",t,&t,t[0],&t[0],&t[1],t+1,*t,++*t,*t);
    printf("*p = %d\n",*p);
    printf("++*p = %d\n",++*p);
    printf("*p = %d\n",*p);
    printf("*++p = %d\n",*++p);
    printf("*p = %d\n",*p);
    printf("*p++ = %d\n",*p++);
    printf("*p = %d\n",*p);

    printf("t[1] = %d\n",t[1]);
    printf("(*t)++ = %d\n",(*t)++);
    printf("*t = %d\n",*t);

    p=&t;
    printf("*p = %d\n",*p);
    printf("++*p++ = %d\n",++*p++);
    printf("*p = %d\n",*p);
    printf("++*++p = %d\n",++*++p);
    printf("*p = %d\n",*p);
    printf("(*++p)++ = %d\n",(*++p)++);
    printf("*p = %d\n",*p);


    char ch[5]={'a','b','\0'};
    printf("%s\n",ch);

    //afficher_tab(4,t);

    */

    int x=11;
    int *ptr;
    ptr=&x;
    printf("&x=%d\nptr = %d\n*ptr = %d\n",&x,ptr,*ptr);
    return 0;
}