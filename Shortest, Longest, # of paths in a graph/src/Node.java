
public class Node {

	private int shortest;
	private int longest;
	private int num_paths;

	public Node(int nodes){
		this.shortest = nodes;
		this.longest = 0;
		this.num_paths = 0;
	}
	
	public int getShortest() {
		return shortest;
	}
	
	public void setShortest(int n) {
		this.shortest = n;
	}

	public int getLongest() {
		return longest;
	}

	public int getNum_paths() {
		return num_paths;
	}
	
	public void setNum_paths(int n) {
		this.num_paths = n;
	}

	public void upShortest(int n) {
		n++;
		if(n < this.shortest) {
			this.shortest = n;
		}
	}
	
	public void upLongest(int n) {
		n++;
		if(this.longest < n) {
			this.longest = n;
		}
	}
	
	public void upTotal(int n) {
		this.num_paths += n;
	}
}
