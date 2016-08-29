#include <stdio.h>
#include <stdlib.h>
#include "square2.h"

/* Allocate a square of size "size" (a 2-D array of char) */
void allocateNumberSquare(const int size, char ***square) {
	int i;
	(*square) = (char **) malloc ( size * sizeof(char *) );
	for(i = 0; i < size; i++) {
		(*square)[i] = (char *) malloc ( size * sizeof(char) );
	} 
} 

/* Initialize the 2-D square array */
void initializeNumberSquare(const int size, char **square) {
	int i, j;
	char k = '0';
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			(square)[i][j] = (k + j);
		}
	} 
} 

/* Print a formatted square */
void printNumberSquare(const int size, char **square) {
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			printf("%c ", square[i][j]);
		}
		printf("\n");
	} 
}

/* Free the memory for the 2-D square array */
void deallocateNumberSquare(const int size, char **square) {
	int i;
	for(i = 0; i < size; ++i) {
		free(square[i]);	
	}
	free(square);
}
