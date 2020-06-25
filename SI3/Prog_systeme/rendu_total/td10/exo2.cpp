/*
 * Exercice 2
 */

#include "exo2.h"
#include <stdio.h>
#include <unistd.h>
JNIEXPORT void JNICALL Java_exo2_getPid(JNIEnv *env, jobject obj)
{
    printf("Pid = %d\n",getpid());
    return;
}