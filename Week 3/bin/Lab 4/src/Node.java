public class Node<E extends Comparable<E>> {
    private E data;
    private Node<E> leftChild;
    private Node<E> rightChild;
    private Node<E> parent;
    private int height;
    private int difference;
    public Node(E d) {
        data = d;
        leftChild = null;
        rightChild = null;
        parent = null;
        height = 1;
    }

    public void setData(E d) {
        data = d;
    }

    public void setLeftChild(Node<E> lc) {
        leftChild = lc;
    }

    public void setRightChild(Node<E> rc) {
        rightChild = rc;
    }

    public void setParent(Node<E> p) {
        parent = p;
    }

    public void setHeight(int h){
        height = h;
    }

    public E getData() {
        return data;
    }

    public Node<E> getLeftChild() {
        return leftChild;
    }

    public Node<E> getRightChild() {
        return rightChild;
    }

    public Node<E> getParent() {
        return parent;
    }

    public int getHeight(){
        return height;
    }
    public int balance(){
    	return difference;
    }

    public boolean isUnbalanced(){
		int lefty = 0, righty=0; int result;
		//System.out.println(data);
		//System.out.println(height);
		
		if (getLeftChild()!=null && getRightChild()!= null){
			lefty=getLeftChild().getHeight();
			righty = getRightChild().getHeight();
			result=righty-lefty;
			if(result==0)
				return false;
			if(result!=1 || result!=-1){
				difference=result;
				return true;
			}
			}
		if (getLeftChild()!=null || getRightChild()!= null)
			if (getLeftChild()!= null){
				lefty=getLeftChild().getHeight();
				if (lefty>1)
					return true;}
			if( getRightChild() !=null){
				righty=getRightChild().getHeight();
				if (righty>1)
					return true;}

		
		
		return false;
    }

}
