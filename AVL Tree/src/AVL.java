
public class AVL {

	AVLNode root;
	
	public AVL(){
		this.root = null;
	}
				
	public boolean insert(AVLNode node, String title) throws LibraryException{
		if(node == null){
			this.root = new AVLNode(title);
			return true;
		}else if(title.compareTo(node.getData()) == 0){
			throw new LibraryException("Book already inserted");
		}else if(title.compareTo(node.getData()) < 0){
			if (node.getLeft_child() == null){
				AVLNode new_node = new AVLNode(title);
				node.setLeft_child(new_node);
				new_node.setParent(node);
				balance(node);
				return true;
			} else {
				return insert(node.getLeft_child(), title);
			}
		}else if(title.compareTo(node.getData()) > 0){
			if(node.getRight_child() == null){
				AVLNode new_node2 = new AVLNode(title);
				node.setRight_child(new_node2);
				new_node2.setParent(node);
				balance(node);
				return true;
			}else{
				return insert(node.getRight_child(), title);
			}
		}
		return false;
	}
	
	public boolean insert(String data) throws LibraryException{
		return insert(root, data);
	}
	
	public boolean find(AVLNode node, String title){
		if(node == null){
			return false;
		}else if(title.equals(node.getData())){
			return true;
		}else if(title.compareTo(node.getData()) < 0){
			return find(node.getLeft_child(), title);
		}else if(title.compareTo(node.getData()) > 0){
			return find(node.getRight_child(), title);
		}else{
			return false;
		}
	}
	
	public boolean find(String data){
		return find(root, data);
	}
	
	public AVLNode remove(AVLNode node, String title){
		if(node == null){
			return node;
		}
		if(node.getLeft_child() == null && node.getRight_child() == null){
			return null;
		}
		if(title.compareTo(node.getData()) == 0){
			if(node.getLeft_child() == null){
				return node.getRight_child();
			}else if(node.getRight_child() == null){
				return node.getLeft_child();
			}else{
				AVLNode temp = node.getRight_child();
				AVLNode temp1 = node.getRight_child();
				while(temp1.getLeft_child() != null){
					temp1 = temp1.getLeft_child();
				temp1.setLeft_child(node.getLeft_child());
				balance(temp.getParent());
				return temp;
				}
			}
		}else if(title.compareTo(node.getData()) < 0){
			node.setLeft_child(remove(node.getLeft_child(), title));
		}else if(title.compareTo(node.getData()) > 0){
			node.setRight_child(remove(node.getRight_child(), title));
		}
		return node;
	}
	
	public boolean remove(String title){
		boolean successful_remove = true;
		remove(root, title);
		return successful_remove;
	}
	
	public AVLNode rotateRight(AVLNode node){
		AVLNode left_child = node.getLeft_child();
		
		left_child.setParent(node.getParent());
		node.setLeft_child(left_child.getRight_child());
		
		if(node.getLeft_child() != null){
			node.getLeft_child().setParent(node);
		}
		
		left_child.setRight_child(node);
		node.setParent(left_child);
		
		if(left_child.getParent() != null){
			if(left_child.getParent().getRight_child() == node){
				left_child.getParent().setRight_child(left_child);
			}else if(left_child.getParent().getLeft_child() == node){
				left_child.getParent().setLeft_child(left_child);
			}
		}
		
		heightFix(node);
		heightFix(left_child);
		heightBalance(node);
		heightBalance(left_child);
		return left_child;
	}
	
	public AVLNode rotateLeft(AVLNode node){
		AVLNode right_child = node.getRight_child();
		
		right_child.setParent(node.getParent());
		node.setRight_child(right_child.getLeft_child());
		
		if(node.getRight_child() != null){
			node.getRight_child().setParent(node);
		}
		
		right_child.setLeft_child(node);
		node.setParent(right_child);
		
		if(right_child.getParent() != null){
			if(right_child.getParent().getRight_child() == node){
				right_child.getParent().setRight_child(right_child);
			}else if(right_child.getParent().getLeft_child() == node){
				right_child.getParent().setLeft_child(right_child);
			}
		}
	
		heightFix(node);
		heightFix(right_child);
		heightBalance(node);
		heightBalance(right_child);
		return right_child;
	}
	
	public void heightFix(AVLNode node){
		if(node != null){
			if(node.getLeft_child() == null && node.getRight_child() == null){
				node.setHeight(1);
			}else if(node.getRight_child() == null){
				node.setHeight(node.getLeft_child().getHeight()+1);
			}else if(node.getLeft_child() == null){
				node.setHeight(node.getRight_child().getHeight()+1);
			}else{
				node.setHeight(1+Math.max(node.getLeft_child().getHeight(), node.getRight_child().getHeight()));
			}
		}
	}
	
	public int heightBalance(AVLNode node){
		if(node == null){
			return -1;
		}else if(node.getLeft_child() == null && node.getRight_child() == null){
			return 1;
		}else if(node.getLeft_child() == null){
			return 0 - node.getRight_child().getHeight();
		}else if(node.getRight_child() == null){
			return node.getLeft_child().getHeight();
		}else{
			return node.getLeft_child().getHeight() - node.getRight_child().getHeight();
		}
	}
	
	public AVLNode balance(AVLNode node){		 
		if(heightBalance(node)== 2){
			if(heightBalance(node.getLeft_child().getLeft_child()) >= heightBalance(node.getLeft_child().getRight_child())){
				node = rotateRight(node);
			}else{
				doubleRotateLeftRight(node);
			}
		}else if(heightBalance(node)== -2){
			if(heightBalance(node.getRight_child().getRight_child()) >= heightBalance(node.getRight_child().getLeft_child())){
				node = rotateLeft(node);
			}else{
				doubleRotateRightLeft(node);
			}
		}
		
		if(node.getParent()!= null){
			balance(node.getParent());
		}else{
			this.root = node;
		}	 
			
		heightFix(node);
		return node;
	}
	
	public AVLNode doubleRotateLeftRight(AVLNode node){
		node.setLeft_child(rotateLeft(node.getLeft_child()));
		return rotateRight(node);
	}
	
	public AVLNode doubleRotateRightLeft(AVLNode node){
		node.setRight_child(rotateRight(node.getRight_child()));
		return rotateLeft(node);
	}
	
	public void print(AVLNode node) {
		if (node != null) {
			String lc; String rc;
			if (node.getLeft_child() != null) {
				lc = node.getLeft_child().getData();
			}
			else {
				lc = "null";
			}
			if (node.getRight_child() != null) {
				rc = node.getRight_child().getData();
			}
			else {
				rc = "null";
			}
			System.out.println(node.getData() + " LC " + lc + " RC " + rc);
			print(node.getLeft_child());
			print(node.getRight_child());
			
		}
	}
}

