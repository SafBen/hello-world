#include "myUtils.h"

void jeu_de_vie_1D(){
	std::array<int, MAX> empty;
	for(int i = 0; i<MAX ;i++){
		bool value;
		if(i<=0 || i>=MAX - 1){
			if(i<=0){
				value = false & container1D.at(i+1);
			}
			else{
				value = container1D.at(i-1) & false;
			}
		}
		else{
			value = container1D.at(i-1) & container1D.at(i+1);
		}
		empty.at(i) = value;
	}
	affiche(container1D);
	affiche(empty);
}

void jeu_de_vie_2D(){
	std::array<std::array<int,MAX>, MAX> empty;
	for(int i = 0; i<MAX ;i++){
		for(int j = 0; j<MAX ;j++){
			bool value;
			if(j<=0 || j>=MAX - 1){
				if(j<=0){
					value = false & (container2D.at(i)).at(j+1);
				}
				else{
					value = (container2D.at(i)).at(j-1) & false;
				}
			}
			else{
				value = (container2D.at(i)).at(j-1) & (container2D.at(i)).at(j+1);
			}
			(empty.at(i)).at(j) = value;
		}
	}

	affiche2D(empty);
}


int main(){
	
	std::cout<< "jeu de vie 1 diemension\n";
	jeu_de_vie_1D();
	std::cout<< "jeu de vie 2 diemensions\a\n";
	jeu_de_vie_2D();
	return 0;
}
