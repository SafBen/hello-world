package td6.part1;

/**
 * A class for simple sorting methods
 */
public class SimpleSorting {

	/**
	 * Sort the array in place using the selection sort algorithm
	 */
	public static <AnyType extends Comparable<AnyType>> void selection(AnyType[] array) {
		for (int i = 0; i < array.length; i++) {
			int n = findMin(array,i);
			if ( n != i)
				swap(array,i,n);
		}
	}

	private static <AnyType extends Comparable<AnyType>> int findMin(AnyType[] array, int current){
		int imin=current;
		AnyType min=array[current];
		for (int i = current; i < array.length; i++) {
			if (array[i].compareTo(min)<0){
				imin=i;
				min=array[i];
			}
		}
		return imin;
	}
	
	/**
	 * Sort the array in place using the insertion sort algorithm
	 */
	public static <AnyType extends Comparable<AnyType>> void insertion(AnyType[] array) {
		int j;
		for (int i = 1; i < array.length; i++) {
			AnyType index = array[i];
			j=i-1;
			while (j>=0 && index.compareTo(array[j]) <0){
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = index;
		}
	}
	
	/**
	 * Swap array[i] and array[j]
	 */
	private static <AnyType> void swap(AnyType[] array, int i, int j) {
		AnyType tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
