
public class Stack {

	private static int size = 0;
	private Object[] base_stack;
	private charNode top = null;
	
	public Stack() {
		base_stack = new Object[size];
	}
	
	public void push(char obj) {
		charNode node = new charNode(obj, null);
		if(top == null){
			top = node;
		}else{
			node.setNext(node);
			top = node;
		}
		size++;
	}
	
	public char pop(){
		
		char result = 0;
		
		if(top != null){
			result = top.getData();
			top = top.getNext();
			size--;
		}
		return result;
		
	}
	
	public boolean isEmpty(){
		if(top == null){
			return true;
		}
		return false;
	}
}
