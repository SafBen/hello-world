/*
 * Exercice 4
 */

public class JavaFromC {
    // public static native void printCpp(); // Déclaration prototype méthode native
    public static native void callJavaMethod(); // Déclaration prototype méthode native
    

    static {
        System.loadLibrary("JavaFromC"); // Chargement de la bibliothèque
    }

    public static void test(String string){
        System.out.println(string);
    }

    public static void main(String args[]) {
        System.out.print("Hello "); // Affiche Hello en Java
        JavaFromC.callJavaMethod(); // Affiche World en C/C++
    }
}