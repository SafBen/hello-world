#include <iostream>
#include "Person.h"

void test1(){
    Person charles = {"Charles",m};
    Person amandine = {"amandine",f};
    cout << charles << endl;
    cout << amandine << endl;
    charles.setParner(&amandine);
    cout << charles << endl;
    cout << amandine << endl;
    cout << "Partenaire de " << charles.getName() << " est " << charles.getPartner()->getName();
    cout << charles.getName() << " est " << charles.getGender();
}

void test2(){
    Person charles = {"Charles",m};
    Person amandine = {"amandine",f};
    Person* ptr = &charles;
    ptr->setParner(&charles);
    cout << charles << endl;
    cout << *ptr << endl;
    cout << &charles << endl << &ptr << endl;
    cout << charles.getName() << ptr->getName();
}

void test3(){
    Person charles = {"Charles",m};
    Person amandine = {"amandine",f};
    charles.setParner(&amandine);
    Person luc = {"Luc",m};
    charles.addEnfant(&luc);
    cout << charles;
}
void incr(int& ref){
    ref+=1;
}

int main() {
    //test3();

    return 0;
}
