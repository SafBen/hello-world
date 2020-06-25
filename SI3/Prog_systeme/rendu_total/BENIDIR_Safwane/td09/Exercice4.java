/*
 * Exercice 4
 */

public class Exercice4 {
    // public static native void printCpp(); // Déclaration prototype méthode native
    public native void callJavaMethod(); // Déclaration prototype méthode native
    

    static {
        System.loadLibrary("Exercice4"); // Chargement de la bibliothèque
    }

    public void test(String string){
        System.out.println(string);
    }

    public static void main(String args[]) {
        System.out.print("Hello "); // Affiche Hello en Java
        Exercice4 obj = new Exercice4();
        obj.callJavaMethod(); // Affiche World en C/C++
    }
}