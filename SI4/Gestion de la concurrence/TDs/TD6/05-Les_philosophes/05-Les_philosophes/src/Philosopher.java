 class Philosopher extends Thread {

    int identity;
    boolean stopRequested = false;
    PhilCanvas view;
    Diners controller;
    Chopstick left;
    Chopstick right;

    Philosopher(Diners controller, int identity, Chopstick left, Chopstick right) {
        this.controller = controller;
        this.view = controller.display;
        this.identity = identity;
        this.left = left;
        this.right = right;
    }

    public void run() {
        int slider;
        while (!stopRequested) {
             try {
                //thinking
                view.setPhil(identity,PhilCanvas.THINKING);
                slider = controller.slider.getValue();
                if (slider < 2) slider=2;
                sleep(slider*(int)(100*Math.random()));
                //hungry
                view.setPhil(identity,PhilCanvas.HUNGRY);
                right.get();
                 //gotright chopstick
                view.setPhil(identity,PhilCanvas.GOTRIGHT);
                sleep(500);
                left.get();
                //eating
                view.setPhil(identity,PhilCanvas.EATING);
                sleep(slider*(int)(50*Math.random()));
                right.put();
                left.put();
             } catch (java.lang.InterruptedException e) {}
        }
    }


    public void stopRequested() {
        stopRequested = true;
    }
}
