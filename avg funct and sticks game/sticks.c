#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>

int getHumanChoice() {
    /* TODO: Prompt the user "Player 1: How many sticks do you take (1-3)?" and return
       an integer. Check that the value is valid (1, 2, or 3) and print an error if 
       is not, then ask again until a valid number is entered. You can exit the program with
       exit(1); Another acceptable alternative is to keep asking the user to enter a valid 
       number until he or she does.
     */
	int true = 1;
	int num;

	while(true){
		printf("Player 1: How many sticks do you take (1-3)?");
		scanf("%d", &num);
		if(num <= 3){
			break;	
		}else {
			printf("Invalid response, please enter correct amount\n");
			true = 1;
		}
	}
}

int getComputerChoice(int current_sticks) {
    
    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;
    
    if (rand_choice > current_sticks) return current_sticks;

    /* Optionally replace with additional logic for the computer's strategy */
    
    return rand_choice;
}


int main(int argc, char** argv) 
{
    int human, computer, number_sticks;
	int true = 1;
    
    
    srand (time(NULL)); /* for reproducible results, you can call srand(1); */
    
    printf("Welcome to the game of sticks!\n");
    printf("How many sticks are there on the table initially (10-100)? ");
    scanf("%d", &number_sticks);
    
    /* TODO: check that number_sticks is between 10 and 100 (inclusive) and either 
     print an error and exit if invalid value is entered or use a loop to keep 
     inputting number_sticks until a valid value is entered.
     */
	 
	 while(true) {
		 if(number_sticks >= 10 && number_sticks <= 100){
			 break;
		 }else {
			 printf("Input must be between 10 and 100.\n");
			 exit(1);
		 }
	 }
    
    /* TODO: Main game loop:
      While some sticks remain:
        1. Print the current number of sticks, e.g., "There are 2 sticks on the board."
        2. Human: Get number of sticks by calling getHumanChoice and update number_sticks
        3. Computer: get number of sticks by calling getComputerChoice and update number_sticks
        4. Output the computer's choice, e.g., "Computer selects 3."
      After all sticks are gone, output the result of the game, e.g., "You win!" or "You lose!"
     */
	 int human_choice;
	 int comp_choice;
	 
	 while(number_sticks != 0) {
		 printf("\n");
		 printf("There are %d sticks on the board.\n", number_sticks);
		 human_choice = getHumanChoice();
		 number_sticks = number_sticks - human_choice;
		 if(number_sticks == 0){
			 printf("You lose!");
			 break;
		 }
		 
		 printf("\n");
		 printf("There are %d sticks on the board.\n", number_sticks);
		 comp_choice = getComputerChoice(number_sticks);
		 printf("Computer selects %d.\n", comp_choice);
		 number_sticks = number_sticks - comp_choice;
		 if(number_sticks == 0){
			 printf("You win!");
			 break;
		 }
	 }
    
    return 0;
}

