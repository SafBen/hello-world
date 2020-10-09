/*
 * Class to be completed
 */
public class Chopstick {

    boolean taken=false;
    PhilCanvas display;
    int identity;

    Chopstick(PhilCanvas display, int identity) {
        this.display = display;
        this.identity = identity;
    }

    synchronized void put() {
    	// begin modification
    	
    	// end modification
        
    	taken = false;
        display.setChop(identity,taken);
        
        // begin modification
        
    	// end modification
    }

    synchronized void get() throws java.lang.InterruptedException {
    	// begin modification
    	
    	// end modification
    	
    	taken = true;
        display.setChop(identity,taken);
        
        // begin modification

    	// end modification
    }
}
