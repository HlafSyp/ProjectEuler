#include <iostream>
#include <cmath>

bool isPrime(int number);
bool isSquare(int num);

int main() {
	
	int totalPrimes = 0;
	int currentNumber = 0;
	
	while(totalPrimes != 10001) {
		
		currentNumber++;
		
		if(isPrime(currentNumber)) {
			
			totalPrimes++;
			std::cout << "\nCurrent Prime is: " << currentNumber; 
		}
		
		
		
	}
	
	std::cout << "\n";
	std::cout << "The 10,001st prime number is: " << currentNumber << std::endl << std::endl;
	
	system("pause");
	return 0;
	
}

bool isPrime(int number) {
	
	int totalFactors = 0;
	int f = 3;
	
	while (number % 2 == 0) {
		
		totalFactors++;
		number /= 2;
		
	}
	
	while (f * f <= number) {
	
		if(number % f == 0) {
			
			totalFactors++;
			number /= f;
			
		} else {
			
			f += 2;
			
		}
	}
	
	if (number != 1) {
		
		totalFactors++;
		
	}
	
	if(totalFactors == 1) {
		
		return true;
		
	} else {
		
		return false;
		
	}
	
}
