#include <iostream>
#include <vector>

void printPrimes(std::vector<int> primes);
bool isPrime(int number);


const int UPPER_BOUND = 2000000;

const int ENABLE_DEBUG_MODE = true;
const int PRINT_PRIMES = true;

const int PRIMES_PER_ROW = 15;

int main() {
	
	std::vector<int> primes;
	
	long long int total = 0;
	
	for(int i = 1; i < UPPER_BOUND; i++) {
		if(isPrime(i)) {
			
			primes.push_back(i);
			total += i;
			
		}
		
	}

	if(ENABLE_DEBUG_MODE && PRINT_PRIMES) {
	
		printPrimes(primes);
		std::cout << "\n\n";
	}
	
	
	std::cout << "The sum of all primes below two million is: " << total << std::endl << std::endl;
	
	system("pause");
	return 0;
	
}

void printPrimes(std::vector<int> primes) {
	
	std::cout << "Primes: ";
	
	for(int i = 0; i < primes.size(); i++) {
		
		if(i % PRIMES_PER_ROW == 0 && i != 0) {
			
			std::cout << "\n        ";
			
		}
		
		std::cout << primes[i];
		
		if(i < primes.size() - 1) {
			
			std::cout << ", ";
			
		}
		
	}
	
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