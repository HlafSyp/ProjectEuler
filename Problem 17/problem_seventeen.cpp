#include <iostream>
#include <string>
#include <cmath>


int letterCounter(std::string number);
int lookupNumber(int number, int position);

const int LOWER_RANGE = 1;
const int UPPER_RANGE = 1000;

int main() {
	
	int totalLetter = 0;
	
	for(int i = LOWER_RANGE; i <= UPPER_RANGE; i++) {
		
		std::cout << "Current Number given: " << i << std::endl;
		
		totalLetter += letterCounter(std::to_string(i));
		
		std::cout << "Current Total: " << totalLetter << "\n\n";
		
	}
	
	std::cout << "The amount of letters in the numbers " << LOWER_RANGE << " to " << UPPER_RANGE << " is: ";
	std::cout << totalLetter << std::endl;
	
	system("pause");
	return 0;
	
}

int letterCounter(std::string number) {
	
	
	int lettersInNumber = 0;
	
	for(int i = 0; i < number.length(); i++) {
		
		lettersInNumber += lookupNumber(number[i] - 48, number.length() - i - 1);
		
	}
	
	std::cout << "Total Characters for # " << number << ": " << lettersInNumber << std::endl;
	
	return lettersInNumber;
	
}

int lookupNumber(int number, int position) {
	
	std::string numberLookup[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand"};
	
	static bool isTens = false;
	static bool addAnd = false;
	int numberOfCharacters = 0;
	
	if(position == 0) {
		
		if(isTens) {
			
			numberOfCharacters = numberLookup[number + 10].length();
			
		} else {
			
			numberOfCharacters = numberLookup[number].length();
			
		}
		
		if(number > 0 && addAnd) {
			
			numberOfCharacters += 3;
			
		}
		
		addAnd = false;
		isTens = false;
		
	} else if (position == 1) {
		
		if(number == 1) {

			isTens = true;
			numberOfCharacters = 0;
			
		} else if (number >= 2) {
			
			numberOfCharacters = numberLookup[number + 18].length();
			
		} else {

			numberOfCharacters = 0;
			
		}
		
		if(addAnd && number >= 1) {
			
			numberOfCharacters += 3;
			addAnd = false;
			
		}
		
	} else if (position == 2) {
		
		if(number > 0) {

			numberOfCharacters = numberLookup[number].length() + numberLookup[28].length();
			addAnd = true;
			
		} else {

			numberOfCharacters = 0;
			
		}
		
	} else if (position == 3) {

		numberOfCharacters = numberLookup[number].length() + numberLookup[29].length();
		
	}

	return numberOfCharacters;
	
}

