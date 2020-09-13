package addressbook.v2t;

import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.TreeSet;

/**
 * A class to maintain an arbitrary number of contact details. Details are
 * indexed by both name and phone number.
 * 
 * @author David J. Barnes and Michael Kölling.
 * @version 2016.02.29
 */
class AddressBook {
    // Storage for an arbitrary number of details.
    private TreeMap<String, ContactDetails> book;
    private int numberOfEntries;

    /**
     * Perform any initialization for the address book.
     */
    AddressBook() {
        book = new TreeMap<>();
        numberOfEntries = 0;
    }

    /**
     * Look up a name or phone number and return the corresponding contact
     * details.
     * 
     * @param key
     *            The name or number to be looked up.
     * @return The details corresponding to the key.
     */
    ContactDetails getDetails(String key) {
        return book.get(key);
    }

    /**
     * Return whether or not the current key is in use.
     * 
     * @param key
     *            The name or number to be looked up.
     * @return true if the key is in use, false otherwise.
     */
    private boolean keyInUse(String key) {
        return book.containsKey(key);
    }

    /**
     * Add a new set of details to the address book.
     * 
     * @param details
     *            The details to associate with the person.
     */
    void addDetails(ContactDetails details) {
        if (details != null) {
            book.put(details.getName(), details);
            book.put(details.getPhone(), details);
            numberOfEntries++;
        }
    }

    /**
     * Change the details previously stored under the given key.
     * 
     * @param oldKey
     *            One of the keys used to store the details. This should be a
     *            key that is currently in use.
     * @param details
     *            The replacement details.
     */
    void changeDetails(String oldKey, ContactDetails details) {
        if (keyInUse(oldKey) && details != null) {
            removeDetails(oldKey);
            addDetails(details);
        }
    }

    /**
     * Search for all details stored under a key that starts with the given
     * prefix.
     * 
     * @param keyPrefix
     *            The key prefix to search on. This may be of zero length, but
     *            must not be null.
     * @return An array of those details that have been found.
     */
    ContactDetails[] search(String keyPrefix) {
        // Build a list of the matches.
        List<ContactDetails> matches = new LinkedList<ContactDetails>();
        if (keyPrefix != null) {
            // Find keys that are equal-to or greater-than the prefix.
            SortedMap<String, ContactDetails> tail = book.tailMap(keyPrefix);
            tail.keySet().stream()
                    .filter(k -> k.startsWith(keyPrefix))
                    .forEach(k -> matches.add(book.get(k)));
        }
        ContactDetails[] results = new ContactDetails[matches.size()];
        matches.toArray(results);
        return results;
    }

    /**
     * Return the number of entries currently in the address book.
     * 
     * @return The number of entries.
     */
    private int getNumberOfEntries() {
        return numberOfEntries;
    }

    /**
     * Remove the entry with the given key from the address book. The key should
     * be one that is currently in use.
     * 
     * @param key
     *            One of the keys of the entry to be removed.
     */
    void removeDetails(String key) {
        if (keyInUse(key)) {
            ContactDetails details = book.get(key);
            book.remove(details.getName());
            book.remove(details.getPhone());
            numberOfEntries--;
        }
    }

    /**
     * Return all the contact details, sorted according to the sort order of the
     * ContactDetails class.
     * 
     * @return A sorted list of the details.
     */
    String listDetails() {
        // Because each entry is stored under two keys, it is
        // necessary to build a set of the ContactDetails. This
        // eliminates duplicates.
        StringBuilder allEntries = new StringBuilder();
        Set<ContactDetails> sortedDetails = new TreeSet<ContactDetails>(
                book.values());
        sortedDetails.forEach(d -> allEntries.append(d + "\n\n"));
        return allEntries.toString();
    }
}
