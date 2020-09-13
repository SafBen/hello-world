#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
	char *s;
	int lg;
} *String;

struct element
{
	int value;
	struct element *next;
};

typedef struct element Element;


String string(const char *s){
	String str = malloc(sizeof(String));
	str->lg=strlen(s);
	str->s=malloc(sizeof(char)*str->lg);
	strcpy(str->s,s);
	return str;
}

String stringCat(String s1, String s2){
	String str = malloc(sizeof(String));
	str->lg=s1->lg+s2->lg;
	str->s=malloc(sizeof(char)*str->lg);
	str->s=strcat(strcpy(str->s,s1->s),s2->s);
}

Element *push_item(int x, Element *p){
	struct element *new = malloc(sizeof(Element));
	if (!new) {
		fprintf(stderr, "allocation failed\n");
		exit(1);
	}
	new->value  = x;
	new->next   = p;
	return new;
}

Element *pop_item(Element *p){
	if (p){
		Element *old = p;
		p=p->next;
		free(old);
		return p;
	}
	fprintf(stderr, "error\n");
	exit(1);
}



int main(int argc, char const *argv[])
{
	Element *p=NULL;
	p=push_item(3,p);
	p=push_item(5,p);
	printf("%d\n", p->value);
	printf("%d\n", p->next->value);
	p=pop_item(p);
	printf("%d\n", p->value);
	//printf("%d\n", p->next->value);
	String str1 = string("klzdsfdsfej");
	String str2 = string("abcd");
	String s = stringCat(str1,str2);
	printf("%s\n", s->s);
	printf("%s\n", str1->s);
	printf("%d\n", str1->lg);
	return 0;
}