#include <iostream>

long double pathCounter();

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

const int MINIMUM_MOVES = GRID_WIDTH + GRID_HEIGHT;

int main() {
	
	unsigned long long int numPaths = 0;
	
	numPaths = pathCounter();
	
	std::cout << "The number of paths for a " << GRID_WIDTH << "x" << GRID_HEIGHT << " grid is: " << numPaths << std::endl;
	
	system("pause");
	return 0;
	
}

long double pathCounter() {
	
	int gridHeight = GRID_HEIGHT + 1;
	int gridWidth = GRID_WIDTH + 1;
	
	long double grid[gridHeight][gridWidth];
	
	for(int i = 0; i < gridHeight; i++) {
		for(int j = 0; j < gridWidth; j++) {
		
			if(i == 0 || j == 0) {
				
				grid[i][j] = 1;
				
			} else {
				
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1]; 
				
			}
			
		}
	}
	
	return grid[gridHeight - 1][gridWidth - 1];
	
}