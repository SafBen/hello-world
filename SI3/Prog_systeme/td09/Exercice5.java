
public class Exercice5 {

	 private int entier = 0;
	 
	 public native String toString();
	 
	 
	 static {
	 	System.loadLibrary("Exercice5"); // Chargement de la bibliothèque
	 }
	 public static native String stringFromCpp();
	 

	 public static void main(String args[]) {
	 	Exercice5 hw = new Exercice5();
		System.out.println(hw.toString());
	 }
}
