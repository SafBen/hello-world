/*
 * Exercice 2 et 3
 */

#include "MessageScanner.h"
#include <stdio.h>
JNIEXPORT void JNICALL Java_MessageScanner_printCpp(JNIEnv *env, jclass cls)
{
    printf("Message sans paramètre\n");
}

JNIEXPORT void JNICALL
Java_MessageScanner_printStringToCpp(JNIEnv *env, jclass cl, jstring str)
{
    // Construction d'une chaîne C/C++ à partir d'une chaîne Java
    const char *cStr = env->GetStringUTFChars(str, 0);
    // Affichage de la chaîne C++
    printf("Ce message vient de Java : %s\n", cStr);
    // Libération de la chaîne C++
    env->ReleaseStringUTFChars(str, cStr);
}

JNIEXPORT jstring JNICALL
Java_MessageScanner_stringFromCpp(JNIEnv *env, jclass cl)
{
    // Construction d'une chaîne Java à partir d'une chaîne C/C++
    return env->NewStringUTF("C vers Java");
}