#include <iostream>
#include <vector>
#include <string>

void printMultiples(std::vector<int> setThree, std::vector<int> setFive);
int checkMultiples(const int &number);

const int maxCap = 1000;
const int multiplesPerRow = 15;
const bool displayMultiples = true;

int main() {
	
	std::vector<int> setThree;
	std::vector<int> setFive;
	
	int multiplesOf = 0;
	int total = 0;
	
	for(int i = 1; i < maxCap; i++) {
		
		multiplesOf = checkMultiples(i);
		switch(multiplesOf) {
			
			case 3:
				setThree.push_back(i);
				total += i;
				break;
			case 5:
				setFive.push_back(i);
				total += i;
				break;
			case 8:
				setThree.push_back(i);
				setFive.push_back(i);
				total += i;
				break;
			
		}
		
	}
	
	if(displayMultiples) {
		
		printMultiples(setThree, setFive);
		
	}
	
	std::cout << "The Sum Of All Multiples of 3 or 5 is: " << total << "\n\n";
	
	
	system("pause");
	return 0;
	
}

int checkMultiples(const int &number) {
	
	int multiple = 0;
	
	if(number % 3 == 0) {
		
		multiple += 3;
		
	}
	
	if(number % 5 == 0) {
		
		multiple += 5;
		
	}
	
	return multiple;
	
}

void printVector(std::vector<int> set) {
	
	for(int i = 0; i < set.size(); i++) {
		
		if(multiplesPerRow != 0) {
			
			if(i % multiplesPerRow == 0 && i != 0) {
			
				std::cout << "\n" << std::string(15, ' ');
				
			}
			
		}
		
		std::cout << set[i];
		
		if(i < set.size() - 1) {
			
			std::cout << ", ";
			
		}
		
	}
	
}

void printMultiples(std::vector<int> setThree, std::vector<int> setFive) {
	
	std::cout << "Multiples Of 3: ";
	printVector(setThree);
	std::cout << "\n\n";
	std::cout << "Multiples of 5: ";
	printVector(setFive);
	std::cout << "\n\n";
	
}

