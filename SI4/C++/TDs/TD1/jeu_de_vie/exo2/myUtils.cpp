#include "myUtils.h"

const std::array<int, MAX> init_container1D(){
	srand (time(NULL));
	std::array<int, MAX> to_ret;
	for(int i = 0; i < MAX; i++){
		to_ret.at(i) = rand()%2 == 0? false:true ;
	}
	
	return to_ret;
}

void affiche(const std::array<int, MAX> cont){
	for(int i = 0; i<MAX ; i++){
		std::cout << cont.at(i)<<" ";
	}
	std::cout<<std::endl;
}

void affiche2D(const std::array< std::array<int,MAX>, MAX> cont){
	for(int i = 0; i<MAX ; i++){
		for(int j = 0; j<MAX; j++){
			std::cout << (cont.at(i)).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}


const std::array< std::array<int,MAX>, MAX> init_container2D(){
	srand (time(NULL));
	std::array< std::array<int,MAX>, MAX> to_ret;
	for(int i = 0; i<MAX; i++){
		for(int j = 0; j<MAX ; j++){
			(to_ret.at(i)).at(j) = rand()%2 == 0? false:true ;
		}
	}
	return to_ret;
}
