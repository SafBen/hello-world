/*
 * Exercice 2
 */

public class exo2 {
    // public static native void printCpp(); // Déclaration prototype méthode native
    public native void getPid(); // Déclaration prototype méthode native
    

    static {
        System.loadLibrary("exo2"); // Chargement de la bibliothèque
    }

    public static void main(String args[]) {
        exo2 obj = new exo2();
        obj.getPid();
    }
}