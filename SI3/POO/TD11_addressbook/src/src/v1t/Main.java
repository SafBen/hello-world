package v1t;

public class Main {

    public static void main(String[] args) {
        AddressBook book = new AddressBook();
        System.out.println(book.getNumberOfEntries());
        AddressBookTextInterface interaction = new AddressBookTextInterface(book);
        interaction.run();
        System.out.println(book.getNumberOfEntries());
    }
}
