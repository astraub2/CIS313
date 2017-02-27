
public class tester {
	 public static void main(String[] args) {    	
		BST<Integer> tree= new BST<Integer>();
		Node<Integer> root=new Node<Integer>(5);
		
		tree.insert(12,  root);
		tree.insert(9,  root);
		tree.insert(21,  root);
		tree.insert(19,  root);
		tree.insert(25,  root);
		
		
		tree.preorder(root);
		tree.delete(12, root);
		tree.preorder(root);

}
}
