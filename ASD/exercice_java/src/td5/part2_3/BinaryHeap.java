package td5.part2_3;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

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
	public BinaryHeap(AnyType[] A) throws FullHeapException {
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
		if (n==0 || isEmpty()) return;
		if (A[right(n)].compareTo(A[n]) < 0){
			if (A[left(n)].compareTo(A[right(n)]) < 0){
				swap(left(n), n);
				percolateDown(left(n));
			}
			else {
				swap(right(n), n);
				percolateDown(right(n));
			}
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
	@SuppressWarnings("unchecked")
	private void buildHeap() throws FullHeapException {
		AnyType[] A = Arrays.copyOf(this.A,size());
		this.A = (AnyType[]) new Comparable[2*size()];
		for (int i = 0; i < size(); i++) {
			add(A[i]);
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
		return null;
	}
	
	/**
	 * Return and delete the extreme element.
	 * Complexity: O(log(size))
	 */
	public AnyType deleteExtreme() throws EmptyHeapException {
		return null;
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
	
	///////////// Part 3: deleting in the heap
	
	/**
	 * Delete the element e from the heap.
	 * Complexity: O(size)
	 */
	public void delete(AnyType e) {

	}
	
	/**
	 * Delete all the elements e from the heap.
	 * Complexity: O(size)
	 */	
	public void deleteAll(AnyType e) {

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

	public static List<Integer> read(String inputString) {
		List<Integer> list = new LinkedList<>();
		String integers[] = inputString.split(", ");
		for (String i : integers) {
			list.add(Integer.parseInt(i));
		}
		return list;
	}

	private static int[] toIntArray(List<Integer> list){
		int[] ret = new int[list.size()];
		for(int i = 0;i < ret.length;i++)
			ret[i] = list.get(i);
		return ret;
	}


	public static void main(String[] args) throws FullHeapException {
		// test du constructeur public BinaryHeap(AnyType[] A)
		List<Integer> tabInt2 = read("10, 12, 1, 14, 6, 5, 8, 3, 9, 7, 4, 11, 13, 2");

		//BinaryHeap<Integer> bh2 = new BinaryHeap<Integer>(tabInt);
		//System.out.println(bh2.toStringAsTab());
	}

}
