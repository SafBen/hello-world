package addressbook.v3t;

/**
 * This will create a sample AddressBook along with a text
 * interface for the purposes of interactive experimentation.
 * @author <html><a href="mailto:sander@polytech.unice.fr">(c)2012 Peter Sander</a></html>
 */
public class Main {

    public static void main(String[] args) throws DuplicateKeyException {
        new AddressBookDemo().showInterface();
    }
}
