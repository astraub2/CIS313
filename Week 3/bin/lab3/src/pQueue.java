public class pQueue<E extends Comparable> {    
	private MinHeap<E> myHeap;

   public pQueue (int s) {        
	   myHeap=new MinHeap<E>(s);
   }
   public void insert(E data){        
	   myHeap.insert(data);    
	   }
   public Comparable<E> findMin(){        
	   System.out.println("Min: "+ myHeap.findMin());
	   return myHeap.findMin();
	   }
   public Comparable<E> removeMin(){         
	   System.out.println("Removed: "+(E) myHeap.findMin());
	   return myHeap.extract();
	   
	   }
   public void isEmpty(){
	   if (myHeap==null)
			   System.out.println("Empty");
	   System.out.println("Not Empty");     
   }
   
   public void print(){        
	   E[] array = myHeap.getArray();
	   System.out.println("Current Queue");
	   for(int i = 0; i<(array.length); i++)
		   if(array[i]!=null)
			   System.out.print(array[i]+",");
	   System.out.println();
   }
   }
