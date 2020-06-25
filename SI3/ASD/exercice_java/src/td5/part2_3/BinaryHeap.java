package td5.part2_3;

import java.util.*;

/**
 * A class for binary heap implementation
 */
public class BinaryHeap<AnyType extends Comparable<? super AnyType>> {

	private AnyType[] A; // to store the heap
	private int size;    // the number of elements in the heap
	
	// comparator to choose
	private Comparator<AnyType> c = new Comparator<AnyType>() {
		public int compare(AnyType e1, AnyType e2) {
			return e1.compareTo(e2);
		}
	};
	
	///////////// Constructors
	
	/**
	 * Build a heap of capacity n.
	 * The elements are ordered according to the
	 * natural order on AnyType.
	 * The heap is empty.
	 * Complexity: THETA(1)
	 */
	@SuppressWarnings("unchecked")
	public BinaryHeap(int n) {
		A = (AnyType[]) new Comparable[n];
	}
	
	/**
	 * Build a heap of capacity n.
	 * The elements are ordered according to c.
	 * The heap is empty.
	 * Complexity: THETA(1)
	 */
	@SuppressWarnings("unchecked")
	public BinaryHeap(int n, Comparator<AnyType> c) {
		A = (AnyType[]) new Comparable[n];
	}
	
	/**
	 * Build a heap based on array A.
	 * The elements are ordered according to the
	 * natural order on AnyType.
	 * The heap is full
	 */
	public BinaryHeap(AnyType[] A) {
		this.A = A;
		size = A.length;
		buildHeap();
	}

	/**
	 * Build a heap based on array A.
	 * The elements are ordered according to c.
	 * The heap is full
	 */
	public BinaryHeap(AnyType[] A, Comparator<AnyType> c) {
		this.A = A;
		size = A.length;
		buildHeap();
	}

	///////////// Private methods
	
	/**
	 * Swap values in the array
	 * at indexes i and j.
	 * Complexity: THETA(1)
	 */
	private void swap(int i, int j) {
		AnyType tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
	 
	/**
	 * Return the number of the left
	 * node of node number n.
	 * Complexity: THETA(1)
	 */
	private int left(int n) {
		return 2*n + 1;
	}
	
	/**
	 * Return the number of the right
	 * node of node number n.
	 * Complexity: THETA(1)
	 */
	private int right(int n) {
		return 2*(n + 1);
	}
	
	/**
	 * Return the number of the parent
	 * node of node number n.
	 * Complexity: THETA(1)
	 */
	private int parent(int n) {
		return (n - 1)/2;
	}
	
	/**
	 * Percolate down the element à node number n
	 * Complexity: O(log(size))
	 */
	private void percolateDown(int n) {
		while (n<size){
			int m1=(left(n)<size && c.compare( A[n],A[left(n)])>0 )?left(n):n;
			int min=(right(n)<size && c.compare(A[m1],A[right(n)])>0)?right(n):m1;
			if (min==n){ break;}
			swap(min,n);
			n=min;
		}
	}
		
	/**
	 * Percolate up the element à node number n
	 * Complexity: O(log(size))
	 */
	private void percolateUp(int n) {
		if (n==0 || isEmpty()) return;
		if (A[parent(n)].compareTo(A[n]) > 0){
			swap(parent(n),n);
			percolateUp(parent(n));
		}
	}
	
	/**
	 * Arrange the elements in A such
	 * that it has the heap property.
	 * Complexity: O(size)
	 */
	private void buildHeap() {
		for (int i=parent(size-1); i>=0; i--) {
			percolateDown(i);
		}
	}
	
	///////////// Public methods
	
	/**
	 * Return the size of the heap
	 * (the number of elements in the heap).
	 * Complexity: THETA(1)
	 */
	public int size() {
		return size;
	}
	
	/**
	 * Check if the heap is empty.
	 * Complexity: THETA(1)
	 */
	public boolean isEmpty() {
		return size==0;
	}
	
	/**
	 * Return the extreme element.
	 * Complexity: THETA(1)
	 */
	public AnyType extreme() throws EmptyHeapException {
		if (isEmpty()){
			throw new EmptyHeapException();
		}
		return A[0];
	}
	
	/**
	 * Return and delete the extreme element.
	 * Complexity: O(log(size))
	 */
	public AnyType deleteExtreme() throws EmptyHeapException {
		if (isEmpty()){
			throw new EmptyHeapException();
		}
		AnyType tmp = A[0];
		swap(0,size-1);
		size--;
		percolateDown(size);
		buildHeap();
		return tmp;
	}
	
	/**
	 * Add a new element in the heap
	 * Complexity: O(log(size))
	 */
	public void add(AnyType e) throws FullHeapException {
		if (size==A.length){
			throw new FullHeapException();
		}
		A[size]=e;
		percolateUp(size);
		size++;
	}

	public void add2(AnyType e) throws FullHeapException {
		if (size==A.length){
			throw new FullHeapException();
		}
		A[size]=e;
		//percolateUp(size);
		size++;
	}
	
	///////////// Part 3: deleting in the heap
	
	/**
	 * Delete the element e from the heap.
	 * Complexity: O(size)
	 */
	public void delete(AnyType e) throws EmptyHeapException {
		if (isEmpty()){
			return;
		}
		int index=0;

		while (index<(size-1) && A[index].compareTo(e)!=0){
			index++;
		}
		if (index==size-1) return;

		//System.out.println(A[size+1]);
		swap(index,size-1);
		size--;
		percolateDown(index+1);
		buildHeap();
		//return tmp;
	}
	
	/**
	 * Delete all the elements e from the heap.
	 * Complexity: O(size)
	 */
	public void deleteAll(AnyType e) {
		int i = 0;
		while (i < size) {
			if (A[i] == e)
				swap(i, --size); // start
			i++;
		}
		buildHeap();
	}

	public String toStringAsTab() {
		if (size == 0) return "[]";
		String res = "[";
		int i = 0;
		while (i< size) {
			res = res +A[i]+", ";
			i++;
		}
		return res.substring(0,res.length()-2)+"]";
	}

	private static List<Integer> read(String inputString) {
		List<Integer> list = new LinkedList<Integer>();
		Scanner input = new Scanner(inputString).useDelimiter("\\,\\s*");
		while ( input.hasNextInt() )
			list.add(input.nextInt());
		input.close();
		return list;
	}


	public static void main(String[] args) throws FullHeapException, EmptyHeapException {
		// test du constructeur public BinaryHeap(AnyType[] A)

		//BinaryHeap<Integer> bh2 = new BinaryHeap<Integer>(tabInt);
		//System.out.println(bh2.toStringAsTab());


		String input = "10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2";
		List<Integer> list = BinaryHeap.read(input);
		BinaryHeap<Integer> bh = new BinaryHeap<>(30);
		BinaryHeap<Integer> bh2 = new BinaryHeap<>(30);
		for (Integer n : list) {
			bh.add(n);
			bh2.add2(n);
		}

		System.out.println(bh.toStringAsTab());
		bh.delete(100);
		System.out.println(bh.toStringAsTab());

	}
	// [1, 3, 2, 12, 6, 4, 8, 15, 14, 9, 7, 5, 11, 13, 10]

}
