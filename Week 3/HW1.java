import java.util.Scanner;

public class HW1 {
public static void main(String[] args){
	
	Scanner scan = new Scanner(System.in); 
    String numProblems = scan.nextLine();   
    for (int j=0; j<Integer.parseInt(numProblems); j++){
      isPalindrome(scan.nextLine());     
    } 
    
    scan.close();
}

 public static boolean isPalindrome(String input){
	Queue<Character> queue = new Queue<Character>();
	Stack<Character> stack = new Stack<Character>();
	for(int j = 0; j < input.length(); j++){
        queue.enqueue(input.charAt(j));
        stack.push(input.charAt(j));             
    }  
	
    for(int k=0; k<input.length(); k++){
     if(queue.dequeue()!=stack.pop()) {
        System.out.println("Not a Palindrome.");
        return false;}
    }
     System.out.println("This is a Palindrome.");
     return true;
	
		
} }