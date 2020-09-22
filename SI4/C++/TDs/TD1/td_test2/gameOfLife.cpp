//
// Created by safwane on 20/09/2020.
//

#include "gameOfLife.h"

void affiche(std::array<bool,SIZE> array,int generation){
    std::cout << "Génération : " << generation << "\n[";
    for (int i = 0; i < SIZE-1; i++)
    {
        std::cout << (array[i]==0 ? "false" : "true") << ", ";
    }
    std::cout << (array[SIZE-1]==0 ? "false" : "true") << "]";
    std::cout<<std::endl;
}

std::array<bool, SIZE> init_array_1d(){
    std::array<bool, SIZE> array{};
    srand(time(nullptr)); // to change value of rand()
    for (int i = 0; i <SIZE; i++) {
        array[i] = rand() % 2 != 0;
    }
    return array;
}

std::array<bool, SIZE> next_step_1d(std::array<bool, SIZE> array){
    for (int i = 0; i <SIZE; i++)
    {
        bool prev,current;
        if (i==0 || i==SIZE-1)
        {
            prev=array[i];
            array[i]=false;
        }
        else{
            current=array[i];
            array[i]=prev & array[i+1];
            prev=current;
        }
    }
    return array;
}

void gameOfLife_1d(){
    std::array<bool, SIZE> array=init_array_1d();
    for (int i = 0; i < GENERATION; i++) {
        affiche(array,i+1);
        array=next_step_1d(array);
    }
}
