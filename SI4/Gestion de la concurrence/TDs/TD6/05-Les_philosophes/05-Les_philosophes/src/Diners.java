import java.awt.*;

public class Diners extends Panel {
	public static final long serialVersionUID = 1L;
	
    PhilCanvas display;
    Thread[] phil= new Thread[PhilCanvas.NUMPHILS];
    Chopstick[] stick = new Chopstick[PhilCanvas.NUMPHILS];
    Scrollbar slider;
    Button restart;
    Button freeze;

    public void init() {
        setLayout(new BorderLayout());
        
        display = new PhilCanvas(this);
        add("Center",display);
        
        Panel p1 = new Panel();
        p1.setLayout(new BorderLayout());
        slider = new Scrollbar(Scrollbar.HORIZONTAL, 50, 5, 0, 100);
        restart = new Button("Restart");
        freeze = new Button("Freeze");
        p1.add("Center",slider);
        p1.add("East",restart);
        p1.add("West",freeze);
        add("South",p1);
    }

    Thread makePhilosopher(Diners d, int id, Chopstick left, Chopstick right) {
    	return new Philosopher(d,id,left,right);
    }

    public void start() {
       for (int i =0; i<PhilCanvas.NUMPHILS; ++i)
            stick[i] = new Chopstick(display,i);
       for (int i =0; i<PhilCanvas.NUMPHILS; ++i){
            phil[i] = makePhilosopher(this,i,
                        stick[(i-1+PhilCanvas.NUMPHILS)% PhilCanvas.NUMPHILS],
                        stick[i]);
            phil[i].start();
       }
    }

    public void stop() {
        for (int i =0; i<PhilCanvas.NUMPHILS; ++i)
            phil[i].interrupt();
    }

    public boolean handleEvent(Event event) {
    	if(event.target==restart) {
    		//if (display.deadlocked(stick)) {
    		if (display.deadlocked()) {
                stop();
                slider.setValue(50);
                start();
    		}
            display.thaw();
            return true;
        } else if (event.target == freeze) {
            display.freeze();
            return true;
        } else
            return false;
    }
    
    public static void main(String[] args) {
        Frame f = new Frame();
        f.addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent e) {
                System.exit(0);
            }
        });

        Diners ut = new Diners();
        f.add(ut);
        f.pack();
        ut.init();
        f.setSize(350, 350);
        f.setVisible(true);
        ut.start();
    }

}
