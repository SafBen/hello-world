package td2.Correction.part1;

import td2.part1.EmptyStackException;

/**
 * An array-based stack class
 */
public class ArrayStack<AnyType> {
	
	private static final int DEFAULT_CAPACITY = 32;
	
	private AnyType[] array;
	private int size;
	
	/**
	 * Build an empty stack
	 * Complexity: THETA(1)
	 */
	public ArrayStack() {
		this(DEFAULT_CAPACITY);
	}
	
	/**
	 * Build an empty stack of
	 * a given capacity
	 * Complexity: THETA(1)
	 */
	@SuppressWarnings("unchecked")
	public ArrayStack(int capacity) {
		array = (AnyType[]) new Object[capacity];
		size = 0;
	}
	
	/**
	 * Check if the stack is empty
	 * Complexity: THETA(1)
	 */
	public boolean isEmpty() {
		return size == 0;
	}
	
	/**
	 * Return the number of items
	 * currently in the stack
	 * Complexity: THETA(1)
	 */
	public int size() {
		return size;
	}
	
	/**
	 * Return the next value to be popped from the stack
	 * Throw EmptyStackException if the stack is empty
	 * Complexity: THETA(1)
	 */	
	public AnyType peek() throws EmptyStackException {
		if ( isEmpty() )
			throw new EmptyStackException();
		return array[size-1];
	}
	
	/**
	 * Push the value x onto the stack.
	 * If needed, the underlying array 
	 * will be enlarged by twice its size
	 * Complexity: amortized O(1)
	 */
	@SuppressWarnings("unchecked")
	public void push(AnyType x) {
		if (size == array.length) {
			AnyType[] tmp = array;
			array = (AnyType[]) new Object[2*size];
			for ( int i = 0; i < size; i++ )
				array[i] = tmp[i];
		}
		array[size++] = x;
	}
	
	/**
	 * Pop the stack and return the value popped
	 * Throw EmptyStackException if the stack is empty
	 * Complexity: THETA(1)
	 */
	public AnyType pop() throws EmptyStackException {
		if ( isEmpty() )
			throw new EmptyStackException();
		AnyType x = array[size - 1];
		array[--size] = null; // for garbage-collection
		return x;
	}
	
	/**
	 * Remove all elements in the stack
	 * Complexity: THETA(1) where n is the
	 * size of the stack
	 */
	@SuppressWarnings("unchecked")
	public void clear() {
		array = (AnyType[]) new Object[DEFAULT_CAPACITY];
		size = 0;
	}
	/**
	 * Return a string representation of the stack
	 * in the form of "[ A B C ->" where A is the
	 * bottom and C the top of the stack
	 */
	public String toString() {
		String s = "[ ";
		for ( int i = 0; i < size; i++ )
			s += array[i] + " ";
		return s + "->";
	}


	public static void genPal(int n){
		//TO COMPLETE
		String s = "";
		genPal(s,n);
	}

	private static void genPal(String m, int reste){
		//TO COMPLETE
		if (reste==0)
			System.out.print(m+" ");

		else if (reste%2!=0){
			genPal(m+"0",reste-1);
			genPal(m+"1",reste-1);
			genPal(m+"2",reste-1);
		}

		else if (reste%2==0) {
			genPal("0"+m+"0",reste-2);
			genPal("1"+m+"1",reste-2);
			genPal("2"+m+"2",reste-2);
		}
	}



	public static void genMBP(int n){
		//TO COMPLETE
		genMBP("",0,2*n);
	}

	private static void genMBP(String pref, int aFermer, int reste){
		//TO COMPLETE
		if (reste == 0){
			System.out.print(pref);
		}
		else if (aFermer>0){
			for (; aFermer > 0; aFermer--) {
				pref=pref+")";
				reste--;
			}

		}
		else {
			for (int i = 1; i < reste/2; i++) {
				genMBP(pref+"(",aFermer+i,reste--);
			}
		}
	}

	public static boolean sumWithRep(int[] A, int N){
		if (N==0) return true;
		int sum=0;
		for (int i = 0; i < A.length; i++) {
			while (sum + A[i] <= N) {
				sum = sum + A[i];
			}
			if (N==sum) return true;
			sumWithRep(A,N);
		}
		return false;
	}

    /**
     * A short main for quick testing
     */
	public static void main(String[] args) throws EmptyStackException {
		/*
		ArrayStack<Integer> stack = new ArrayStack<Integer>();
		for ( int i = 1; i <= 100; i++ )
			stack.push(i);
		int i = 0;
		while ( ! stack.isEmpty() ) {
			if ( i++ % 25 == 0 )
				System.out.println();
			System.out.print(stack.pop() + " ");
		}
			
		System.out.println();

		 */
		sumWithRep(new int[]{5,11,3},13);
		//genPal(3);
		//genMBP(3);
	}
	// expected output:
	//
	// 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 
	// 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 
	// 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 
	// 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
}
