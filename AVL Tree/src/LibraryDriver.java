/*Eric Aranda
CIS 313
Lab 3 Assignment*/

import java.util.Scanner;


public class LibraryDriver {

	public static void main(String[] args) throws LibraryException{
		
		String[] results;
		int num_phrases;
	
		AVL tree = new AVL();		
		Scanner stdin = new Scanner(System.in);
		
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
