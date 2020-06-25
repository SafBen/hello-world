/*
 * Exercice 3
 */

public class exo3 {
    // public static native void printCpp(); // Déclaration prototype méthode native
    public native int fork(); // Déclaration prototype méthode native
    

    static {
        System.loadLibrary("exo3"); // Chargement de la bibliothèque
    }

    public static void main(String args[]) {
        exo3 obj = new exo3();
        int f=obj.fork();
        System.out.println(f);
    }
}