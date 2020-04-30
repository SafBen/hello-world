package td3.part1_2;

//import td7.util.TestClass;
import td1.TestClass;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * A class for interactive testing binary nodes
 */
public class TestBinaryNode extends TestClass<TestBinaryNode> {

	private BinaryNode<String> tree;
	private BinaryNode<String> tree1;
	private Scanner input;
	List<BinaryNode> binaryNodeList = new ArrayList<>();
	
	public TestBinaryNode() {
		tree1 = BinaryNode.read("A$");
		tree = BinaryNode.read("A B D X 1 10$ 20$ $ Y$ E V$ W$ C F$ G$");
		BinaryNode<String> t0 = BinaryNode.read("A B D X 1 10$ 20$ $ Y$ E V$ W$ C F$ G$");
		BinaryNode<String> t1 = BinaryNode.read("A B D X 1 10$ 20$ $ Y$  ");
		BinaryNode<String> t2 = BinaryNode.read("A$");
		BinaryNode<String> t3 = BinaryNode.read("A B$ $  ");
		BinaryNode<String> t4 = BinaryNode.read("A B$ C$  ");
		BinaryNode<String> t5 = BinaryNode.read("A B$ C D$ E$  ");
		BinaryNode<String> t6 = BinaryNode.read("A B$ $  ");
		BinaryNode<String> t7 = BinaryNode.read("A B D X 1 10$ 20$ $ Y$ E V$ W$ C F F1$ F2$ G G1$ G2$");
		BinaryNode<String> t8 = BinaryNode.read("A B D X$ Y$ E V$ W$ C F F1$ F2$ G G1$ G2$");
		BinaryNode<String> t9 = BinaryNode.read("A B D X$ $ E V$ W$ C F $ F2$ G G1$ G2$");
		BinaryNode<String> t10 = BinaryNode.read("A B D X$ $ E V$ W$ C F F2$ $ G G1$ G2$");
		BinaryNode<String> t11 = BinaryNode.read("A B D X 1 10$ 20$ $ Y$ E V$ W$ C F$ G$");


		binaryNodeList.add(t0);
		binaryNodeList.add(t1);
		binaryNodeList.add(t2);
		binaryNodeList.add(t3);
		binaryNodeList.add(t4);
		binaryNodeList.add(t5);
		binaryNodeList.add(t6);
		binaryNodeList.add(t7);
		binaryNodeList.add(t8);
		binaryNodeList.add(t9);
		binaryNodeList.add(t10);
		binaryNodeList.add(t11);

		input = new Scanner(System.in);
	}
	
	public void readTree() {
		System.out.print("enter the tree in linear form: ");
		String linear = input.nextLine();
		tree = BinaryNode.read(linear);
	}
	
	public void showTree() {
		tree.display();
	}
	
	public void height() {
		System.out.println(tree.height());
	}
	
	public void lowness() {
		System.out.println(tree.lowness());
	}
	
	public void size() {
		System.out.println(tree.size());
	}
	
	public void leaves() {
		System.out.println(tree.leaves());
	}

	public void isomorphic() {
		System.out.println(tree.isomorphic(tree1));
	}
	
	public void balanced1() {
		if ( tree.balanced1() )
			System.out.println("the tree is balanced");
		else
			System.out.println("the tree is not balanced");
	}		
	
	public void balanced2() {
		if ( tree.balanced2() )
			System.out.println("the tree is balanced");
		else
			System.out.println("the tree is not balanced");
	}		
	
	public void shapely1() {
		if ( tree.shapely1() )
			System.out.println("the tree is shapely");
		else
			System.out.println("the tree is not shapely");
	}		
	
	public void shapely2() {
		if ( tree.shapely2() )
			System.out.println("the tree is shapely");
		else
			System.out.println("the tree is not shapely");
	}		
	
    public static void main(String[] args) {
    	TestBinaryNode test = new TestBinaryNode();
        //test.tester();

		for (int i = 0; i < 11; i++) {
			System.out.println(test.binaryNodeList.get(i).leaves());
		}
    }
}
