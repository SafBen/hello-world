#include "Exercice6.h"
#include <stdio.h>
#include <string.h>


static int fib(int n) {
    if (n < 2) return n;
    else return fib(n-1) + fib(n-2);
    }

JNIEXPORT jint JNICALL Java_Exercice6_fib(JNIEnv *env, jobject obj, jint entier) {
    return fib(entier);
}
