#include <iostream> 
#include <fstream>   
#include "maze.hpp"
#include "utils.hpp"

int main(int argc, const char *argv[]) {
	if( argc != 2 ) //checks for the input file name
	{
		std::cerr << "Error: no input file name" << std::endl;
		std::cerr << "Usage: ./" << argv[0] << " someinput.txt" << std::endl;
		return 1;
	}

	std::ifstream mazeInputFile ( argv[1] );	// open the input file
	int numberOfMazes = 0;
	mazeInputFile >> numberOfMazes; 			// read the number of mazes

	for (int currentMaze = 0; currentMaze < numberOfMazes; currentMaze++ ) {
		int mazeSize = 0;
		mazeInputFile >> mazeSize;				// read the maze size from the input file

		std::cout << "size = " << mazeSize << std::endl;
		Utils mazeUtils(mazeSize, mazeInputFile); // helper class for testing, output

		if (mazeSize < 10 || mazeSize > 30) {
			std::cerr << "Error: invalid maze size " << mazeSize << " read from " << argv[1] << std::endl;
			std::cerr << "     Maze sizes must be between 10 and 30" << std::endl;
			return 1;
		}

		// Create a new maze object of the given size
		Maze maze(mazeSize);

		// Initialize the maze
		maze.readFromFile(mazeInputFile);
				
		std::cout << "**ENTER**\n" << std::endl;
		do {
			maze.step();
		} while ( ! maze.atExit() );
		std::cout << "**EXIT**\n" << std::endl;
	}
}