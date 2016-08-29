#include <stdio.h>

/* Print a diamond containing the digits 0 - 9 */
void printNumberDiamond(const int size, char **square) {
	
	int blank;
	int even;
	if(size % 2 == 0) 
		even = 1;
	else 
		even = 0;

	if (even) 
		blank = (size / 2) - 1;
	else 
		blank = size / 2;

	int numbers = 1;

	while (blank >= 0) {
		for(int i = 0; i < blank * 2; i++)
			printf(" ");
		
		for (int i = 0; i < numbers; i++)
			printf("%c ", square[0][i]);

		printf("\n");
		numbers +=2;
		blank--;
	} 

	if(!even) {
		blank = 1;
		numbers -= 4;
	}

	else {
		numbers -= 2;
		blank = 0;
	}

	while (blank <= size / 2) {
		for(int i = 0; i < blank * 2; i++)
			printf(" ");

		for(int i = 0; i < numbers; i++)
			printf("%c ", square[0][i]);

		printf("\n");
		numbers -= 2;
		blank++;

	}
}
