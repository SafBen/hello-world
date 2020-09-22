import java.util.concurrent.Semaphore;

/**
 * Class to be modified
 */

public class CarParkControl {
	protected int spaces;
	protected int capacity;
	Semaphore arrival;
	Semaphore departure;



	CarParkControl(int n) {
		capacity = spaces = n;
		arrival = new Semaphore(n,true);
		departure = new Semaphore(0,true);
	}

	// TO DO: modify arrive
	void arrive() throws InterruptedException {
		// to do
		arrival.acquire();
		--spaces;
		departure.release();
		System.out.println(spaces);
	}

	// TO DO: modify arrive
	void depart() throws InterruptedException {
		// to do
		departure.acquire();
		++spaces;
		arrival.release();
		System.out.println(spaces);
	}
}
