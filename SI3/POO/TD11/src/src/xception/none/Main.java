package xception.none;

import java.util.Random;

class Main {

    public static void main(String[] args) {
        final Random rand = new Random();
        // generates a random int with values -1, 0, 1
        final int i = rand.nextInt(3) - 1;
        // calculates sqroot of random int
        final double sqres = new YetAnotherClass().yetAnotherMethod(i);
        System.out.println("sqres = " + sqres);
        // if something weird happens then blows up
        //  and you have to admit that sqres != sqres -> true is a bit weird
        if (sqres != sqres) {
            throw new ArithmeticException("Panic! " + sqres + " != " + sqres);
        }
    }
}
