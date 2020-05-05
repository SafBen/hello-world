/*
 * Exercice 4
 */

#include "Exercice4.h"
#include <stdio.h>
JNIEXPORT void JNICALL Java_Exercice4_callJavaMethod(JNIEnv *env, jobject obj)
{
    // Récupération d'un objet de Metaclasse
    jclass cls = env->GetObjectClass(obj);
    // Calcule de l'identificateur de "void test(String str)"
    jmethodID mid = env->GetMethodID(cls, "test", "(Ljava/lang/String;)V");
    if (mid == 0)
    {
        // Ca a planté !!!
        fprintf(stderr, "Ouille, ça a planté !");
    }
    else
    {
        // Tout va bien, l'appel peut aboutir.
        jstring str = env->NewStringUTF("Ceci est un paramètre créé en C/C++");
        env->CallVoidMethod(obj, mid, str);
    }
    printf("World !\n");
    return;
}