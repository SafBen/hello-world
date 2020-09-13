package addressbook.v1t;

import java.util.Arrays;

/**
 * Provide a textual interface to an AddressBook. Different commands provide
 * access to the data in the address book.
 * 
 * One to search the address book.
 * 
 * One to allow a set of contact details to be entered.
 * 
 * One to show all the entries in the book.
 * 
 * @author David J. Barnes and Michael Kölling.
 * @author Peter Sander
 * @version 2016.02.29
 */
class AddressBookTextInterface {
    // The address book to be viewed and manipulated.
    private AddressBook book;
    // A parser for handling user commands.
    private Parser parser;

    /**
     * Constructor for objects of class AddressBookTextInterface
     * 
     * @param book
     *            The address book to be manipulated.
     */
    AddressBookTextInterface(AddressBook book) {
        this.book = book;
        parser = new Parser();
    }

    /**
     * Read a series of commands from the user to interact with the address
     * book. Stop when the user types 'quit'.
     */
    void run() {
        System.out.println("Address Book.");
        System.out.println("Type 'help' for a list of commands.");

        String command;
        do {
            command = parser.getCommand();
            switch (command) {
                case "add":
                    add();
                    break;
                case "list":
                    list();
                    break;
                case "search":
                    find();
                    break;
                case "help":
                    help();
                    break;
                default:
                    break;
            }
        } while (!(command.equals("quit")));

        System.out.println("Goodbye.");
    }

    /**
     * Add a new entry.
     */
    private void add() {
        System.out.print("Name: ");
        String name = parser.readLine();
        System.out.print("Phone: ");
        String phone = parser.readLine();
        System.out.print("Address: ");
        String address = parser.readLine();
        book.addDetails(new ContactDetails(name, phone, address));
    }

    /**
     * Find entries matching a key prefix.
     */
    private void find() {
        System.out.println("Type a prefix of the key to be found.");
        String prefix = parser.readLine();
        ContactDetails[] results = book.search(prefix);
        Arrays.asList(results)
                .forEach(r -> System.out.println(r + "\n====="));
    }

    /**
     * List the available commands.
     */
    private void help() {
        parser.showCommands();
    }

    /**
     * List the address book's contents.
     */
    private void list() {
        System.out.println(book.listDetails());
    }
}
