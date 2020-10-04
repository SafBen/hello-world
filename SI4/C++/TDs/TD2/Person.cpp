//
// Created by safwane on 28/09/2020.
//

#include "Person.h"


Person::Person(string name, Gender gender) {
    this->gender=gender;
    this->name=name;
}

ostream &operator<<(ostream &os, const Person &p) {
    os << "Je suis " << p.name << ", je suis un" << p.gender;
    return os;
}
