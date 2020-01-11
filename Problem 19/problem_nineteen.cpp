#include <iostream>

const int MONTHS_PER_YEAR = 12; //How many months are in a year
const int DAYS_PER_MONTH[MONTHS_PER_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //The amount of days in each month
const int DAYS_IN_FEB_LEAP_YEAR = 29; //How many days are in february on a leap year

int main() {
	
	int currentNameDay = 1;
	int currentYear = 1900;
	int daysInCurMonth = DAYS_PER_MONTH[0];
	
	int total = 0;

	for(int i = 0; i <= 100; i++) {
		for(int j = 0; j < MONTHS_PER_YEAR; j++) {
			
			daysInCurMonth = DAYS_PER_MONTH[j];
			
			if(j == 1) {
				if((currentYear + i) % 4 == 0) {
					if((currentYear + i) % 100 == 0) {
						if((currentYear + i) % 400 == 0) {
							
							daysInCurMonth = DAYS_IN_FEB_LEAP_YEAR;
							
						}
						
					} else {
						
						daysInCurMonth = DAYS_IN_FEB_LEAP_YEAR;
						
					}
					
				}
			
			}
			
			for(int k = 0; k < daysInCurMonth; k++) {
				
				if(currentNameDay == 7) {
					if(k == 0 && i != 0) {
					
						total++;
						std::cout << k + 1 << " " << j << " " << currentYear + i << " was a sunday." << std::endl;
					
					}
					currentNameDay = 1;
					
					
				} else {
				
					currentNameDay++;
				
				}
			}
			
		}
		
	
	}

	std::cout << "The number of sundays that fell on the first of a month in the 20th century was: " << total << std::endl;
	
	system("pause");
	return 0;
	
}