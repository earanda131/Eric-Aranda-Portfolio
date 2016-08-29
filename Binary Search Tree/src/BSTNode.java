
public class BSTNode{

		private String data;
		private BSTNode left_child;
		private BSTNode right_child;
		private BSTNode parent;
		
		public BSTNode(String data){
			this.data =data;
			left_child = null;
			right_child = null;
			parent = null;
		}

		public String getData() {
			return data;
		}

		public void setData(String data) {
			this.data = data;
		}

		public BSTNode getLeft_child() {
			return left_child;
		}

		public void setLeft_child(BSTNode left_child) {
			this.left_child = left_child;
		}

		public BSTNode getRight_child() {
			return right_child;
		}

		public void setRight_child(BSTNode right_child) {
			this.right_child = right_child;
		}

		public BSTNode getParent() {
			return parent;
		}

		public void setParent(BSTNode parent) {
			this.parent = parent;
		}
}
