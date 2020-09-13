class Souper {
    private final int numb = 42;

    private void souperAndSub() {
        System.out.println("Souper#souperAndSub numb = " + numb);
    }

    void souper() {
        System.out.println("Souper#souper");
        souperAndSub();
    }
}