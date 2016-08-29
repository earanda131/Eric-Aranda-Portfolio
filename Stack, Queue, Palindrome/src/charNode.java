
public class charNode {
	
	private char data;
	private charNode next;

	public charNode(){
		data = 0;
		next = null;
	}
	
	public charNode(char data, charNode next){
		this.data = data;
		this.next = next;
	}

	public char getData() {
		return data;
	}

	public void setData(char data){
		this.data = data;
	}

	public charNode getNext() {
		return next;
	}

	public void setNext(charNode next) {
		this.next = next;
	}
}
