#!/bin/sh
javac -h . *.java
g++ -c -fpic -Wall *.cpp -I "/home/user/Documents/intellij/idea-IU-193.6911.18/jbr/include" -I "/home/user/Documents/intellij/idea-IU-193.6911.18/jbr/include/linux"
#g++ -Wl,-soname,*.so -shared -o *.so *.o
#g++ -Wl,-soname,libHelloWorld.so -shared -o libHelloWorld.so HelloWorld.o
#g++ -Wl,-soname,libMessageScanner.so -shared -o libMessageScanner.so MessageScanner.o
