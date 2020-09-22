#ifndef _JEU_DE_VIE
#define _JEU_DE_VIE

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <time.h>

const int MAX = 50;

const std::array<int, MAX> init_container1D();

const std::array< std::array<int,MAX>, MAX> init_container2D();

const std::array<int, MAX> container1D = init_container1D();

const std::array<std::array<int,MAX>, MAX> container2D = init_container2D();

void affiche(const std::array<int, MAX> cont);

void affiche2D(const std::array<std::array<int,MAX>, MAX>  cont);

#endif
