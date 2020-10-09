import java.awt.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

class PhilCanvas extends Canvas {
	private static final long serialVersionUID = 1L;

	Diners controller;

    static final int NUMPHILS = 5;
    static final int THINKING = 0;
    static final int HUNGRY = 1;
    static final int GOTRIGHT = 2;
    static final int EATING =3;
    static final int GOTLEFT = 4;

    Image[] imgs = new Image[5];


    double [] philX  = new double[NUMPHILS];
    double [] philY  = new double[NUMPHILS];
    int [] state     = new int [NUMPHILS];
    boolean[] redraw = new boolean[NUMPHILS];

    double [] chopX  = new double[NUMPHILS];
    double [] chopY  = new double[NUMPHILS];
    boolean[] untable= new boolean[NUMPHILS];

    boolean wasdeadlocked = false;

    boolean frozen = false;

    public PhilCanvas(Diners controller) {
        super();
        this.controller = controller;

        MediaTracker mt;
        mt = new MediaTracker(this);

        Path imgPath = Paths.get("images/thinking.gif");
        if (Files.exists(imgPath)) {
        	imgs[0] = Toolkit.getDefaultToolkit().getImage("images/thinking.gif");
        	imgs[1] = Toolkit.getDefaultToolkit().getImage("images/hungry.gif");
        	imgs[2] = Toolkit.getDefaultToolkit().getImage("images/gotright.gif");
        	imgs[3] = Toolkit.getDefaultToolkit().getImage("images/eating.gif"); 
        	imgs[4] = Toolkit.getDefaultToolkit().getImage("images/gotleft.gif");
        } else {
        	System.out.println("Couldn't load one of the images");
            System.exit(-1);
        }
        
        mt.addImage(imgs[0], 0);
        mt.addImage(imgs[1], 1);
        mt.addImage(imgs[2], 2);
        mt.addImage(imgs[3], 3);
        mt.addImage(imgs[4], 4);
        
        try {
            mt.waitForID(0);
            mt.waitForID(1);
            mt.waitForID(2);
            mt.waitForID(3);
            mt.waitForID(4);
        } catch (java.lang.InterruptedException e) {
            System.out.println("Couldn't load one of the images");
        }
        initPlacing();
    }

    Image offscreen;
    Dimension offscreensize;
    Graphics offgraphics;

    public void backdrop() {
        Dimension d = getSize();
	    if ((offscreen == null) || (d.width != offscreensize.width)
	                            || (d.height != offscreensize.height)) {
	        offscreen = createImage(d.width, d.height);
	        offscreensize = d;
	        offgraphics = offscreen.getGraphics();
	        offgraphics.setFont(new Font("Helvetica",Font.BOLD,18));
	    }
        offgraphics.setColor(Color.lightGray);
        offgraphics.fillRect(0, 0, getSize().width, getSize().height);
        for (int i = 0; i < NUMPHILS; i++) {
            redraw[i] = true;
        }
     }

    public void drawtable() {
        offgraphics.setColor(Color.red);
        offgraphics.fillOval(105,105,90,90);
        offgraphics.setColor(Color.black);
        for(int i=0; i<NUMPHILS; i++) {
            if(untable[i])
            	offgraphics.fillOval((int)chopX[i],(int)chopY[i],10,10);
        }
    }

    public void paint(Graphics g) {
        backdrop();
        update(g);
    }

    public void update(Graphics g) {
        if (wasdeadlocked) {
            backdrop();
            wasdeadlocked=false;
        }
        for (int i = 0; i < NUMPHILS; i++) {
            if (redraw[i]) {
                philPaint(offgraphics,i);
                redraw[i] = false;
            }
        }
        drawtable();
        if (deadlocked()) {
            offgraphics.setColor(Color.black);
            offgraphics.drawString("DEADLOCKED",90,130);
            wasdeadlocked=true;
        }
        g.drawImage(offscreen, 0, 0, null);
    }

   public void philPaint(Graphics g,int i) {
        g.setColor(Color.lightGray);
        g.fillRect((int)philX[i], (int)philY[i],imgs[0].getWidth(this),imgs[0].getHeight(this));
        g.drawImage(imgs[state[i]], (int)philX[i], (int)philY[i], this);
   }

    public synchronized void setPhil(int id,int s)  throws java.lang.InterruptedException{
        while (frozen) wait();
        state[id] = s;
        redraw[id] = true;
        repaint();
    }

    public synchronized void freeze(){
        frozen = true;
    }

    public synchronized void thaw() {
        frozen = false;
        notifyAll();
    }

    public synchronized void setChop(int id, boolean taken) {
        untable[id]= !taken;
    }


    public boolean deadlocked(){
        int i=0;
        while(i<NUMPHILS && state[i]==GOTRIGHT) ++i;
        return i==NUMPHILS;
    }


    public void initPlacing() {
        double radius = 105.0;
        double centerAdj = 100.0;
        double radians;

        for (int i = 0; i < NUMPHILS; i++) {
            radians = i*(2.0 * Math.PI /(double)NUMPHILS);
            philX[i] = Math.sin(radians) * radius + centerAdj;
            philY[i] = Math.cos(radians) * radius + centerAdj;
         }

        radius = 35;
        centerAdj = 145;

        for (int i = 0; i < NUMPHILS; i++) {
            radians = i*(2 * Math.PI /(double)NUMPHILS) + Math.PI/5;
            chopX[i] = Math.sin(radians) * radius + centerAdj;
            chopY[i] = Math.cos(radians) * radius + centerAdj;
            untable[i] = true;
         }
    }
}
