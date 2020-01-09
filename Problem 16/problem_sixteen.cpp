#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

std::string add2NumStrings(std::string a, std::string b);
void carry(std::vector<int> &numWithCarry);

const int POW_BASE = 2;
const int POW_POWER = 1000;

int main() {
	
	std::string pow = "0";
	
	pow = add2NumStrings(pow, std::to_string(POW_BASE));
	
	for(int i = 1; i < POW_POWER; i++) {
		
		for(int j = 1; j < POW_BASE; j++) {
			
			pow = add2NumStrings(pow, pow);
			
		}
		
	}
	
	int sumOfDigits = 0;
	
	for(int i = 0; i < pow.length(); i++) {
		
		sumOfDigits += pow[i] - 48;
		
	}
	
	
	
	std::cout << "The sum of the digits of the number " << POW_BASE << "^" << POW_POWER << " is: ";
	std::cout << sumOfDigits << std::endl;
	
	system("pause");
	return 0;
	
}

std::string add2NumStrings(std::string a, std::string b) {
	
	std::vector<int> tempSum;
	
	int numOne = 0;
	int numTwo = 0;
	
	int bOffset = a.length() - b.length();
	
	for(int i = 0; i < a.length(); i++) {
		
		numOne = a[i] - 48;
		if(bOffset > i) {
			
			numTwo = 0;
			
		} else {
			
			numTwo = b[i - bOffset] - 48;
			
		}
		
		tempSum.push_back(numOne + numTwo);
		
	}
	
	carry(tempSum);
	
	std::string sum = "";
	
	for(int i = 0; i < tempSum.size(); i++) {
		
		sum += std::to_string(tempSum[i]);
		
	}
	
	return sum;
	
}

void swap(int &a, int &b) {
	
	int tempA = a;
	a = b;
	b = tempA;
	
}

void increaseSignificance(std::vector<int> &number) {
	
	for(int i = 0; i < number.size(); i++) {
		
		swap(number[i], number.back());
		
	}
	
}

void carry(std::vector<int> &numWithCarry) {
	
	for(int i = 0; i < numWithCarry.size(); i++) {
		
		if(numWithCarry[i] >= 10) {
			
			if(i - 1 == -1) {
				
				numWithCarry[i] = numWithCarry[i] - 10;
				numWithCarry.push_back(1);
				increaseSignificance(numWithCarry);
				
			} else {
				
				numWithCarry[i] = numWithCarry[i] - 10;
				numWithCarry[i - 1] = numWithCarry[i - 1] + 1;
				
			}
			
			carry(numWithCarry);
			
		}
		
	}
	
}