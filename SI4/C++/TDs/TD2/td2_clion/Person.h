//
// Created by safwane on 28/09/2020.
//

#ifndef TD2_CLION_PERSON_H
#define TD2_CLION_PERSON_H

#include <string>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

enum Gender {m,f};

class Person {
private:
    string name;
    Gender gender;
    /*
     * Person partner   ? non récursivité
     * Person* partner  ? oui
     * Partner& partner ? non car on devrait initialiser à la création
     */
    Person* partner = nullptr;
    vector <Person*> enfants;
    array <Person*,2> parents;

public:
    Person(string name, Gender gender);
    Person(string name, Gender gender, array<Person*,2> parents);
    friend ostream& operator<<(ostream& os, const Person& p);
    string getName();
    string getGender();
    void setParner(Person* person);
    Person* getPartner();
    void addEnfant(Person* person);
    void setParents(Person* pere, Person* mere);
    array<Person*,2> getParents();
};


#endif //TD2_CLION_PERSON_H
