public class TestContests{
 public static void main(String[] args){
  Scanner scan = new Scanner(System.in);
  Queue<Character> queue = new Queue<Character>();
  Stack<Character> stack = new Stack<Character>();
  input = scan.nextLine();
  for(int i = 0; i < input.length(); ++i){
   queue.enqueue(input[i]);
   stack.push(input[i]);
  }
  stack.printStack();
  queue.printQueue();
 }
}
