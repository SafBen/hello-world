package td2.Correction.part5;

import td2.Correction.part1.ArrayStack;

import java.util.*;

/**
 * A class to arrange train configuration
 */
public class TrainManagement {
	
	private int[] from; // the initial ordering
	private int[] to;   // the final ordering
	
	/**
	 * Build a TrainManagement object
	 * Preconditions:
	 * 'from' and 'to' have the same size N and are
	 * both permutations of [ 0, 1, 2,..., N-1 ]
	 */
	public TrainManagement(int[] from, int[] to) {
		this.from = from;
		this.to = to;
	}

	/**
	 * Output the basic move commands to transfer
	 * the cars from the 'from' order on track U
	 * to the 'to' order on track S
	 */
	public void arrange() throws EmptyStackException, td2.part1.EmptyStackException {
		ArrayStack<Integer> U = new ArrayStack<Integer>(); // to hold the cars on track U
		ArrayStack<Integer> T = new ArrayStack<Integer>(); // to hold the cars on track T
		ArrayStack<Integer> S = new ArrayStack<Integer>(); // to hold the cars on track S (input data)
		boolean[] inU = new boolean[from.length]; // inU[i] == true <==> car 'i' is in the stack U
		
		for ( int i = from.length - 1; i >= 0; i-- ) {
			U.push(from[i]);
			S.push(to[i]);
			inU[i] = true;
		}

		while ( ! S.isEmpty() ) {
			int i = S.pop();
			if ( inU[i] )
				UtoT(i,U,T,inU);
			else
				TtoU(i,T,U,inU);
			display(T.pop(),"T","S");
		}
	}
	
	/**
	 * Transfer the cars from stack U to stack T
	 * until car 'i' is on top of T
	 * Precondition: car 'i' is in stack U
	 */
	private void UtoT(int i, ArrayStack<Integer> U, ArrayStack<Integer> T, boolean[] inU) throws EmptyStackException, td2.part1.EmptyStackException {
		int j;
		do {
			j = U.pop();
			T.push(j);
			inU[j] = false;
			display(j,"U","T");
		} while ( j != i);
	}
	
	/**
	 * Transfer the cars from stack T to stack U
	 * until car 'i' is on top of T
	 * Precondition: car 'i' is in stack T
	 */
	private void TtoU(int i, ArrayStack<Integer> T, ArrayStack<Integer> U, boolean[] inU) throws EmptyStackException, td2.part1.EmptyStackException {
		int j = T.peek();
		while ( j != i ) {
			U.push(T.pop());
			inU[j] = true;
			display(j,"T","U");
			j = T.peek();
		}
	}

	/**
	 * Display the basic command (message) for moving
	 * the car 'car' from tack 'from' to track 'to'
	 */
	private void display(int car, String from, String to) {
		System.out.println("move car " + car + " from " + from + " to " + to);
	}

	////////////////////////////////////
	
	/**
	 * Checks if the array 'track' is a legal track
	 * i.e. is a permutation of [ 0, 1, 2,..., N-1 ]
	 * where N = track.length
	 */
	private static boolean notApermutation(int[] track) {
		boolean[] check = new boolean[track.length];
		for (int i = 0; i < track.length; i++)
			if ( track[i] < 0 || track[i] >= track.length || check[track[i]] )
				return true;
			else
				check[track[i]] = true;
		return false;
	}
	
	@SuppressWarnings("resource")
	private static int[] readTrack(Scanner input, String prompt) {
		List<Integer> list = new LinkedList<Integer>();
		System.out.print(prompt);
		Scanner scan = new Scanner(input.nextLine());
		while ( scan.hasNextInt() )
			list.add(scan.nextInt());
		return list.stream().mapToInt(i->i).toArray();
	}
	
    /**
     * An interactive main for testing.
     */	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Welcome to the Train arrangement program\n");
		while (true) {
			int[] from = readTrack(keyboard,"\nEnter the 'from' track (just enter to exit): ");
			if ( from.length == 0 )
				break;
			if ( notApermutation(from) ) {
				System.out.println("bad track!");
				continue;
			}
			int[] to = readTrack(keyboard,"Enter the 'to' track: ");
			if ( notApermutation(to) ) {
				System.out.println("bad track!");
				continue;
			}
			if ( from.length != to.length ) {
				System.out.println("the 'from' and 'to' tracks don't have the same size!");
				continue;
			}
			try {
				(new TrainManagement(from,to)).arrange();
			}
			catch (EmptyStackException | td2.part1.EmptyStackException ese) {
				System.out.println("oops! EmptyStackException");
			}
		}
		System.out.println("\nThank you for using the Train arrangement program");
	}
}
