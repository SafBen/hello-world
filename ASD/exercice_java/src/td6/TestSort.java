package td6;

import td1.TestClass;
import td5.part2_3.EmptyHeapException;
import td6.part1.SimpleSorting;
import td6.part2.HeapSort;
import td6.part3.MergeSort;
import td6.part4.QuickSort;

/**
 * A class for interactive testing of sorting algorithms
 */
public class TestSort extends TestClass<TestSort> {
	
	// the size of the array
	private static final int SIZE = 30;
	private SlowInteger[] array;
	private SlowInteger[] unsorted;
	
	/**
	 * Build a TestSort object to test various
	 * sorting methods
	 */
	public TestSort() {
		array = new SlowInteger[SIZE];
		unsorted = new SlowInteger[SIZE];
		// set the slowness of the compareTo
		// method on SlowInteger objects
		SlowInteger.setSlowness(1);
		newArray();
	}
	
	public void heapsort() throws EmptyHeapException {
		long startTime = System.nanoTime();
		HeapSort.sort(array);
		long endTime = System.nanoTime();
		showArray();
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}
	
	public void mergesort() {
		long startTime = System.nanoTime();
		MergeSort.sort(array);
		long endTime = System.nanoTime();
		showArray();
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}
	
	public void quicksort() {
		long startTime = System.nanoTime();
		QuickSort.sort(array);
		long endTime = System.nanoTime();
		showArray();
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}
	
	public void selectionsort() {
		long startTime = System.nanoTime();
		SimpleSorting.selection(array);
		long endTime = System.nanoTime();
		showArray();
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}
	
	public void insertionsort() {
		showArray();
		long startTime = System.nanoTime();
		SimpleSorting.insertion(array);
		long endTime = System.nanoTime();
		showArray();
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}

	
	public void showArray() {
		System.out.print("[ " + array[0]);
		for ( int i = 1; i < array.length; i++ )
			System.out.print(", " + array[i]);
		System.out.println("]");
	}
	
	public void newArray() {
		for ( int i = 0; i < array.length; i++ ) {
			array[i] = new SlowInteger(1 + (int) (Math.random() * SIZE));
			unsorted[i] = array[i];
		}
	}
	
	private void restoreArray() {
		for ( int i = 0; i < array.length; i++ ) {
			array[i] = unsorted[i];
		}
	}
	
    public static void main(String[] args) throws EmptyHeapException {
    	TestSort test = new TestSort();
        //test.tester();
		test.mergesort();
    }
}
