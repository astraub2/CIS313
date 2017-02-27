public class Stack<E> { 
	private Node<E> top;
	public Stack(){
		top=null;
	} 
	public void push(E newData){
		Node<E> newNode=new Node<E>(newData, top);
		top=newNode;
		
	} 
	public E pop(){
		if(top!=null){
		Node<E> tiptop = top;
		top=top.getNext();
		
		return tiptop.getData();
		}
		return null;
	}
	public boolean isEmpty(){
		if(top!=null)
			return false;
		return true;
	
} 
	public void printStack(){
		while(top!=null){
			System.out.print(top.getData()+" ");
			top=top.getNext();
			
		}
		System.out.println();
	
	}
	
}

