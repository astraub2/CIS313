public class TwoStackQueue<E> {
	private Stack<E> input; 
	private Stack<E> output;
	public TwoStackQueue(){
		input=new Stack<E>();
		output=new Stack<E>();
} 
	public void enqueue(E newData){
		input.push(newData);
	}
	
	public E dequeue(){
		while(!input.isEmpty()){
			output.push(input.pop());
		}
		E temp = null;
		if(!output.isEmpty())
			temp=output.pop();
		
		return temp;
			
	}
	
	public boolean isEmpty(){
		if (input == null)
			return true;
		return false; 
				
	}
	public void printQueue(){
		while(!input.isEmpty()){
			output.push(input.pop());
		}
		output.printStack();
	}

}
