#include <fstream>
#include <string>
#include <iostream>
#include "maze.hpp"

Maze::Maze(int size) {
	this->size = size;
	this->xcoord = 0;
	this->ycoord = 0;
	this->direction = 0;
	
	this->maze = new char*[this->size];
	for(int i = 0; i < this->size; i++) {
		this->maze[i] = new char[this->size];
		for(int j = 0; j < this->size; j++) {
			this->maze[i][j] = '.';
		}
	}
}

Maze::~Maze() {
	for(int i = 0; i < this->size; i++) {
		delete []this->maze[i];
	}
	delete []this->maze;
}

void Maze::readFromFile(std::ifstream &f) {
	std::string line;
	
	for(int i = 0; i < this->size; i++) {
		f >> line;
		for(int j = 0; j < this->size; j++) {
			this->maze[i][j] = line[j];
			if(this->maze[i][j] == 'x') {
				this->xcoord = i;
				this->ycoord = j;
				if (this->xcoord == 0) {
					this->direction = DOWN;
				}
				else if(this->xcoord == this->size - 1) {
		            this->direction = UP;
		        }
		        else if(this->ycoord == 0) {
		            this->direction = RIGHT;
		        }
		        else if(this->ycoord == this->size - 1) {
		            this->direction = LEFT;
		        }
			}
			std::cout << line[j];
		}
		std::cout << "" << std::endl;
	}
}

void Maze::step() {
	if (this->direction == UP) {
        if (this->maze[this->xcoord][this->ycoord + 1] == '.') {
            this->ycoord += 1;
			std::cout << "RIGHT\n" << std::endl;
            this->direction = RIGHT;
        }
        else if (this->maze[this->xcoord - 1][this->ycoord] == '.') {
            this->xcoord -= 1;
			std::cout << "UP\n" << std::endl;
            this->direction = UP;
        }
        else if (this->maze[this->xcoord][this->ycoord - 1] == '.') {
            this->ycoord -= 1;
			std::cout << "LEFT\n" << std::endl;
            this->direction = LEFT;
        }
        else if (this->maze[this->xcoord + 1][this->ycoord] == '.') {
            this->xcoord += 1;
			std::cout << "DOWN\n" << std::endl;
            this->direction = DOWN;
        }
    }
        
    else if (this->direction == LEFT) {
        if (this->maze[this->xcoord - 1][this->ycoord] == '.') {
            this->xcoord -= 1;
			std::cout << "UP\n" << std::endl;
            this->direction = UP;
        }
        else if (this->maze[this->xcoord][this->ycoord - 1] == '.') {
            this->ycoord -= 1;
			std::cout << "LEFT\n" << std::endl;
            this->direction = LEFT;
        }
        else if (this->maze[this->xcoord + 1][this->ycoord] == '.') {
            this->xcoord += 1;
			std::cout << "DOWN\n" << std::endl;
            this->direction = DOWN;
        }
        else if (this->maze[this->xcoord][this->ycoord + 1] == '.') {
            this->ycoord += 1;
			std::cout << "RIGHT\n" << std::endl;
            this->direction = RIGHT;
        }
    }
        
    else if (this->direction == DOWN) {
        if (this->maze[this->xcoord][this->ycoord - 1] == '.') {
            this->ycoord -= 1;
			std::cout << "LEFT\n" << std::endl;
            this->direction = LEFT;
        }
        else if (this->maze[this->xcoord + 1][this->ycoord] == '.') {
            this->xcoord += 1;
			std::cout << "DOWN\n" << std::endl;
            this->direction = DOWN;
        }
        else if (this->maze[this->xcoord][this->ycoord + 1] == '.') {
            this->ycoord += 1;
			std::cout << "RIGHT\n" << std::endl;
            this->direction = RIGHT;
        }
        else if (this->maze[this->xcoord - 1][this->ycoord] == '.') {
            this->xcoord -= 1;
			std::cout << "UP\n" << std::endl;
            this->direction = UP;
        }
    }
        
    else if (this->direction == RIGHT) {
        if (this->maze[this->xcoord + 1][this->ycoord] == '.') {
            this->xcoord += 1;
			std::cout << "DOWN\n" << std::endl;
            this->direction = DOWN;
        }
        else if (this->maze[this->xcoord][this->ycoord + 1] == '.') {
            this->ycoord += 1;
			std::cout << "RIGHT\n" << std::endl;
            this->direction = RIGHT;
        }
        else if (this->maze[this->xcoord - 1][this->ycoord] == '.') {
            this->xcoord -= 1;
			std::cout << "UP\n" << std::endl;
            this->direction = UP;
        }
        else if (this->maze[this->xcoord][this->ycoord - 1] == '.') {
            this->ycoord -= 1;
			std::cout << "LEFT\n" << std::endl;
            this->direction = LEFT;
        }
    }
}

bool Maze::atExit() {
	if (this->xcoord == 0 || this->xcoord == this->size - 1 || this->ycoord == 0 || this->ycoord == this->size -1) {
        return true;
    }
	return false;
}

void Maze::getCurrentPosition(int &row, int &col) {
	row = this->xcoord;
	col = this->ycoord;
}