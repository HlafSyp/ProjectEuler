#include <iostream>

long long int checkLine(int dir, int x, int y);
void getOffsets(int dir, int offsetsX[], int offsetsY[]);
long long int product(int factors[]);

const int NUM_GRID[20][20] = {{ 8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8},
							 {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0},
							 {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
							 {52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
							 {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
							 {24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
							 {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
							 {67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21},
							 {24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
							 {21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95},
							 {78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92},
							 {16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57},
							 {86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
							 {19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40},
							 { 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
							 {88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
							 { 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36},
							 {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16},
							 {20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54},
							 { 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48}};

const int NUM_ADJACENT_DIGITS = 4;	

//DEBUG VARIABLES
const bool ENABLE_DEBUG_MODE = true;
const bool PRINT_LINE_CHECKS = true;	
const bool PRINT_LARGEST_CHANGE = false;
const bool PRINT_CURRENT_OFFSET = false;	
				
int main() {
	
	bool answerFound = false;
	int timesChecked = 0;
	
	int curLargest = 0;
	int curLineProduct = 0;
	
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			
			for(int k = 1; k < 10; k++) {
				
				curLineProduct = checkLine(k, j, i);
				if(curLineProduct > curLargest) {
					
					if(ENABLE_DEBUG_MODE && PRINT_LARGEST_CHANGE) {
						
						std::cout << "New Current Largest: " << curLineProduct;
						std::cout << "; Old Largest: " << curLargest << std::endl;
						std::cout << "POS: (" << j << "," << i << ") ; Direction: " << k << std::endl << std::endl;
						
					}
					curLargest = curLineProduct;
					
				}
				
			}
			
		}
	}
	
	std::cout << "The largest product of " << NUM_ADJACENT_DIGITS << " adjacent numbers in the same direction is: ";
	std::cout << curLargest << std::endl << std::endl;
	
	system("pause");
	return 0;
	
}

long long int checkLine(int dir, int x, int y) {
	
	// 7 8 9
	// 4   6
	// 1 2 3
	//number represents direction line will look
	//ex.) dir = 3, line will go diagonally down right
	
	int factors[NUM_ADJACENT_DIGITS] = {};
	int offsetsX[NUM_ADJACENT_DIGITS] = {};
	int offsetsY[NUM_ADJACENT_DIGITS] = {};
	
	getOffsets(dir, offsetsX, offsetsY);
	
	if(ENABLE_DEBUG_MODE && PRINT_LINE_CHECKS) {
		
		std::cout << "( " << x << "," << y << ", " << dir << ") Current Line: ";
		
	}
	
	for(int i = 0; i < NUM_ADJACENT_DIGITS; i++) {
		
		if((y + offsetsY[i] > 0 && y + offsetsY[i] < 20) && (x + offsetsX[i] > 0 && x + offsetsX[i] < 20)) { 
		
			factors[i] = NUM_GRID[y + offsetsY[i]][x + offsetsX[i]];
		
		} else {
			
			if(ENABLE_DEBUG_MODE && PRINT_LINE_CHECKS) {
				
				std::cout << "\n";
				
			}
			return -1;
			
		}
		
		if(ENABLE_DEBUG_MODE && PRINT_LINE_CHECKS) {
			
			std::cout << factors[i] << ", ";
			
		}
		
	}
	
	if(ENABLE_DEBUG_MODE && PRINT_LINE_CHECKS) {
		
		std::cout << "= " << product(factors) << std::endl; 
		
	}
	
	return product(factors);
	
}

void getOffsets(int dir, int offsetsX[], int offsetsY[]) {
	
	int curOffsetX = 0;
	int curOffsetY = 0;
	
	for(int i = 0; i < NUM_ADJACENT_DIGITS; i++) {
		
		switch(dir) {
			case 1:
				offsetsX[i] = curOffsetX--;
				offsetsY[i] = curOffsetY++;
				break;
			case 2:
				offsetsX[i] = 0;
				offsetsY[i] = curOffsetY++;
				break;
			case 3:
				offsetsX[i] = curOffsetX++;
				offsetsY[i] = curOffsetY++;
				break;
			case 4:
				offsetsX[i] = curOffsetX--;
				offsetsY[i] = 0;
				break;
			case 5:
			case 6:
				offsetsX[i] = curOffsetX++;
				offsetsY[i] = 0;
				break;
			case 7:
				offsetsX[i] = curOffsetX--;
				offsetsY[i] = curOffsetY--;
				break;
			case 8:
				offsetsX[i] = 0;
				offsetsY[i] = curOffsetY--;
				break;
			case 9:
				offsetsX[i] = curOffsetX++;
				offsetsY[i] = curOffsetY--;
				break;
				
		}
		
		if(ENABLE_DEBUG_MODE && PRINT_CURRENT_OFFSET) {
			
			std::cout << "Current Y Offset: " << curOffsetY << std::endl;
			std::cout << "Current X Offset: " << curOffsetX << std::endl;
		
		}
		
	}
	
}

long long int product(int factors[]) {

	long long int productTotal = 1;
	
	for(int i = 0; i < NUM_ADJACENT_DIGITS; i++) {
		
		productTotal *= factors[i];
		
	}
	
	return productTotal;
	
}