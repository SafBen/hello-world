#include <stdio.h>

void imprimerBaseB(int n,int base){
	if (n<0){
		putchar('-');
		n=-n;
	}
	
	if (n>=base){
		imprimerBaseB(n/base,base);
	}
	putchar(n%base+((n%base>=10) ? 'A'-10 : '0'));
}

void enBinaire(int n){
	unsigned int masque=1<<(8*sizeof(int)-1);
	while (masque>0){
		putchar(((masque&n)?'1':'0'));
		masque>>=1;
	}
	putchar('\n');
}



int main(int argc, char const *argv[])
{
	imprimerBaseB(12,2);
	putchar('\n');
	enBinaire(14);
	return 0;
}