package td6.part2;

import td5.Correction.BinaryHeap;
import td5.part2_3.EmptyHeapException;

/**
 * A class for the heap sort algorithm.
 */
public class HeapSort {

    /**
     * Sort the array in place using the heapsort algorithm
     * Complexity: THETA( n.log(n) ) where n is the size of the array
     */
    public static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array) {
        BinaryHeap<AnyType> binaryHeap = new BinaryHeap<>(array);
        int n = array.length;
        // array = (AnyType[]) new Comparable[array.length];
        for (int i = 0; i < n-1; i++) {
            try{
                array[n-i-1] = binaryHeap.deleteExtreme();
            }
            catch (Exception ignored){

            }
        }
    }
}