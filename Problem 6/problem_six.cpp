#include <iostream>

const int upper_bound = 100;

int main() {
	
	int sumOfSquares = 0;
	int squareOfSums = 0;
	
	for(int i = 0; i < upper_bound; i++) {
		
		sumOfSquares += (i + 1) * (i + 1);
		
	}
	
	for(int i = 0; i < upper_bound; i++) {
		
		squareOfSums += i + 1;
		
	}
	
	squareOfSums *= squareOfSums;
	
	std::cout << "The difference between the sum of squares and square of sums of the first " << upper_bound << " natural numbers is\n";
	std::cout << squareOfSums << " - " << sumOfSquares << " = " << squareOfSums - sumOfSquares << std::endl << std::endl;
	
	system("pause");
	return 0;
	
}