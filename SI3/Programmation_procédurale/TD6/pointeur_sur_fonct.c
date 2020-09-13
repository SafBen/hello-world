#include <stdio.h>

int sum(int a, int b){
	return a+b;
}

int iterate(int (*fnptr)(int,int), int *tab, int len){
	int k;
	for (int i = 0; i < len; i++)
	{
		k=i;
		if (!i)
		{
			tab[i]=fnptr(tab[i],tab[--k]);
		}
		printf("%d\n", tab[i]);
	}
}

int main(int argc, char const *argv[])
{
	int tab[4]={1,2,3,4};
	printf("%d\n", iterate(sum,tab,4));
	return 0;
}