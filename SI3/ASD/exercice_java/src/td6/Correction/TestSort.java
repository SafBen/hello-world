package td6.Correction;

import td1.TestClass;

import java.util.Arrays;

/**
 * A class for interactive testing of sorting algorithms
 */
public class TestSort extends TestClass<TestSort> {

	// the size of the array
	private static int SIZE = 8;
	private static SlowInteger[] array;
	private static SlowInteger[] unsorted;
	private static SlowInteger[] sorted;

	/**
	 * Build a TestSort object to test various
	 * sorting methods
	 */
	public TestSort() {
		/*array = new SlowInteger[SIZE];
		unsorted = new SlowInteger[SIZE];
		sorted = new SlowInteger[SIZE];*/
		// set the slowness of the compareTo
		// method on SlowInteger objects
		SlowInteger.setSlowness(1);
		// newArray();
	}

	public void heapsort() {
		long startTime = System.nanoTime();
		HeapSort.sort(array);
		long endTime = System.nanoTime();
		/*if ( Arrays.equals(array,sorted) )
			System.out.println("Sorting completed!");
		else
			System.out.println("Oops, your sort method is wrong!");
		showArrays();*/
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}

	public void mergesort() {
		long startTime = System.nanoTime();
		MergeSort.sort(array);
		long endTime = System.nanoTime();
		/*if ( Arrays.equals(array,sorted) )
			System.out.println("Sorting completed!");
		else
			System.out.println("Oops, your sort method is wrong!");
		showArrays();*/
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}

	public void quicksort() {
		long startTime = System.nanoTime();
		QuickSort.sort(array);
		long endTime = System.nanoTime();
		/*if ( Arrays.equals(array,sorted) )
			System.out.println("Sorting completed!");
		else
			System.out.println("Oops, your sort method is wrong!");
		showArrays();*/
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}

	public void selectionsort() {
		long startTime = System.nanoTime();
		SimpleSorting.selection(array);
		long endTime = System.nanoTime();
		/*if ( Arrays.equals(array,sorted) )
			System.out.println("Sorting completed!");
		else
			System.out.println("Oops, your sort method is wrong!");
		showArrays();*/
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}

	public void insertionsort() {
		long startTime = System.nanoTime();
		SimpleSorting.insertion(array);
		long endTime = System.nanoTime();
		/*if ( Arrays.equals(array,sorted) )
			System.out.println("Sorting completed!");
		else
			System.out.println("Oops, your sort method is wrong!");
		showArrays();*/
		System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
		restoreArray();
	}

	public void showArrays() {
		System.out.println("original array:");
		System.out.println(Arrays.toString(unsorted));
		System.out.println("sorted array:");
		System.out.println(Arrays.toString(sorted));
		System.out.println("your sorted array:");
		System.out.println(Arrays.toString(array));
	}

	public void newArray(int tab[]) {
		for ( int i = 0; i < array.length; i++ ) {
			array[i] = new SlowInteger(tab[i]);
			sorted[i] = unsorted[i] = array[i];
		}
		Arrays.sort(sorted);
	}

	private void restoreArray() {
		for ( int i = 0; i < array.length; i++ ) {
			array[i] = unsorted[i];
		}
	}

    public static void main(String[] args) {
    	TestSort test = new TestSort();
        //test.tester();
		int [] tab = {30, 53, 31, 46, 26, 64, 27};
		SIZE=tab.length;
		array = new SlowInteger[SIZE];
		unsorted = new SlowInteger[SIZE];
		sorted = new SlowInteger[SIZE];
		test.newArray(tab);
		System.out.println("avant "+Arrays.toString(array));
		System.out.println("\nSÉLECTION---------------------------\n");
		test.selectionsort();
		System.out.println("\nINSERTION---------------------------\n");
		test.insertionsort();
		System.out.println("\nQUICKSORT---------------------------\n");
		test.quicksort();
		System.out.println("\nHEAPSORT---------------------------\n");
		test.heapsort();
		System.out.println("\nMERGESORT---------------------------\n");
		test.mergesort();
		System.out.println("\n---------------------------\n");
		System.out.println("après "+Arrays.toString(array));
    }
}
