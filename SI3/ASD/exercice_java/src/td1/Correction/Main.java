package td1.Correction;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner input;
        input = new Scanner(System.in);
        Recursion.permutations(input.nextInt());
        System.out.println(Recursion.compteur);
    }
}
