#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

extern void load_library(char *library_name);
static void (*sortLib)(int list[], int size);

void load_library(char *library_name){
    /*
    void *handle;
    void (*sortLib)(int [], int);
    char *error;

    handle = dlopen(library_name,RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
        }
    
    dlerror();

    *(void **) (&sortLib) = dlsym(handle, library_name);

    error = dlerror();
           if (error != NULL) {
               fprintf(stderr, "%s\n", error);
               exit(EXIT_FAILURE);
           }
        
    int list[4];

    // Initialize a ramdom list of numbers;
    srand(0);
    for (int i = 0; i < 4; i++) {
        list[i] = rand() % 1000;
    }
    print_list(list, 4);
    */
   FILE* plib = (FILE*)dlopen(library_name,RTLD_LAZY);
   dlerror();
   sortLib=dlsym(plib,"sort");

   int list[40];

    // Initialize a ramdom list of numbers;
    srand(0);
    for (int i = 0; i < 4; i++) {
        list[i] = rand() % 1000;
    }
    sortLib(list,4);
    print_list(list, 4);
}

int main(void){
    load_library("libTri_bubble-dynamicLib.so");
}