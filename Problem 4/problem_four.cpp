#include <iostream>
#include <string>
#include <cmath>

bool isPalindrome(int number);
int findPalindrome();

const bool displayDebugLog = false;
const int numberOfDigits = 3;

int main() {
	
	int palindrome = findPalindrome();
	
	std::cout << "The answer is: " << palindrome << "\n\n";
	
	system("pause");
	return 0;
	
}

int findPalindrome() {
	
	int upperBound = pow(10, numberOfDigits) - 1;
	int lowerBound = pow(10, numberOfDigits - 1) - 1;
	
	int palindrome = 0;
	int totalChecks = 0;
	int factorOne = upperBound;
	int factorTwo = 0;
	
	while(factorOne != lowerBound) {
		
		for(int i = upperBound; i > lowerBound; i--) {
			
			totalChecks += 1;
			
			if(isPalindrome(factorOne * i)) {
				
				
				if(factorOne * i > palindrome) {
					
					palindrome = factorOne * i;
					
				}
				
				factorTwo = i;
				
				
				
			}

		}	

		factorOne--;
		
	}
	
	if(displayDebugLog) {
		
		std::cout << "\nChecked " << totalChecks << " times\n";
		std::cout << "The palindrome was made with " << factorOne << " * " << factorTwo << "\n\n";
		
	}
	
	return palindrome;
	
	
}

bool isPalindrome(int number) {
	
	std::string stringNumber = std::to_string(number);
	std::string reversedNumber = "";
	
	float rebmun;
	
	for(int i = stringNumber.length(); i > 0; i--) {
		
		reversedNumber += stringNumber[i  - 1];
		
	}
	
	rebmun = std::stoi(reversedNumber);
	
	if(displayDebugLog) {

		std::cout << "\n";
		std::cout << stringNumber << ", " << reversedNumber << ", ";
		std::cout << rebmun << ", " << number;

	}
	
	if(rebmun / number == 1) {
		
		return true;
		
	} else {
		
		return false;
		
	}
	
}