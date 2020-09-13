#include <stdio.h>
#include <stdarg.h>

float moyenne(int count,...){
	int compteur=count;
	va_list va;
	float sum=0;
	va_start(va,count);
	while(count--){
		sum+=va_arg(va,double);
	}
	va_end(va);
	return sum/compteur;
}

void cat_strings(char *str1, ...){
	va_list va;
	char *str=str1;
	va_start(va,str1);
	while (str){
		printf("%s", str);
		str=va_arg(va,char *);
	}
	putchar('\n');
	va_end(va);
}

int evaluer2(char operateur,int operande,...){
	va_list va;
	int res=operande;
	va_start(va,operande);
	if (res < 0) return 0;
	for (int current = va_arg(va, int); current >= 0; current=va_arg(va,int))
	{
		switch(operateur){
		case '+' : res+=current; break;
		case '-' : res-=current; break;
		case '*' : res*=current; break;
		case '/' : if (!current){ 
						res/=current; 
						break;
					}
					else {
                  		printf("*** ERREUR: division par 0\n");
                  		va_end(va);
                  		return 0;
					}
		}
	}
	va_end(va);
	return res;
}

int evaluer(char op, int operande, ...) {
  va_list ap;
  int res = operande;      // initialisation du résultat avec le premier nombre

  va_start(ap, operande);  // initialisation de ap
  if (res < 0) return 0;   // si aucun opérande on renvoie 0 par convention

  for(int courant = va_arg(ap, int); courant >= 0; courant = va_arg(ap, int)) {
    switch (op) {
      case '+': res += courant; break;
      case '-': res -= courant; break;
      case '*': res *= courant; break;
      case '/': if (courant != 0) {
                  res /= courant; break;
                } else {
                  printf("*** ERREUR: division par 0\n");
                  va_end(ap);
                  return 0;
                }
    }
  }
  va_end(ap);
  return res;
}

int main(int argc, char const *argv[])
{
	printf("Moyenne1 = %f\n", moyenne(2, 10.0, 15.0));                 // ⇒ 12.5
	printf("Moyenne2 = %f\n", moyenne(5, 10.0, 15.0, 18.5, 0.0, 3.5)); // ⇒ 9
	printf("Moyenne3 = %f\n", moyenne(0));     // ⇒ 0	
	cat_strings("es", "sai", NULL);
	printf("%d\n", evaluer('+', 1, 2, 3, -1));
	printf("%d\n",evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1));
	printf("%d\n", evaluer2('+', 1, 2, 3, -1));
	printf("%d\n",evaluer2('-', 10, evaluer2('*', 2, 2, 2, -1), 2, -1));
  return 0;
}