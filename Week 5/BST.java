public class BST<E extends Comparable<E>> {
    private Node<E> root;
    private Node<E> last;
    private E min;

    public BST(){
        root = null;
    }
    public Node<E> getRoot(){
        return root;
    }
    public void insert(E data, Node<E> currentNode){
        Node<E> newNode = new Node<E>(data);
        if(currentNode==null){
            currentNode=newNode;
  
            if(currentNode.getData().compareTo(last.getData())<0){
                currentNode.setParent(last);
                last.setLeftChild(currentNode);
            }
            else if(currentNode.getData().compareTo(last.getData())>0){
                currentNode.setParent(last);
                last.setRightChild(currentNode);
            }
        
        }
        else if (newNode.getData().compareTo(currentNode.getData())==0)
            System.out.println("Duplacate node detected");
        else if(newNode.getData().compareTo(currentNode.getData())<0){
            last=currentNode;
            insert(data, currentNode.getLeftChild());
        }
        
        else if(newNode.getData().compareTo(currentNode.getData())>0){
            last=currentNode;
            insert(data, currentNode.getRightChild());
        }
        }

    public Node<E> find(E data, Node <E> node){
        boolean done = false;
       


        while(!done){
            if (node == null){
                return null;
            }
            if(node.getData().compareTo(data) == 0){
                done = true;
            } else if (node.getData().compareTo(data) > 0){
                node = node.getLeftChild();
            } else if (node.getData().compareTo(data) < 0){
                node = node.getRightChild();
            }
        }
        last=node;
        return node;
    }


    public int isnull(Node<E> test){
        if(test==null)
            return 1;
        return 2;
    }

    public void delete(E data, Node<E>root){
        find(data, root);
        Node<E> deleted = last;
        boolean righty = deleted.getRightChild()==null;
        boolean lefty = deleted.getLeftChild()==null;   
        if(righty && lefty){
            if(deleted.getData().compareTo(deleted.getParent().getData()) <0){
                deleted.getParent().setLeftChild(null);
            }
        else if(deleted.getData().compareTo(deleted.getParent().getData()) >0){
                deleted.getParent().setRightChild(null);
            }
        }
        
        else if(righty || lefty){
            Node<E> parent = deleted.getParent();
            if(righty==true){
                parent.setLeftChild(deleted.getLeftChild());    
            }
            else
                parent.setRightChild(deleted.getRightChild());
                
            }
        else{
            Node<E> right = deleted.getRightChild();
            minValue(right);
            deleted.setData(min);
            
                
            }
                
            
        }
    public void minValue(Node<E> node) {
        if (node.getLeftChild() == null){
              E val = node.getData();
              delete(val, node);
              min=(E) val;
            }
              
        else{
              minValue(node.getLeftChild());
        }
  }
       

    public void traverse(String order, Node<E> top) {
        if (top != null){
            switch (order) {
                case "preorder":
                    preorder(top);

                    break;
                case "inorder":
                    inorder(top);

                    break;
                case "postorder":
                    postorder(top);
                    break;
            }
        }
    }

    void postorder(Node<E> root) {
        if(root == null) return;
        
        postorder( root.getLeftChild());
        postorder( root.getRightChild() ); 
        System.out.print(root.getData());
        
    }

    void inorder(Node<E> root) {
        if(root == null) return;
        
        inorder( root.getLeftChild());
        
        System.out.print( root.getData());
          
        inorder( root.getRightChild() ); 
        
    }

    void preorder(Node<E> root) {
        if(root == null) return;
          
          System.out.print(root.getData());
          
          preorder( root.getLeftChild());
          preorder( root.getRightChild() ); 
                
    }
}




