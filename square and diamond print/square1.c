#include <stdio.h>

void print10Square() {
 
	static char a[10][10];
	char c = '0';

	int k,l;
	for(k = 0; k < 10; k++) {
		for(l = 0; l < 10; l++) {
			a[k][l] = (c + l);
			printf("%c ", a[k][l]);
		}
		printf("\n");
	} 
}
