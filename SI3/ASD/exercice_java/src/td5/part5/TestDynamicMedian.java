package td5.part5;

import td1.TestClass;
import td5.part2_3.EmptyHeapException;
import td5.part2_3.FullHeapException;

import java.util.Scanner;

/**
 * A class for interactive testing of dynamic median finding
 */
public class TestDynamicMedian extends TestClass<TestDynamicMedian> {

	private DynamicMedian<Integer> median;
	private Scanner input;
	
	public TestDynamicMedian() {
		median = new DynamicMedian<Integer>(128);
		input = new Scanner(System.in);
	}
	
	public void add() throws EmptyHeapException, FullHeapException {
		System.out.print("Enter an integer: ");
		int x = input.nextInt();
		median.add(x);
	}
	
	public void findMedian() throws EmptyHeapException {
		System.out.println(median.findMedian());
	}
	
	public void deleteMedian() throws EmptyHeapException, FullHeapException {
		System.out.println(median.deleteMedian());
	}
	
    public static void main(String[] args) {
    	TestDynamicMedian test = new TestDynamicMedian();
        test.tester();
    }
}
