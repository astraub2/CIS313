import java.util.Scanner;
public class TestContents{
     public static void main(String[] args){ 
     

      Scanner scan = new Scanner(System.in); 
      TwoStackQueue<Character> queue = new TwoStackQueue<Character>();
      Stack<Character> stack = new Stack<Character>();
      while (scan.hasNext()){
      	String input = scan.nextLine();
        for(int i = 0; i < input.length(); i++){
              queue.enqueue(input.charAt(i));
              stack.push(input.charAt(i));             
          }
          System.out.println("Stack: ");
          stack.printStack();
          System.out.println("Queue: ");
          queue.printQueue();         
      }     
  } 
}