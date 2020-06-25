/*
 * Exercice 4
 */

public class exo4 {
    // public static native void printCpp(); // Déclaration prototype méthode native
    public native int fork(); // Déclaration prototype méthode native
    

    static {
        System.loadLibrary("exo4"); // Chargement de la bibliothèque
    }

    private void print(int n){
        for (int i=0;i<n;i++){
            System.out.print(i+"  ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        exo4 obj = new exo4();
        int P = 10;
        for (int i = 0; i < P; i++){
            switch (obj.fork()) {
                case -1 :       // Cas d'erreur
                    System.out.println("ERROR");
                    System.exit(1);
                case 0 :        // Processus fils
                    obj.print(P);   // On fait l'affichage
                    System.exit(1);    // On sort de la fonction pour éviter les duplications
                default :
                    break;
            }
        }
        return;
    }
}