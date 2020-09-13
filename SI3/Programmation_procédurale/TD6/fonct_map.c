#include <stdio.h>

int carre(int n){
	return n*n;
}


/*void map(int *tab, int len, int(*fnptr)(int)){
	for (int i = 0; i < len; i++)
	{
		tab[i]=fnptr(tab[i]);
	}
}*/

int main(int argc, char const *argv[])
{
	/*
	int tab[4]={1,2,3,4};
	map(tab,4,carre);
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", tab[i]);
	}
	*/
	int n=10;
	int *p;
	p=n;
	printf("%d\n",*p);
	return 0;
}