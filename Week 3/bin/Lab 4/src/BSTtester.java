import java.util.Scanner;

public class BSTtester {
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
						tree.insert(var);
					
		         	
		             break;
				case "delete":
					int var2=scan.nextInt();
					tree.delete(var2, root);
		         	
		             break;
				case "find":
					int var3=scan.nextInt();
					tree.find(var3, root);
		         	
		             break;
				
				case "preorder":
		         	tree.preorder(root);
		         	System.out.println();
		             break;
				
				
    			
    			
    			
    			
    			}
    			
    			
    			
    			
    			
    		}
    	}
    
    	
    	

    }

