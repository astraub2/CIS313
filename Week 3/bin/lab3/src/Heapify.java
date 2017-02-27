
public class Heapify {
	public static void main(String[] args) { 
		Integer[] input_array = new Integer[5];
		input_array[0]=1;
		input_array[1]=12;
		input_array[2]=13;
		input_array[3]=6;
		input_array[4]=1;
		
		pQueue<Integer> pq = new pQueue<Integer>(input_array.length);
				
		for(int i = 0; i<(input_array.length); i++){
			//pq.minHeapify(input_array[i]);
		}
		pq.print();
			
	}

}
