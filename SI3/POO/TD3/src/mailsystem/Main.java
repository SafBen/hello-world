package mailsystem;

class Main{

    public static void main(String[] args){
        String JOHN = "John";
        String PAUL = "Paul";
        String MSG = "Yo! Ni hao! Tervist!";
        MailServer server= new MailServer();
        MailClient from = new MailClient(server, JOHN);
        MailClient to = new MailClient(server, PAUL);
        //from.sendMailItem(PAUL, MSG);
        MailItem item = to.getNextMailItem();
        System.out.println(item != null);
        System.out.println(MSG.equals(item.getMessage()));
        System.out.println(JOHN.equals(item.getFrom()));
        System.out.println(PAUL.equals(item.getTo()));
    }
}