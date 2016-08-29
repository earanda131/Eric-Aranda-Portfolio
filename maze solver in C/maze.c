#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MAZE_SIZE 30

enum Direction { DOWN, RIGHT, UP, LEFT }; //might be useful

//uses right-hand wall following algorithm to solve maze
void mazeSolve( char maze[][MAX_MAZE_SIZE], int *xloc, int *yloc, int *dir, int mazesize)
{
    bool done = false;
    while (!done) {
        
        if (*dir == UP) {
            if (maze[*xloc][*yloc + 1] == '.') {
                *yloc += 1;
                printf("RIGHT\n");
                *dir = RIGHT;
            }
            else if (maze[*xloc - 1][*yloc] == '.') {
                *xloc -= 1;
                printf("UP\n");
                *dir = UP;
            }
            else if (maze[*xloc][*yloc - 1] == '.') {
                *yloc -= 1;
                printf("LEFT\n");
                *dir = LEFT;
            }
            else if (maze[*xloc + 1][*yloc] == '.') {
                *xloc += 1;
                printf("DOWN\n");
                *dir = DOWN;
            }
        }
        
        else if (*dir == LEFT) {
            if (maze[*xloc - 1][*yloc] == '.') {
                *xloc -= 1;
                printf("UP\n");
                *dir = UP;
            }
            else if (maze[*xloc][*yloc - 1] == '.') {
                *yloc -= 1;
                printf("LEFT\n");
                *dir = LEFT;
            }
            else if (maze[*xloc + 1][*yloc] == '.') {
                *xloc += 1;
                printf("DOWN\n");
                *dir = DOWN;
            }
            else if (maze[*xloc][*yloc + 1] == '.') {
                *yloc += 1;
                printf("RIGHT\n");
                *dir = RIGHT;
            }
        }
        
        else if (*dir == DOWN) {
            if (maze[*xloc][*yloc - 1] == '.') {
                *yloc -= 1;
                printf("LEFT\n");
                *dir = LEFT;
            }
            else if (maze[*xloc + 1][*yloc] == '.') {
                *xloc += 1;
                printf("DOWN\n");
                *dir = DOWN;
            }
            else if (maze[*xloc][*yloc + 1] == '.') {
                *yloc += 1;
                printf("RIGHT\n");
                *dir = RIGHT;
            }
            else if (maze[*xloc - 1][*yloc] == '.') {
                *xloc -= 1;
                printf("UP\n");
                *dir = UP;
            }
        }
        
        else if (*dir == RIGHT) {
            if (maze[*xloc + 1][*yloc] == '.') {
                *xloc += 1;
                printf("DOWN\n");
                *dir = DOWN;
            }
            else if (maze[*xloc][*yloc + 1] == '.') {
                *yloc += 1;
                printf("RIGHT\n");
                *dir = RIGHT;
            }
            else if (maze[*xloc - 1][*yloc] == '.') {
                *xloc -= 1;
                printf("UP\n");
                *dir = UP;
            }
            else if (maze[*xloc][*yloc - 1] == '.') {
                *yloc -= 1;
                printf("LEFT\n");
                *dir = LEFT;
            }
        }
        
        if (*xloc == 0 || *xloc == mazesize - 1 || *yloc == 0 || *yloc == mazesize -1) {
            done = true;
        }
    }
}
        


int main( int argc, const char* argv[] ) {
	//checks for the input file name
	if( argc != 2 ) {
		printf("error; no input file name\n");
		return 1;
	}
	
	else if (argc > 2) {
	    printf("error; too many arguments\n");
	    return 1;
	}

	FILE *filePointer;
	filePointer = fopen( argv[1], "r" );

	char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = { 0 };

	int numberOfTestCases = 0;
	fscanf( filePointer, "%d\n", &numberOfTestCases );

	for( int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++ ) {
        int mazeSize = 0;
		fscanf( filePointer, "%d\n", &mazeSize );
		int *xloc, *yloc, *dir;
		int direction;
		dir = &direction;
		
		//reads maze from input to matrix
		for (int i = 0; i < mazeSize; i++) {
			char temp[mazeSize];
			fscanf(filePointer,"%s", temp);
	        for (int j = 0; j < mazeSize; j++) {
				maze[i][j] = temp[j];
		        if(temp[j]=='x') {
		            int xcoord = i;
		            int ycoord = j;
		            xloc = &xcoord;
		            yloc = &ycoord;
		            if (xcoord == 0) {
		                direction = DOWN;
		            }
		            else if(xcoord == mazeSize - 1) {
		                direction = UP;
		            }
		            else if(ycoord == 0) {
		                direction = RIGHT;
		            }
		            else if(ycoord == mazeSize - 1) {
		                direction = LEFT;
		            }
		        }
		    }
		}
		                
		printf( "ENTER\n" );
		
        mazeSolve(maze, xloc, yloc, dir, mazeSize);

		printf( "EXIT\n***\n" );	
	}
	fclose( filePointer );
	return 0;
}
