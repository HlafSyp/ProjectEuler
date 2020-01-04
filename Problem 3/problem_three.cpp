#include <iostream>
#include <vector>
#include <cmath>

int TrialDivision();
bool isPrime(int number);
bool isSquare(int num);

const long long int THE_NUMBER = 600851475143; //600,851,475,143


int main() {
	
	std::cout << "The Largest Prime Factor is: " << TrialDivision() << "\n\n";
	
	system("pause");
	return 0;
	
}

int TrialDivision() {
	
	std::vector<int> factors;
	
	int s = floor(sqrt(THE_NUMBER));
	
	int divisor = 1;
	
	while(divisor != s) {
		
		if(THE_NUMBER % divisor == 0) {
			
			if(isPrime(divisor)) {
				
				factors.push_back(divisor);
				
			}
			
		}
		
		divisor++;
		
	}
	
	return factors[factors.size() - 1];
	
}

bool isPrime(int number) {
	
	int a = ceil(sqrt(number));
	int bTwo = a*a - number;
	while(!isSquare(bTwo)) {
		
		a += 1;
		bTwo = a * a - number;
		
	}
	
	if(a - sqrt(bTwo) == 1) {
		
		return true;
		
	} else {
		
		return false;
		
	}
	
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