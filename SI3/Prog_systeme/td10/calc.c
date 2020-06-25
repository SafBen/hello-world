#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    float vitesseLune = 3683.590215;    // km/h
    vitesseLune = vitesseLune/3.6;   // m/s

    float tempsLune = 27.32;    //jours

    float jourSideral = 23*60*60+56*60+4;     // 23 h 56 min 4 s

    float anneeLune = 12*27.32*jourSideral;

    float distance = vitesseLune*anneeLune;

    float vitesseLum = distance/jourSideral;

    printf("%f\n",vitesseLum);

    return 0;
}