import java.util.Scanner;

public class HW2 {
    public static void main(String[] args) {    	
    	Scanner scan = new Scanner(System.in);
    	BST<Integer> tree= new BST<Integer>();
    	Node<Integer> root=null;
		int n=scan.nextInt();
		for(int i = 0; i < n; i++){
			String command=scan.next();
			switch(command){
				case "insert":
					int var=scan.nextInt();
					if(root==null)
						root= new Node<Integer>(var);
					else
						tree.insert(var, root);
					
		         	
		             break;
				case "delete":
					int var2=scan.nextInt();
					tree.delete(var2, root);
		         	
		             break;
				case "find":
					int var3=scan.nextInt();
					Node<Integer> x = tree.find(var3, root);
					if(x!=null)
						System.out.println("Found");
		             break;
				case "inorder":
		         	tree.inorder(root);
		         	System.out.println();
		             break;
				case "preorder":
		         	tree.preorder(root);
		         	System.out.println();
		             break;
				case "postorder":
		         	tree.postorder(root);
		         	System.out.println();
		             break;
		         
				
    			
    			
    			
    			
    			}
    			
    			
    			
    			
    			
    		}
    	}
    
    	
    	

    }
