import java.util.Scanner;

public class HelloWorld {

	 private int entier = 0;
	 
	 public static void test(String str){
	 	System.out.println(str);
	 }
	 
	 public static native void printCpp(); // Déclaration prototype méthode native
	 public static native void printStringToCpp(String str);
	 public native void callJavaMethod();
	 public native String toString();
	 
	 
	 static {
	 	System.loadLibrary("HelloWorld"); // Chargement de la bibliothèque
	 }
	 public static native String stringFromCpp();
	 

	 public static void main(String args[]) {
	 	HelloWorld hw = new HelloWorld();
		System.out.println("Hello "); // Affiche Hello en Java
		System.out.println("Saisissez une valeur!");
		Scanner myObj = new Scanner(System.in);
		String donnes = myObj.nextLine();

		//hw.callJavaMethod(); // provoque une erreur ...
		System.out.println(hw.toString());
		System.out.println(HelloWorld.stringFromCpp());
	 	HelloWorld.printCpp(); // Affiche World en C/C++
	 }
}
