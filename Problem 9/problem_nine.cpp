#include <iostream>
#include <cmath>
#include <vector>

bool isSquare(int num);
bool generateTriplets(std::vector<int> &As,std::vector<int> &Bs, std::vector<int> &Cs, int startingA = 1);
void printTriplets(std::vector<int> a, std::vector<int> b, std::vector<int> c);
int checkForAnswer(std::vector<int> a, std::vector<int> b, std::vector<int> c);

const int UPPER_BOUND = 500; //Upper limit of integer checks to find valid triplets

//DEBUG VARIABLES
const bool ENABLE_DEBUG_MODE = false;

const bool DISPLAY_TRIPLETS = true;
const int NUM_OF_TRIPLETS = 16;

int main() {
	
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	
	bool problemSolved = false;
	int startingSearch = 0;
	
	int answerIndex;
	
	generateTriplets(a, b, c);
	
	answerIndex = checkForAnswer(a, b, c);
	
	if(answerIndex != -1) {
		
		problemSolved = true;
		
	} else {
		
		startingSearch = a[a.size() - 1];
		
	}
	
	while(!problemSolved) {
	
		if(!generateTriplets(a, b, c, startingSearch)) {
			
			break;
			
		}
		
		answerIndex = checkForAnswer(a, b, c);
	
		if(answerIndex != -1) {
			
			problemSolved = true;
			
		} else {
			
			startingSearch = a[a.size() - 1];
			
		}
		
	}
	if(ENABLE_DEBUG_MODE) {
	
		printTriplets(a, b, c);
	
	}
	
	std::cout << "A,B,C is equal to: " << a[answerIndex] << " + " << b[answerIndex] << " + " << c[answerIndex] << " = 1000\n";
	std::cout << "The product of a,b,c is: " << a[answerIndex] * b[answerIndex] * c[answerIndex] << std::endl << std::endl;
	
	system("pause");
	return 0;
	
}

int checkForAnswer(std::vector<int> a, std::vector<int> b, std::vector<int> c) {
	
	for(int i = 0; i < a.size(); i++) {
		
		if(ENABLE_DEBUG_MODE) {
		
			std::cout << a[i] + b[i] + c[i] << std::endl;
		
		}
		
		if(a[i] + b[i] + c[i] == 1000) {
			
			return i;
			
		}
		
	}
	
	return -1;
	
}

void printTriplets(std::vector<int> a, std::vector<int> b, std::vector<int> c) {

	for(int i = 0; i < a.size(); i++) {
		
		std::cout << "Triplet #" << i << ": ";
		std::cout << a[i] << "^2 + " << b[i] << "^2 = ";
		std::cout << c[i] << "^2\n";
		
	}
	
}

bool generateTriplets(std::vector<int> &As,std::vector<int> &Bs, std::vector<int> &Cs, int startingA) {

	int tripletsFound = 0;
	
	int a = startingA + 1;
	int c = 0;
	
	int numberOfTriplets = NUM_OF_TRIPLETS;
	
	if(startingA != 1) {
		
		numberOfTriplets = As.size() + 10;
		
	}
	
	while(numberOfTriplets > tripletsFound) {
		
		for(int i = a; i < UPPER_BOUND; i++) {
			
			c = (a*a) + (i*i);
			
			if(isSquare(c)) {

				As.push_back(a);
				Bs.push_back(i);
				Cs.push_back(sqrt(c));
				
				if(ENABLE_DEBUG_MODE) {
					
					std::cout << "a: " << As[As.size() - 1] << ", ";
					std::cout << "b: " << Bs[Bs.size() - 1] << ", ";
					std::cout << "c: " << Cs[Cs.size() - 1] << std::endl;
					
				}
				
				tripletsFound++;
				
			}
			
		}
		
		a++;
		
	}
	
	return true;

}	

bool isSquare(int num) {
	
	int roundedNum = ceil(sqrt(num));
	double sqrtNum = sqrt(num);
	
	if(roundedNum == sqrtNum) {
		
		return true;
		
	} else {
		
		return false;
		
	}
	
}

