/**
 * A class that maintains information on a book.
 * This might form part of a larger application such
 * as a library system, for instance.
 *
 * @author <a href="mailto:sander@unice.fr>Peter Sander</a>
 */
class Book {
    // The fields.
    private String author;
    private String title;
    /**
     * Set the author and title fields when this object
     * is constructed.
     */
    Book(String bookAuthor, String bookTitle) {
        author = bookAuthor;
        title = bookTitle;
    }

    void printAuthor()

}