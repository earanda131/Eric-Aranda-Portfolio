
public class BinarySearchTree{
	
	BSTNode root;
	
	public BinarySearchTree(){
		this.root = new BSTNode("zzz");
	}
				
	public boolean insert(BSTNode node, String title) throws LibraryException{
		if(node.getData().compareTo(title) == 0){
			throw new LibraryException("Book already inserted");
		}else if(node.getData().compareTo(title) < 0){
			if (node.getLeft_child() == null){
				BSTNode new_node = new BSTNode(title);
				node.setLeft_child(new_node);
				new_node.setParent(node);
				return true;
			} else {
				return insert(node.getLeft_child(), title);
			}
		}else if(node.getData().compareTo(title) > 0){
			if(node.getRight_child() == null){
				BSTNode new_node2 = new BSTNode(title);
				node.setRight_child(new_node2);
				new_node2.setParent(node);
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
	
	public boolean find(BSTNode node, String title){
		if(node == null){
			return false;
		}else if(node.getData().equals(title)){
			return true;
		}else if(node.getData().compareTo(title) < 0){
			return find(node.getLeft_child(), title);
		}else if(node.getData().compareTo(title) > 0){
			return find(node.getRight_child(), title);
		}else{
			return false;
		}
	}
	
	public boolean find(String data){
		return find(root, data);
	}
	
	public BSTNode remove(BSTNode node, String title){
		if(node == null){
			return node;
		}
		if(node.getLeft_child() == null && node.getRight_child() == null){
			return null;
		}
		if(node.getData().compareTo(title) == 0){
			if(node.getLeft_child() == null){
				return node.getRight_child();
			}else if(node.getRight_child() == null){
				return node.getLeft_child();
			}else{
				BSTNode temp = node.getRight_child();
				BSTNode temp1 = node.getRight_child();
				while(temp1.getLeft_child() != null){
					temp1 = temp1.getLeft_child();
				temp1.setLeft_child(node.getLeft_child());
				return temp;
				}
			}
		}else if(node.getData().compareTo(title) < 0){
			node.setLeft_child(remove(node.getLeft_child(), title));
		}else if(node.getData().compareTo(title) > 0){
			node.setRight_child(remove(node.getRight_child(), title));
		}
		return node;
	}
	
	public boolean remove(String title){
		boolean successful_remove = true;
		remove(root, title);
		return successful_remove;
	}
}

