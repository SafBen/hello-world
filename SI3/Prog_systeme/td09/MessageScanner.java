/*
 * Exercice 2 et 3
 */

import java.util.Scanner;

public class MessageScanner {

    public static native void printCpp(); // Déclaration prototype méthode native
    public static native void printStringToCpp(String string); // Déclaration prototype méthode native
    public static native String stringFromCpp(); // Déclaration prototype méthode native

    static {
        System.loadLibrary("MessageScanner"); // Chargement de la bibliothèque
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Veuillez saisir un mot : ");
        String str = sc.nextLine();
        System.out.println("Vous avez saisi : " + str);
        MessageScanner.printCpp(); // Affiche World ! en C/C++
        MessageScanner.printStringToCpp("Java vers C");
        System.out.println("Ce message vient de C : " + MessageScanner.stringFromCpp());
    }
}


