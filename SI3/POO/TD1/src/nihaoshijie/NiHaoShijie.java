package nihaoshijie;


public class NiHaoShijie {
    private String message = "Ni hao shijie";

    /**
     * Must use the variable message.
     * * @return the character string: "from NiHaoShijie: Ni hao shijie"
     */
    public String toString() {
        return "from NiHaoShijie: " + message;
    }

    /**
     * Prints the character string returned by the method toString
     */
    void print() {
        System.out.println(toString());
    }
}