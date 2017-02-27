import java.util.Scanner;

public class HW3 {     
 public static void main(String[] args) {         
	 Scanner scan = new Scanner(System.in);
	 pQueue<Integer> pq = new pQueue<Integer>(10);
	 int n=scan.nextInt();
		for(int i = 0; i < n; i++){
			String command=scan.next();
			switch(command){
			case "insert":
				int var=scan.nextInt();
				pq.insert(var);
	            break;
			case "isEmpty":
				pq.isEmpty();
	         	
	             break;
			case "print":
				pq.print();
	             break;
			case "findMin":
	         	pq.findMin();
	             break;
			case "removeMin":
	         	pq.removeMin();
	             break;
			
			}
			}
		scan.close();
}
      
}