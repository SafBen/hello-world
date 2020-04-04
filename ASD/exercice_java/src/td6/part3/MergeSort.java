package td6.part3;

import td5.part2_3.EmptyHeapException;
import td6.SlowInteger;
import td6.TestSort;

import java.util.Arrays;

/**
 * A class for the recursive merge sort algorithm.
 */
public class MergeSort {

    private static final int SIZE = 10;


    /**
     * Sort the array using the recursive merge sort algorithm.
     * This algorithm is not in place and needs an auxiliary array of
     * the same size than the array to sort
     * Complexity: THETA( n.log(n) ) where n is the size of the array
     */
    public static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array) {
        AnyType[] tmp = (AnyType[]) new Comparable[array.length];
        sort(array,tmp,0,array.length - 1);
    }

    /**
     * Sort the array in the range [lo, hi] using the portion [lo, hi]
     * of the auxiliary array tmp
     * Complexity: THETA( n.log(n) ) where n = hi - lo + 1
     */
    private static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array, AnyType[] tmp, int lo, int hi) {
        if (array.length<=1) return;
        int mid = (lo+hi)/2;
        //sort(array,lo,mid);
        //sort(array,mid+1,hi);
        //merge(array,lo,mid,hi);
    }

    /**
     * Merge array[lo, mid] and array[mid+1, hi] into tmp[lo, hi]
     * and copy back the result into array[lo, hi]
     * Precondition: array[lo, mid] and array[mid+1, hi] are sorted
     * Complexity: THETA( n ) where n = hi - lo + 1
     */
    private static <AnyType extends Comparable<AnyType>> void merge(AnyType[] array, AnyType[] tmp, int lo, int mid, int hi) {
        int i=lo;
        int j=mid+1;
        int k=0;
        while (i<=mid && j<=hi){
            if (array[i].compareTo(array[j])<0){
                tmp[k]=array[i];
                i++;
            }
            else{
                tmp[k]=array[j];
                j++;
            }
            k++;
        }
        if (i==mid+1){
            while (j<=hi){
                tmp[k]=array[j];
                j++;
                k++;
            }
        }
        else if (j==hi+1){
            while (i<=mid){
                tmp[k]=array[i];
                i++;
                k++;
            }
        }

        for (int l = lo; l <= hi; l++) {
            array[l]=tmp[l];
        }
    }

    /**
     * Copy the elements from tmp[lo, hi] into array[lo, hi]
     * Complexity: THETA( n ) where n = hi - lo + 1
     */
    private static <AnyType> void transfer(AnyType[] tmp, AnyType[] array, int lo, int hi) {
        for (int i = lo; i <= hi; i++) {
            array[i]=tmp[i];
        }
    }

    @SuppressWarnings("unchecked")
    private static <AnyType> AnyType[] somme(AnyType[] t1, AnyType[] t2) {
        AnyType[] sum = (AnyType[]) new Comparable[t1.length+t2.length];
        for (int i = 0; i < t1.length; i++) {
            sum[i]=t1[i];
        }
        for (int i = 0; i < t2.length; i++) {
            sum[i+t1.length]=t2[i];
        }
        return sum;
    }

    @SuppressWarnings("unchecked")
    private static <AnyType> AnyType[] tab(AnyType[] t, int debut, int fin) {
        AnyType[] array = (AnyType[]) new Comparable[fin - debut];
        for (int i = 0; i < fin-debut; i++) {
            array[i]=t[i+debut];
        }
        return array;
    }

    private static <AnyType extends Comparable<AnyType>> AnyType[] fusion(AnyType[] t1, AnyType[] t2) {
        if (t1.length==0) return t2;
        if (t2.length==0) return t1;
        if (t1[0].compareTo(t2[0]) < 0){
            return somme(tab(t1,0,1),fusion(tab(t1,1,t1.length),t2));
        }
        else return somme(tab(t2,0,1),fusion(t1,tab(t2,1,t2.length)));
    }

    private static <AnyType extends Comparable<AnyType>> AnyType[] trifusion(AnyType[] t) {
        if (t.length<=1) return t;
        AnyType[] t1 = tab(t,0,t.length/2);
        AnyType[] t2 = tab(t,t.length/2,t.length);
        return fusion(trifusion(t1),trifusion(t2));
    }

    public void showArray(SlowInteger[] array) {
        System.out.print("[ " + array[0]);
        for ( int i = 1; i < array.length; i++ )
            System.out.print(", " + array[i]);
        System.out.println("]");
    }

    public void newArray(SlowInteger[] array, SlowInteger[] unsorted) {
        for ( int i = 0; i < array.length; i++ ) {
            array[i] = new SlowInteger(1 + (int) (Math.random() * SIZE*SIZE));
            unsorted[i] = array[i];
        }
    }

    @SuppressWarnings("unchecked")
    public static <Anytype> void main(String[] args) {
        SlowInteger[] array;
        SlowInteger[] unsorted;

        array = new SlowInteger[SIZE];
        unsorted = new SlowInteger[SIZE];


        for ( int i = 0; i < array.length/2; i++ ) {
            array[i] = new SlowInteger(6*i);
        }
        for ( int i = array.length/2; i < array.length; i++ ) {
            array[i] = new SlowInteger(3*i);
        }
        System.out.println(array[1].compareTo(array[3]));
        System.out.println(array[3].compareTo(array[1]));
        System.out.println(Arrays.toString(array));
        System.out.println(Arrays.toString(unsorted));
        merge(array,unsorted,0,array.length/2,array.length-1);
        System.out.println(Arrays.toString(array));
        System.out.println(Arrays.toString(unsorted));

        /*
        MergeSort mergeSort = new MergeSort();
        mergeSort.newArray(array,unsorted);
        mergeSort.showArray(unsorted);

        mergeSort.showArray((SlowInteger[]) trifusion(unsorted));
        mergeSort.showArray(tab(array,0,array.length-1));

         */


    }

}

/*
def fusion(T1,T2) :
if T1==[] :return T2
if T2==[] :return T1
if T1[0]<T2[0] :
return [T1[0]]+fusion(T1[1 :],T2)
else :
return [T2[0]]+fusion(T1,T2[1 :])


def trifusion(T) :
if len(T)<=1 : return T
T1=[T[x] for x in range(len(T)//2)]
T2=[T[x] for x in ange(len(T)//2,len(T))]
return fusion(trifusion(T1),trifusion(T2))
 */