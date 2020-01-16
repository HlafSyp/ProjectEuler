#include <iostream>
#include <vector>
#include <cmath>

class amicableNumber {
	
public:
	
	amicableNumber(int num, bool isPaired) {
		
		_number = num;
		_trialDivision();
		_calcFactorSum();
		
		_isPaired = true;
		
	}
	
	amicableNumber(int num) {
		
		_number = num;
		_trialDivision();
		_calcFactorSum();
		
		_pair = new amicableNumber(_factorSum, true);
		
		_isPair();
		
	}
	
	amicableNumber() {}
	
	~amicableNumber() {
		
		delete _pair;
		
	}
	
	int getNumber() {return _number;}
	int getFactorSum() {return _factorSum;}
	
	bool getStatus() {return _isAmicableNumber;}
	
	
private:
	
	void _isPair() {
		
		if(_pair->getFactorSum() == _number) {
			
			_isAmicableNumber = true;
			
		}
		
	}
	
	void _trialDivision() {
		
		int s = floor(sqrt(_number));
		
		int divisor = 1;
		
		bool inFactors = false;
		
		while(divisor != s) {
			
			if(_number % divisor == 0) {
				
				_factors.push_back(divisor);
				
			}
			
			divisor++;
			
		}
		
		_factors.push_back(1);
		_factors.push_back(_number);
		
	}
	
	void _calcFactorSum() {
		
		_factorSum = 0;
		
		for(int i = 0; i < _factors.size(); i++) {
			
			_factorSum += _factors[i];
			
		}
		
	}
	
	std::vector<int> _factors;
	int _number;
	int _factorSum;
	bool _isPaired = false;
	
	bool _isAmicableNumber = false;
	
	amicableNumber *_pair;
	
};

int d(int n);
int sumFactors(int n); 

const int ADD_BELOW = 10000; //The highest value the amicable number can go to (is less than but NOT equal to)

int main() {

	int finalSum = 0;
	
	int numOne = 0;
	int numTwo = 0;
	
	std::vector<int> numAmicable;
	
	for(int i = 1; i < ADD_BELOW; i++) {
		
		numOne = d(i);
		numTwo = d(numOne);
		
		if(i == numTwo && i != numOne) {
			
			finalSum += i;
			numAmicable.push_back(i);
			
		}
		
	}
	
	for(int i = 0; i < numAmicable.size(); i++) {
		
		std::cout << numAmicable[i] << ", " << d(numAmicable[i]) << std::endl;
		
	}
	
	std::cout << "The sum of all amicable numbers below " << ADD_BELOW << " totals " << finalSum;
	
	std::cout << "\n\n";
	
	system("pause");
	return 0;
	
}

int d(int n) {
	
	int sumOfFactors = sumFactors(n);
	
	return sumOfFactors;
	
}

int sumFactors(int n) {
	
	int sum = 0;
	
	int s = floor(sqrt(n));
	
	int divisor = 1;
	
	while(divisor <= s) {
		
		if(n % divisor == 0) {
			
			sum += divisor;
			
			if(divisor != n / divisor && n / divisor != n) {
				
				sum += n / divisor;
				
			}
			//std::cout << "Factor Pair of " << n << ": " << divisor << ", " << n / divisor << std::endl;
			
		}
		
		divisor++;
		
	}
	
	return sum;
	
}