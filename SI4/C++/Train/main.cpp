#include <iostream>
#include "Rectangle.h"
#include "Segment.h"

using namespace std;


int do_something1(string s){
    int i = 06;
    s = s + "!";
    return i;
}
void exo1(){
    string s = "yeah ";
    cout << s << endl;
    do_something1(s);
    cout << s << endl;
    //cout << i << endl;
    int j = 29;
    j = do_something1(s);
    cout << s << endl;
    cout << j << endl;
}

string* do_something2(string s){
    string* pt_s = &s;
    s = s + "!";
    return pt_s;
}

void exo2(){
    string s = "yeah ";
    cout << s << endl;
    do_something2(s);
    cout << s << endl;
    string* pt_s = do_something2(s);
    cout << pt_s << endl;
    cout << (*pt_s) << endl;
    cout << s << endl;
}

string* do_something3(string* s){
    string* pt_s = s;
    (*s) = (*s) + "!";
    return pt_s;
}

void exo3(){
    string s = "yeah ";
    cout << s << endl;
    do_something3(&s);
    cout << s << endl;
    string* pt_s = do_something3(&s);
    cout << s << endl;
    cout << (*pt_s) << endl;
}

string* do_something4(string& s){
    string* pt_s = &s;
    s = s + "!";
    return pt_s;
}
void exo4() {
    string s = "yeah ";
    cout << s << endl;
    do_something4(s);
    cout << s << endl;
    string *pt_s = do_something4(s);
    cout << (*pt_s) << endl;
}

string do_something5(string& s){
    s = s + "!";
    return s;
}
void exo5() {
    string s = "yeah ";
    cout << s << endl;
    do_something5(s);
    cout << s << endl;
    string s2 = do_something5(s);
    cout << s2 << endl;
    cout << &s << endl;
    cout << &s2 << endl;
}

string& do_something6(string s){
    s = s + "!";
    return s;
}

void exo6() {
    string s = "yeah ";
    cout << s << endl;
    do_something6(s);
    cout << s << endl;
    string s2 = do_something6(s);
    cout << s2 << endl;
    cout << &s << endl;
    cout << &s2 << endl;
}

string do_something7(string** s){
    string* s2 = *s;
    **s = *s2 + "!";
    return **s;
}
void exo7() {
    string s = "yeah ";
    cout << s << endl;
    //do_something7(&&s);
    cout << s << endl;
    string * s0 = &s;
    string s2 = do_something7(&s0);
    cout << s2 << endl;
    cout << &s << endl;
    cout << &s2 << endl;
}

int main(){
    Rectangle rectangle = Rectangle();
    cout << rectangle.getLength() << endl;
    cout << rectangle.getWidth() << endl;
    cout << rectangle.getSegment().longueur << endl;

    Segment segment = Segment();
    cout << segment.longueur << endl;
    /*
    exo5();
    int i=5;
    int& refi=i;
    cout << "@i = " << &i << endl;
    cout << "@refi = " << &refi << endl;
    cout << "refi = " << refi << endl;
    string* pi = new string("toto");
    delete pi;
    cout << (*(pi+8000)) << endl;
     */
    return EXIT_SUCCESS;
}