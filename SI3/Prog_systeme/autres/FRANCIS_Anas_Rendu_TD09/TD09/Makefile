all: imports exe2
	java HelloWorld

imports:
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:C_files
	export LD_LIBRARY_PATH
	
exe2: exe
	javac HelloWorld.java

exe:
	make -C C_files 

very clean: 
	make clean -C C_files

clean:	very clean
	rm *.class 
