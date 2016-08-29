import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Driver {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String in = sc.nextLine();
		File file = new File(in);
		sc.close();
		
		try {
			
			Scanner f_read = new Scanner(file);
				
			int num_grph = Integer.parseInt(f_read.nextLine());
			int num_nodes, num_edges, start_edge, end_edge, count = 0;
			
			int adj_matrix[][];
			
			for(int i = 0; i < num_grph; i++) {
				num_nodes = Integer.parseInt(f_read.nextLine());
				num_edges = Integer.parseInt(f_read.nextLine());
								
				System.out.println("Graph number: " + (i + 1));
				
				adj_matrix = new int[num_nodes][num_nodes];
				Node[] nodes = new Node[num_nodes];
				
				for(int j = 0; j < num_nodes; j++) {
					nodes[j] = new Node(num_nodes);
				}
				
				nodes[0].setShortest(0);
				nodes[0].setNum_paths(1);
								
				for(int k = 0; k < num_nodes; k++) {
					for(int l = 0; l < num_nodes; l++) {
						adj_matrix[k][l] = 0;
					}
				}
				
				while(count < num_edges) {
					String[] edges = f_read.nextLine().split(" ");
					start_edge = Integer.parseInt(edges[0]);
					end_edge = Integer.parseInt(edges[1]);
					adj_matrix[start_edge - 1][end_edge - 1] = 1;
					count ++;
				}
				
				count = 0;
						
				int m = 0, n = 0;
				while(m < num_nodes) {
					while(n < num_nodes) {
						if(adj_matrix[m][n] == 1) {
							nodes[n].upLongest(nodes[m].getLongest());
							nodes[n].upTotal(nodes[m].getNum_paths());
							nodes[n].upShortest(nodes[m].getShortest());
						}
						n++;
					}
					m++;
					n = m;
				}
				
				System.out.println("Shortest path: " + nodes[num_nodes - 1].getShortest());
				System.out.println("Longest path: " + nodes[num_nodes - 1].getLongest());
				System.out.println("Number of paths: " + nodes[num_nodes - 1].getNum_paths());
				System.out.println("\n");
			}
			f_read.close();
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
