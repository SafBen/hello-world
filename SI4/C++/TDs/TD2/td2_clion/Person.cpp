//
// Created by safwane on 28/09/2020.
//

#include "Person.h"


Person::Person(string name, Gender gender):name(name),gender(gender){

}

ostream &operator<<(ostream &os, const Person &p) {
    string gender = p.gender==m ? " homme. " : "e femme. ";
    string partner = (p.partner== nullptr) ? "Je suis célibataire. " : "Mon partenaire est " + p.partner->name+". ";
    string enfant = (p.enfants.empty()) ? "Je n'ai pas d'enfants. " : "J'ai " + to_string(p.enfants.size()) + " enfants";
    os << "Je m'appelle " << p.name << ", je suis un" << gender << partner << enfant;
    return os;
}

void Person::setParner(Person *p) {
    if (this->partner != nullptr){
        this->partner->partner = nullptr; //sanity check required here
    }
    if (p != nullptr){
        p->partner = this;
    }
    this->partner = p;
}

Person* Person::getPartner() {
    return this->partner;
}

string Person::getName() {
    return this->name;
}

string Person::getGender() {
    return (this->gender==m) ? "un homme" : "une femme";
}

void Person::addEnfant(Person* person) {
    this->enfants.push_back(person);
}

Person::Person(string name, Gender gender, array<Person*,2> parents):name(name),gender(gender) {
    this->parents.at(0)=parents.at(0);
    this->parents.at(1)=parents.at(1);
}

void Person::setParents(Person* pere, Person* mere) {
    this->parents.at(0)=pere;
    this->parents.at(1)=mere;
}

array<Person *, 2> Person::getParents() {
    return this->parents;
}
