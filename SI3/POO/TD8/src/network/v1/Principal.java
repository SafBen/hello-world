package network.v1;

public class Principal {
    public static void main(String[] args) {
        MessagePost mp = new MessagePost("Homer Simpson", "Facts are meaningless. You can use facts to prove anything that's even remotely true!");
        mp.like();
        mp.like();
        mp.unlike();
        mp.display();

    }
}
