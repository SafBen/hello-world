package td6.part4;

/**
 * A class for the quicksort algorithm
 */
public class QuickSort {

    private static final int CUTOFF = 10;

    /**
     * Sort the array in place using the quicksort algorithm
     */
    public static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array) {
        sort(array,0,array.length-1);
    }

    /**
     * Sort the portion array[lo,hi] in place using the quicksort algorithm
     */
    public static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array, int lo, int hi) {
        if (lo < hi) {
            int pi = partition(array, lo, hi);
            sort(array, lo, pi - 1);
            sort(array, pi + 1, hi);
        }
    }

    /**
     * Partition the portion array[lo,hi] and return the index of the pivot
     */
    private static <AnyType extends Comparable<AnyType>> int partition(AnyType[] array, int lo, int hi) {
        int median = median(array,lo,(lo+hi)/2,hi);
        int i = lo;  // Index of smaller element
        for (int j = lo; j <= hi; j++)
        {
            if (array[j].compareTo(array[median]) < 0)
            {
                i++;    // increment index of smaller element
                swap(array, i, j);
            }
        }
        swap(array,i+1,hi);
        return i;
    }

    /**
     * Return the index of the median of { array[lo], array[mid], array[hi] }
     */
    private static <AnyType extends Comparable<AnyType>> int median(AnyType[] array, int lo, int mid, int hi) {
        if (array[lo].compareTo(array[mid])<0){
            // lo<mid
            if (array[lo].compareTo(array[hi])<0){
                // lo<hi
                return (array[mid].compareTo(array[hi])<0) ? mid : hi ;
            }
            else{
                // lo > hi
                return lo;
            }
        }
        else{
            // mid<lo
            if (array[mid].compareTo(array[hi])<0){
                // mid<hi
                return (array[lo].compareTo(array[hi])<0) ? lo : hi ;
            }
            else{
                return mid;
            }
        }
    }

    /**
     * Sort array[lo, hi] in place using the insertion sort algorithm
     */
    private static <AnyType extends Comparable<AnyType>> void insertion(AnyType[] array, int lo, int hi) {

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