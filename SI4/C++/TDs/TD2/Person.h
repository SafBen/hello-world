//
// Created by safwane on 28/09/2020.
//

#ifndef TD2_CLION_PERSON_H
#define TD2_CLION_PERSON_H

using namespace std;
#include <string>

enum Gender {m,f};

class Person {
private:
    string name;
    Gender gender;

public:
    Person(string name, Gender gender);
    friend ostream& operator<<(ostream& os, const Person& p);
};


#endif //TD2_CLION_PERSON_H
