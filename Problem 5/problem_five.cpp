#include <iostream>

bool isDivisible(int number);

const int upper_dividend = 20;

int main() {
	
	int number = 0;	
	bool hasFound = false;
	
	
	while(!hasFound) {
		
		number++;
		hasFound = isDivisible(number);
		
	}
	
	std::cout << "The smallest number is: " << number << "\n\n";
	
	system("pause");
	return 0;
	
}

bool isDivisible(int number) {
	
	for(int i = 0; i < upper_dividend; i++) {
		
		if(number % (i + 1) != 0) {
			
			return false;
			
		}
		
	}
	
	return true;
	
}