package mailsystem;

/**
 * @author David J. Barnes and Michael Kolling
 * @version 2016.02.29
 * @author safwane benidir
 */
class MailItem {
    // The sender of the item.
    private final String from;
    // The intended recipient.
    private final String to;
    // The text of the subject.
    private final String subject;
    // The text of the message.
    private final String message;

    /**
     * Create a mail item from sender to the given recipient,
     * containing the given message.
     *
     * @param from
     *            The sender of this item.
     * @param to
     *            The intended recipient of this item.
     * @param message
     *            The text of the message to be sent.
     */
    MailItem(String from, String to,String subject ,String message) {
        this.from = from;
        this.to = to;
        this.subject = subject ;
        this.message = message;
    }

    /**
     * @return The sender of this message.
     */
    String getFrom() {
        return from;
    }

    /**
     * @return The intended recipient of this message.
     */
    String getTo() {
        return to;
    }

    /**
     * @return The text of the message.
     */
    String getMessage() {
        return message;
    }

    /**
     * @return The text of the subject.
     */
    String getSubject() {
        return subject;
    }

    /**
     * Print this mail message to the text terminal.
     */
    void print() {
        System.out.println("From: " + from);
        System.out.println("To: " + to);
        System.out.println("Subject: " + subject);
        System.out.println("Message: " + message);
    }
}

class MailClient {
    private MailServer serveur;
    private String user;

    MailClient(MailServer serveur, String user) {
        this.serveur = serveur;
        this.user = user;
    }

    MailItem getNextMailItem() {
        return this.serveur.getNextMailItem(this.user);

    }

    void printNextMailItem() {
        MailItem item = getNextMailItem() ;
        if(item == null) {
            System.out.println("No new mail.") ;
        }
        else {
            item.print();
        }
    }

    boolean sendMailItem(String to,String subj ,String message) {
        MailItem item = new MailItem(user, to,subj, message);
        return serveur.post(item);
    }

}