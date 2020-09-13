#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
	int value;
	struct element *next;
};

typedef struct element Element;

typedef Element *List;

int find_element(List lst, int v){
	for (Element *p=lst;p; p=p->next)
	{
		if (p->value==v)
		{
			return 1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	List l = malloc(sizeof(List));
	List vide=NULL;
	l->value=3;
	l->next=vide;
	printf("%d\n", l->value);
	printf("%d\n", find_element(l,2));
	return 0;
}