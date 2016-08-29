
public class AVLNode {
	
	private String data;
	private AVLNode left_child;
	private AVLNode right_child;
	private AVLNode parent;
	private int height;
	
	public AVLNode(String data){
		this.data = data;
		this.left_child = null;
		this.right_child = null;
		this.parent = null;
		this.height = 1;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public AVLNode getLeft_child() {
		return left_child;
	}

	public void setLeft_child(AVLNode left_child) {
		this.left_child = left_child;
	}

	public AVLNode getRight_child() {
		return right_child;
	}

	public void setRight_child(AVLNode right_child) {
		this.right_child = right_child;
	}

	public AVLNode getParent() {
		return parent;
	}

	public void setParent(AVLNode parent) {
		this.parent = parent;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

}
