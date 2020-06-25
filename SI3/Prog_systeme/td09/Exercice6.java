/*
 * Exercice 6
 */


public class Exercice6 {

    public native int fib(int entier);

    static {
        System.loadLibrary("Exercice6"); // Chargement de la bibliothèque
    }

    public static void main(String args[]) {
        Exercice6 exo6 = new Exercice6();
        System.out.println("fib("+10+") = "+exo6.fib(10));
    }
}


