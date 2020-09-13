#include <stdio.h>
#include <stdarg.h>

int evaluer(char operateur, int operande, ...){
	va_list va;
	int res=operande;
	va_start(va,operande);
	switch(operateur){
		case '+': operande=va_arg(va,int);
				  while(operande>=0){
					res+=operande;
					operande=va_arg(va,int);
				} break;
		case '-': 	operande=va_arg(va,int);
					while(operande>=0){
						res-=operande;
						operande=va_arg(va,int);
				  } break;
		case '*': operande=va_arg(va,int);
				  while(operande>=0){
					res*=operande;
					operande=va_arg(va,int);
				  } break;
		case '/': operande=va_arg(va,int);
				  while(operande>=0){
					res/=operande;
					operande=va_arg(va,int);
				  } break;
	}
	va_end(va);
	return res;
}

int main(){
	printf("%d\n", evaluer('+',14,0,5,2,-1)); // 21
	printf("%d\n", evaluer('-',4,52,2,0,-3,9)); // -50
	printf("%d\n", evaluer('*',4,5,2,1,7,-4,4)); // 280
	printf("%d\n", evaluer('/',50,3,2,1,3,-7)); // 2
	printf("%d\n", evaluer('+', 1, 2, 3, -1)); // 6
	printf("%d\n", evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1)); // 0
	return 0;
}