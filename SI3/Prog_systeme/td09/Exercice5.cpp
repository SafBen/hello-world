#include "Exercice5.h"
#include <stdio.h>
#include <string.h>

JNIEXPORT jstring JNICALL Java_Exercice5_toString(JNIEnv *env, jobject obj) {
	char buffer[256];

	// Obtention de la Metaclasse de Exercice5
	jclass cls = env->GetObjectClass(obj);
	
	// Calcul de l'identificateur de l'attribut entier de type int
	jfieldID fid = env->GetFieldID(cls,"entier","I");
	
	// Récupération de la valeur entière de l'attribut
	int a = env->GetIntField(obj,fid);

	// Modification de la valeur entière de l'attribut
	env->SetIntField(obj, fid, a + 1);
	
	// Deuxieme récupération de la valeur entière de l'attribut
	a = env -> GetIntField(obj,fid);
	
	// Génération d'une chaîne contenant la valeur de l'attribut
	sprintf(buffer,"Hello [a = %d]",a);

	// On retourne un objet Java de chaîne de caractères
	return env->NewStringUTF(buffer);
}
