package addressbook.v3t;

/**
 * Capture a key that failed to match an entry in the address book.
 * 
 * @author David J. Barnes and Michael Kölling.
 * @author Peter Sander
 * @version 2016.02.29
 */
@SuppressWarnings("serial")
class NoMatchingDetailsException extends RuntimeException {
    NoMatchingDetailsException(String key) {
        super(key);
    }

    public String toString() {
        return "No details matching: " + getMessage() + " were found.";
    }
}
