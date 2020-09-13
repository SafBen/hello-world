#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct string {
	char *s; 	// les caractères de la chaîne
	int lg;		// longueur de la chaîne
} *String;

String string(const char *s) {
	String  ms = malloc(sizeof(struct string));
	ms ->lg = strlen(s);// on alloue la place mémoire pour la nouvelle chaîne de car
	ms ->s = malloc(sizeof(char)*ms->lg+1);
	// et on la copie
	strcpy(ms->s, s);
	return ms;
}

String stringCat(const String s1, const String s2) {
	String ms = malloc(sizeof(struct string));
	ms->lg = s1->lg+s2->lg;
	ms->s = malloc(ms->lg+1);
	ms->s = strcat(strcpy(ms->s, s1->s), s2->s);
	return ms;
}

int main(void){
	String s1,s2;
	char chaine1 = "bon";
	char chaine2 = "jour";
	s1 = string(chaine1);
	s2 = string(chaine2);
	s = stringCat(s1,s2);
	printf("")
}