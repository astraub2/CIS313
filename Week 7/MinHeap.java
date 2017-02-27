import java.util.Arrays;
public class MinHeap<E extends Comparable> {     
    private E[] myArray;     
    private int maxSize;     
    private int length;

    public MinHeap(int s){ 
        myArray = (E[])new Comparable[s];  
        length = 0;  
    }
    public E[] getArray(){         
        return myArray;    
        }
    public void setArray(E[] newArray){         
        myArray = newArray;     
        }
    public int getMaxSize(){         
        return maxSize;     
        }
    public void setMaxSize(int ms){         
        maxSize = ms;     
        }
    public int getLength(){         
        return length;     
        }
    public void setLength(int l){         
        length = l;     
        }

   
    public void insert(E data){        
        if (length >= myArray.length - 1) {
            myArray = this.resize();
        }        
        length++;
        int index = length;
        myArray[index] = data;
        
        bubbleUp();    
    }
    private void bubbleUp() {
        int index = length;
        
        while (hasParent(index)
                && (parent(index).compareTo(myArray[index]) > 0)) {
            // swap parent and child
            swap(index, parentIndex(index));
            index = parentIndex(index);
        }
        
    }
    public E remove() {
        E thing = peek();
        myArray[1] = myArray[length];
        myArray[length] = null;
        length--;
        bubbleDown();
        return thing;
    }
    protected void bubbleDown() {
        int index = 1;
        while (hasLeftChild(index)) {
            int smallerChild = leftIndex(index);
            if (hasRightChild(index)
                && myArray[leftIndex(index)].compareTo(myArray[rightIndex(index)]) > 0) {
                smallerChild = rightIndex(index);
            } 
            
            if (myArray[index].compareTo(myArray[smallerChild]) > 0) {
                swap(index, smallerChild);
            } else {
                break;
            }
            index = smallerChild;
        }        
    }
    
    
    public E peek() {
        if (length==0) {
            throw new IllegalStateException();
        }
        
        return myArray[1];
    }
    private boolean hasParent(int index) {
            return index > 1;
    }
    protected E parent(int i) {
        return myArray[parentIndex(i)];
    }
    protected int parentIndex(int i) {
            return i / 2;
        }
    protected int leftIndex(int i) {
        return i * 2;
    }
    
    
    protected int rightIndex(int i) {
        return i * 2 + 1;
    }
    
    
    protected boolean hasLeftChild(int i) {
        return leftIndex(i) <= length;
    }
    
    
    protected boolean hasRightChild(int i) {
        return rightIndex(i) <= length;
    }
    protected void swap(int index1, int index2) {
        E tmp = myArray[index1];
        myArray[index1] = myArray[index2];
        myArray[index2] = tmp;        
    }
    private E[] resize() {
        return Arrays.copyOf(myArray, myArray.length * 2);
    }
    
    public Comparable<E> findMin(){         
        
        if(myArray.length!=0)
            return myArray[1];
        return null;
    }
    public Comparable<E> extract(){
        Comparable<E> x = findMin();
        remove();
        return x;
        } 
}
    
    