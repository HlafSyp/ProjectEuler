#include <iostream>
#include <cmath>
#include <vector>

long long int getTriangleNumber(int n);
int trialDivision(long long int number);
bool isUsed(std::vector<int> factors, int factor);

const int NUMBER_OF_FACTORS_TO_FIND = 500;

//DEBUG
const bool ENABLE_DEBUG_MODE = true;
const bool PRINT_TRIANGLE_VALUE = true;
const bool PRINT_NUMBER_OF_FACTORS = true;
const bool PRINT_ALL_FACTORS = false;

int main() {
	
	bool numberFound = false;
	int currentTriNumber = 1;
	long long int currentTriValue = 0;
	
	while(!numberFound) {
		
		currentTriValue = getTriangleNumber(currentTriNumber);
		
		if(trialDivision(currentTriValue) > NUMBER_OF_FACTORS_TO_FIND) {
			
			numberFound = true;
			
		} else {
			
			currentTriNumber++;
			
		}
		
	}
	
	std::cout << "The value of the first triangle number to have over " << NUMBER_OF_FACTORS_TO_FIND << " divisors is: " << currentTriValue << std::endl;
	
	system("pause");
	return 0;
	
}

int trialDivision(long long int number) {
	
	int totalFactors = 0;
	
	int divisor = 1;
	
	std::vector<int> factors;
	
	int s = floor(sqrt(number));
	
	if(number < 500) {
		
		s = number;
		
	}
	
	while(divisor <= s) {
		
		if(number % divisor == 0 && !(isUsed(factors, divisor) || isUsed(factors, number / divisor))) {
			
			if(number != 1) {
			
				totalFactors += 2;
			
			} else {
			
				totalFactors++;
				
			}
			
			factors.push_back(divisor);
			factors.push_back(number / divisor);
			
		}
		
		divisor++;
		
	}
	
	if(ENABLE_DEBUG_MODE && PRINT_NUMBER_OF_FACTORS) {
		
		std::cout << "The number of factors for " << number << " is " << totalFactors << std::endl;
		
	}
	
	if(ENABLE_DEBUG_MODE && PRINT_ALL_FACTORS) {
		
		std::cout << "The factors of " << number << " is: ";
		
		for(int i = 0; i < factors.size(); i++) {
			
			std::cout << factors[i] << ", ";
			
		}
		
		std::cout << std::endl;
		
	}
	
	return totalFactors;
	
}

bool isUsed(std::vector<int> factors, int factor) {
	
	for(int i = 0; i < factors.size(); i++) {
		
		if(factors[i] == factor) {
			
			return true;
			
		}
		
	}
	
	return false;
	
}

long long int getTriangleNumber(int n) {
	
	long long int triangleNumber = 0;
	
	for(int i = 0; i < n; i++) {
		
		triangleNumber += i + 1;
		
	}
	
	if(ENABLE_DEBUG_MODE && PRINT_TRIANGLE_VALUE) {
		
		std::cout << "Triangle Value #" << n << " is: " << triangleNumber << std::endl;
		
	}
	
	return triangleNumber;
	
}