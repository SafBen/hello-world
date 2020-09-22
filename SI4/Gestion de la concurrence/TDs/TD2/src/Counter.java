/**
 * Class to be modified
 */

/**
 * @author riveill
 *
 */
import java.awt.*;
import java.util.concurrent.Semaphore;

public class Counter {
	int value_=0;
	TextCanvas display_;

	Semaphore sample = new Semaphore(1, true);

	Counter(TextCanvas t) {
		display_=t;
		display_.setcolor(Color.cyan);
	}

	// TO DO: modify increment
	/*
	synchronized public void increment() {
		int temp = value_;  //read

		Simulate.interrupt();
		++temp;            //add1
		value_=temp;       //write
		display_.setvalue(value_);
	}
	 */

	public void increment() throws InterruptedException {
		sample.acquire();
		int temp = value_;  //read

		Simulate.interrupt();
		++temp;            //add1
		value_=temp;       //write
		display_.setvalue(value_);
		sample.release();
	}
}
