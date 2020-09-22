//
// Created by safwane on 20/09/2020.
//

#include <iostream>
#include <string>
#include "palindrom.h"

void palindrom(std::string s){
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i]!=s[s.length()-i-1]){
            std::cout << "No palindrom" << std::endl;
            return;
        }
    }
    std::cout << s <<" is a palindrom" << std::endl;
    return;
}
