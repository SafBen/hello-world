#include <iostream>
#include <string>
#include <array>

const int SIZE = 10;
const int GENERATION = 5;

void affiche(std::array<bool,SIZE> array,int generation);
std::array<bool, SIZE> next_step_1d(std::array<bool, SIZE> array);
std::array<bool, SIZE> init_array_1d();
void gameOfLife_1d();