package bookexercise;
/**
 * A class that maintains information on a book.
 * This might form part of a larger application such
 * as a library system, for instance.
 *
 * @author <a href="mailto:sander@unice.fr">Peter Sander</a>
 */
class Book {
    // The fields.
    final private String author;
    private final String title;
    private final int pages;
    private String refNumber;
    private int borrowed;

    /**
     * Set the author and title fields when this object
     * is constructed.
     */
    Book(String bookAuthor, String bookTitle, int bookPages) {
        author = bookAuthor;
        title = bookTitle;
        pages = bookPages;
        refNumber = "";
        borrowed=0;
    }

    // Add the methods here ...

    void printAuthor(){
        System.out.println(author);
    }

    void printTitle(){
        System.out.println(title);
    }

    int getPages(){
        return pages;
    }

    public String toString(){
        if (refNumber.length() == 0){
            return ("Title: "+title+"\nAuthor: "+author+"\nPages: "+pages+"\nThis book has been borrowed "+getBorrowed()+" times.\n");
        }
        else {
            return ("Title: "+title+"\nAuthor: "+author+"\nPages: "+pages+"\nReference: "+refNumber+"\nThis book has been borrowed "+getBorrowed()+" times.\n");
        }
    }

    void printDetails(){
        System.out.print(toString());
    }

    void setRefNumber(String ref){
        if (ref.length() < 3){
            System.out.println("Gotcha! RefNumber must be of length >= 3, but was "+ref.length());
        }
        else{
            refNumber=ref;
        }
    }

    String getRefNumber(){
        return refNumber;
    }

    void borrow(){
        borrowed++;
    }

    int getBorrowed(){
        return borrowed;
    }
}
