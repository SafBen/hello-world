#include <stdio.h>
#include <stdarg.h>

float moyenne(int count, ...){
	float res = 0.0;
	va_list va;
	va_start(va,count);
	if (count==0) return 0;
	for (int i=0;i<count;i++){
		res+=va_arg(va,double);
	}
	va_end(va);
	return res/count;
}

int main(){
	printf("%f\n", moyenne(2, 10.0, 15.0));
	printf("%f\n", moyenne(5, 10.0, 15.0, 18.5, 0.0, 3.5));
	printf("%f\n", moyenne(0));
	return 0;
}