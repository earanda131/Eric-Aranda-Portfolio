
public class Queue {
	
	private int size = 0;
	private charNode head;
	private charNode tail;
	private Object[] base_queue;
	
	public Queue(){
		base_queue = new Object[size];
	}
	
	public boolean isEmpty(){
		if(head == null){
			return true;
		}
		return false;
	}
	
	public void enqueue(char obj){
		charNode node = new charNode();
		node.setData(obj);
		node.setNext(null);
		if(tail != null){
			tail.setNext(node);
		}
		tail = node;
		if(head == null){
			head = tail;
		}
		size++;
	}
	
	public char dequeue() {
		
		char result = 0;
		
		if(head != null){
			result = head.getData();
			head = tail.getNext();
			size--;
		}
		return result;
	}
}
