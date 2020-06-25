package td6.part3;


import td6.part2.HeapSort;

public class TriFusion {
    private static final int SIZE = 2000;

    private static int[] somme(int[] t1, int[] t2) {
        int[] sum = new int[t1.length+t2.length];
        System.arraycopy(t1, 0, sum, 0, t1.length);
        System.arraycopy(t2, 0, sum, t1.length, t2.length);
        return sum;
    }

    private static int[] tab(int[] t, int debut, int fin) {
        int[] array = new int[fin - debut];
        if (fin - debut >= 0) System.arraycopy(t, debut, array, 0, fin - debut);
        return array;
    }

    private static int[] fusion(int[] t1, int[] t2) {
        if (t1.length==0) return t2;
        if (t2.length==0) return t1;
        if (t1[0] < t2[0]){
            return somme(tab(t1,0,1),fusion(tab(t1,1,t1.length),t2));
        }
        else return somme(tab(t2,0,1),fusion(t1,tab(t2,1,t2.length)));
    }

    private static int[] trifusion(int[] t) {
        if (t.length<=1) return t;
        int[] t1 = tab(t,0,t.length/2);
        int[] t2 = tab(t,t.length/2,t.length);
        return fusion(trifusion(t1),trifusion(t2));
    }

    public void showArray(int[] array) {
        System.out.print("[ " + array[0]);
        for ( int i = 1; i < array.length; i++ )
            System.out.print(", " + array[i]);
        System.out.println("]");
    }

    public void newArray(int[] array, int[] unsorted) {
        for ( int i = 0; i < array.length; i++ ) {
            array[i] = (int) (Math.random()*SIZE);
            unsorted[i] = 10*array[i];
        }
    }

    public static void main(String[] args) {
        int[] array;
        int[] unsorted;

        array = new int[SIZE];
        unsorted = new int[SIZE];

        TriFusion tri = new TriFusion();
        tri.newArray(array,unsorted);

        tri.showArray(array);
        long startTime = System.nanoTime();
        int[] fusion = trifusion(array);
        long endTime = System.nanoTime();
        System.out.println("Execution time: " + ((endTime - startTime)/1000000) + " ms");
        tri.showArray(fusion);

    }
}
