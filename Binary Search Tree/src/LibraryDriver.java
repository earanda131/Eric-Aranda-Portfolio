/*Eric Aranda
CIS 313
Lab 2 Assignment*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class LibraryDriver {

	public static void main(String[] args) throws LibraryException, FileNotFoundException {
		
		String[] results;
		int num_phrases;
	
		BinarySearchTree tree = new BinarySearchTree();
		File file = new File("C:/Users/Eric/Desktop/input2_larger.txt");
		
		Scanner stdin = new Scanner(file);
		
		num_phrases = Integer.parseInt(stdin.nextLine());
		results = new String[num_phrases];
		
		for(int i = 0; i < num_phrases; i++){
			String line = stdin.nextLine();
			String line2 = stdin.nextLine();
			if(line.equals("insert")){
				if(tree.insert(line2)){
					results[i] = "Inserted " + line2 + " into the catalog";
				}
			}
			if(line.equals("find")){
				if(tree.find(line2)){
					results[i] = line2 + " is in the catalog";
				}else{
					results[i] = line2 + " is not in the catalog";
				}
			}
			if(line.equals("remove")){
				if(tree.remove(line2)){
					results[i] = line2 + " was removed from the catalog";
				}else{
					results[i] = line2 + " is not in the catalog";
				}
			}
		}
		
		stdin.close();
				
		for(String s : results){
			System.out.println(s);
		}	
	}
}
