package bookexercise;
/**
 * A class that maintains information on a book.
 * This might form part of a larger application such
 * as a library system, for instance.
 *
 * @author <a href="mailto:sander@unice.fr">Peter Sander</a>
 */
class Main {

    public static void main(String... args) {
        final String ref = "";
        Book book = new Book("George Lacaisse", "Milking It", 26745);
        book.setRefNumber(ref);
        book.printDetails();
    }
}
