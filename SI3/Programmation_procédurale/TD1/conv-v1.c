#include <stdio.h>

int main(){
	float celsius = 0.0;
	float fahrenheit = 32.0;
	while (celsius<=20.0){
		printf("|  %.0fC | %.0fF |\n", celsius, fahrenheit);
		celsius+=0.5;
		fahrenheit= 1.8*celsius + 32;
	}
	return 0;
}