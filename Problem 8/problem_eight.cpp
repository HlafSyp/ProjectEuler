#include <iostream>
#include <string>
#include <vector>

void populateVector(std::vector<int> &number); 
void readIntoVector(std::vector<int> &number, std::string textNumber);
long long int findLargestProduct(std::vector<int> number);

const std::string THE_NUMBER_ONE =   "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843";
const std::string THE_NUMBER_TWO =   "8586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557";
const std::string THE_NUMBER_THREE = "6689664895044524452316173185640309871112172238311362229893423380308135336276614282806444486645238749";
const std::string THE_NUMBER_FOUR =  "3035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776";
const std::string THE_NUMBER_FIVE =  "6572733300105336788122023542180975125454059475224352584907711670556013604839586446706324415722155397";
const std::string THE_NUMBER_SIX =   "5369781797784617406495514929086256932197846862248283972241375657056057490261407972968652414535100474";
const std::string THE_NUMBER_SEVEN = "8216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586";
const std::string THE_NUMBER_EIGHT = "1786645835912456652947654568284891288314260769004224219022671055626321111109370544217506941658960408";
const std::string THE_NUMBER_NINE =  "0719840385096245544436298123098787992724428490918884580156166097919133875499200524063689912560717606";
const std::string THE_NUMBER_TEN =   "0588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

const int number_of_digits = 13;

int main() {
	
	std::vector<int> number;
	
	populateVector(number);

	std::cout << "The largest " << number_of_digits << " adjacent digit product is: ";
	std::cout << findLargestProduct(number);
	std::cout << "\n\n";

	std::cout << "\n\n";
	
	system("pause");
	return 0;
	
}

long long int findLargestProduct(std::vector<int> number) {
	
	long long int largestProduct = 0;
	long long int tempProduct = 1;
	int factors[number_of_digits] = {};
	int tempFactors[number_of_digits] = {};
	for(int i = 0; i < number.size() - number_of_digits; i++) {
		
		tempProduct = 1;
		
		for(int j = 0; j < number_of_digits; j++) {
			
			tempProduct = tempProduct * number[i + j];
			tempFactors[j] = number[i + j];
			
		}
		
		if(tempProduct >= largestProduct) {
			
			largestProduct = tempProduct;
			for(int j = 0; j < number_of_digits; j++) {
				
				factors[j] = tempFactors[j];
				
			}
			
		}
		
	}
	
	std::cout << "The factors for the largest product are: ";
	
	for(int i = 0; i < number_of_digits; i++) {
		
		std::cout << factors[i] << ", ";
		
	}
	
	std::cout << "\n";
	
	return largestProduct;
	
}

void populateVector(std::vector<int> &number) {
	
	readIntoVector(number, THE_NUMBER_ONE);
	readIntoVector(number, THE_NUMBER_TWO);
	readIntoVector(number, THE_NUMBER_THREE);
	readIntoVector(number, THE_NUMBER_FOUR);
	readIntoVector(number, THE_NUMBER_FIVE);
	readIntoVector(number, THE_NUMBER_SIX);
	readIntoVector(number, THE_NUMBER_SEVEN);
	readIntoVector(number, THE_NUMBER_EIGHT);
	readIntoVector(number, THE_NUMBER_NINE);
	readIntoVector(number, THE_NUMBER_TEN);
	
}

void readIntoVector(std::vector<int> &number, std::string textNumber) {
	
	int currentNumber = 0;
	
	for(int i = 0; i < textNumber.length(); i++) {
		
		currentNumber = std::stoi(textNumber.substr(i, 1));
		
		number.push_back(currentNumber);
		
	}
	
}