#include <iostream>
#include <string>

void printSequence(bool evensOnly);
int getSumOfSequence(bool evensOnly);

const int maxValue = 4000000;
const int numbersPerRow = 20;
const int sequenceStart = 1;

const int displaySequence = true;
const int displayFullSequenceSum = true;

int main() {
	
	if(displaySequence) {
		
	std::cout << "     Fibonacci Sequence: ";
	printSequence(false);
	
	std::cout << "\n\n";
	
	std::cout << "Even Fibonacci Sequence: ";
	printSequence(true);
	std::cout << "\n\n";
	}
	
	if(displayFullSequenceSum) {
		
		std::cout << "     Sequence Sum: ";
		std::cout << getSumOfSequence(false);
		std::cout << "\n\n";
		
	}
	
	std::cout << "Even Sequence Sum: ";
	std::cout << getSumOfSequence(true);
	
	std::cout << "\n\n";
	
	system("pause");
	return 0;
	
}

int getSumOfSequence(bool evensOnly) {
	
	int highestNumber = 0;
	int currentNumber = sequenceStart;
	int previousNumber = sequenceStart;
	int tempCur = 0;
	
	int total = 0;
	
	while(highestNumber < 4000000) {	
		
		tempCur = currentNumber;
		currentNumber += previousNumber;
		previousNumber = tempCur;
		highestNumber = currentNumber;
		
		if(evensOnly && currentNumber % 2 == 0) {
			
			total += currentNumber;
			
		} else if(!evensOnly) {
			
			total += currentNumber;
			
		}
		
	}
	
	return total;
	
}

void printSequence(bool evensOnly) {
	
	int highestNumber = 0;
	int currentNumber = sequenceStart;
	int previousNumber = sequenceStart;
	int tempCur = 0;
	int numsOnRow = 0;
	while(highestNumber < 4000000) {
		
		if(numsOnRow % numbersPerRow == 0 && numsOnRow != 0) {
			
			std::cout << "\n";
			std::cout << std::string(25, ' ');
			numsOnRow = 0;
			
		}
		
		if(evensOnly && currentNumber % 2 == 0) {
			
			std::cout << currentNumber << ", ";
			
		} else if(!evensOnly) {
			
			std::cout << currentNumber << ", ";
			
		}
		
		
		tempCur = currentNumber;
		currentNumber += previousNumber;
		previousNumber = tempCur;
		highestNumber = currentNumber;
		
		numsOnRow++;
		
	}
	
}