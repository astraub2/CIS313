public class Queue<E> {
	private Node<E> head; 
	private Node<E> tail;
	public Queue(){
		head=null;
		tail=null;	
} 
	public void enqueue(E newData){
		Node<E> newNode = new Node<E>(newData, null);
        if (tail == null) {
            tail = newNode;
            head = newNode;
        } else {
        	tail.setNext(newNode);
        	tail=tail.getNext();
        }
	
	}
	public E dequeue(){
		Node<E> temp_node=head;
		if (head == null){
            tail = null;
			return null;
		}
		else{
		head = head.getNext();        
     	
		return temp_node.getData();
		}
	
} 

	public boolean isEmpty(){
		if (head == null)
			return true;
		return false; 
				
	}
	public void printQueue(){
		System.out.println();
		while (head != tail.getNext() )
        {
            System.out.print(head.getData()+" ");
            head = head.getNext();
        }		
	}
}


     