/*Eric Aranda
CIS 313
Lab1 Assignment*/

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class PalindromeDriver {

    /* Main method: reads input and calls palindrome test, prints results */
    public static void main(String[] args) throws IOException
    {
        String[] results;
        int num_phrases = 0;
        String line;
        
        File file = new File("C:/Users/Eric/Desktop/input1.txt");
        Scanner stdin = new Scanner(file);
        
        FileWriter output = new FileWriter("stdout.txt");
        BufferedWriter out = new BufferedWriter(output);
        
        num_phrases = Integer.parseInt(stdin.nextLine());
        results = new String[num_phrases];
        
        for(int i = 0; i < num_phrases; ++i){
        	line = stdin.nextLine().toUpperCase();
        	if(is_palindrome(line)){
        		results[i] = "Palindrome";
        	}else{
        		results[i] = "Not a palindrome";
        	}
        }
       
        for(String s : results){
        	out.write(s);
        	out.newLine();
        	}
        out.close();
        stdin.close();
        }
        
    public static boolean is_palindrome(String input) {
    	
    	Stack stack = new Stack();
    	Queue queue = new Queue();
    	Character letter;
    	
    	for(int i = 0; i < input.length(); i++){
    		letter = input.charAt(i);
    		if(Character.isLetter(letter)){
    			stack.push(letter);
    			queue.enqueue(letter);
    		}
    	}
    	
    	while(!queue.isEmpty() && !stack.isEmpty()){
    		if(queue.dequeue() !=  stack.pop()){
    			return false;
    		}
    	}
		return true;
    }
}
