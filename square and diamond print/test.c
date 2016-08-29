#include <stdio.h>
#include "diamond.h"
#include "square2.h"
#include "square1.h"

int main() {
	
	char **square; 
	/* print10Square(); */

	int true = 1;
	int num;
	while(true) {
		printf("Please enter the size of the square [2-10]: ");
		scanf("%d", &num);
		if(num >= 2 && num <= 10) {
			break;
		} 
	}

	allocateNumberSquare((const int) num, &square); 
	initializeNumberSquare((const int) num, square); 
	printNumberSquare((const int) num, square); 
	printNumberDiamond((const int) num, square);
	deallocateNumberSquare((const int) num, square); 

	return 0;
} 
