#include <iostream>

int testStartNumber(unsigned int number);
int collatzSequence(unsigned int number);

const int NUMBER_CAP = 1000000;

int main() {
	
	int longestChainLength = 0;
	int NumberProducedChain = 0;
	
	int tempChainLength = 0;
	
	for(int i = 1; i < NUMBER_CAP; i++) {

		tempChainLength = testStartNumber(i);
		
		//std::cout << tempChainLength << std::endl;
		
		if(longestChainLength <= tempChainLength) {

			longestChainLength = tempChainLength;
			NumberProducedChain = i;

		}
		
	}
	
	std::cout << "The number which produced the longest chain of " << longestChainLength << " was " << NumberProducedChain << std::endl;
	system("pause");
	return 0;
	
}

int testStartNumber(unsigned int number) {
	
	int chainLength = 1;
	
	if(number == 1) {
		
		chainLength = 0;
		
	}
	
	while(number > 1) {
		
		chainLength++;
		
		number = collatzSequence(number);
		
	}
	
	return chainLength;
	
}

int collatzSequence(unsigned int number) {
	
	if(number % 2 == 0) {
		
		//std::cout << "(" << number << ") Even: " << number / 2 << std::endl;
		
		return number / 2;
		
	} else {
		
		//std::cout << "(" << number << ") Odd: " << (number * 3) + 1 << std::endl;
		
		return (number * 3) + 1;
		
	}
	
}