#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class row {
	
public:

	row (std::string rowData) {
		
		extractRowData(rowData);
		
	}
	
	void printRow() {
		
		for(int i = 0; i < numbers.size(); i++) {
			
			if(numbers[i] < 10 && numbers[i] > 0) {
				
				std::cout << "0" << numbers[i] << " ";
				
			} else {
				
				std::cout << numbers[i] << " ";
			
			}
			
		}
		
		std::cout << std::endl;
		
	}
	
	int at(int index) {
		
		return numbers[index];
		
	}
	
	int size() {
		
		return numbers.size();
		
	}
	
private:
	
	std::vector<int> numbers;
	
	void extractRowData(std::string rowData) {
		
		for(int i = 0; i < rowData.length(); i += 3) {
			
			if(rowData[i] == 0) {
				
				numbers.push_back(rowData[i + 1] - 48);
				
			} else {
				
				numbers.push_back(std::stoi(rowData.substr(i, 2)));
				
			}
			
		}
		
	}
	
};

const int STEPS_ADVANCED = 2; //How many rows down the program checks on each row (EX if on row 0, it will check each path down to row 2 for the highest return value)

const int PATH_HISTORY_PER_LINE = 6; //How many steps are displayed per row

bool moveLeft(std::vector<row> rows, int index, int xPos, int startingTotal);
int checkAdvance(std::vector<row> rows,  int startingTotal, int index = 0, int xPos = 0, int checkCounter = STEPS_ADVANCED - 1);
void initRows(std::vector<row> &rows);

int main() {
	
	std::vector<int> path;
	std::vector<bool> moveLefts;
	
	std::vector<row> rows;
	
	initRows(rows);
	
	int x = 0;
	int y = 0;
	
	int total = rows[y].at(x);
	
	path.push_back(rows[y].at(x));
	
	for(int i = 1; i < rows.size(); i++) {
		
		if(moveLeft(rows, y, x, total)) {

			moveLefts.push_back(true);
			
		} else {
			
			x++;
			moveLefts.push_back(false);
			
		}
		
		y++;
		
		if(i == rows.size()) {
			
			system("pause");
			
		}

		total += rows[y].at(x);
		path.push_back(rows[y].at(x));
		
	}
	
	for(int i = 0; i < path.size(); i++) {
		
		if(i % PATH_HISTORY_PER_LINE == 0 && i != 0) {
			
			std::cout << "\n";
			
		}
		
		std::cout << path[i];
		
		if(moveLefts[i]) {
			
			std::cout << " (moved left) ";
			
		} else {
			
			std::cout << " (moved right) ";
			
		}
		
	}
	
	std::cout << "\n\n";
	std::cout << "The maximum total from top to bottom was: " << total << "\n\n";
	
	system("pause");
	return 0;
	
}

bool moveLeft(std::vector<row> rows, int index, int xPos, int startingTotal) {
	
	int leftBranch = checkAdvance(rows, startingTotal, index + 1, xPos);
	int rightBranch = checkAdvance(rows, startingTotal, index + 1, xPos + 1);

	if(leftBranch > rightBranch) {
		
		return true;
		
	} else {
		
		return false;
		
	}
	
}

int checkAdvance(std::vector<row> rows,  int startingTotal, int index, int xPos, int checkCounter) {
	
	int currentTotal;

	if(index >= rows.size() || xPos >= rows[index].size()) {
		
		return startingTotal;
		
	} else {
	
		currentTotal = startingTotal + rows[index].at(xPos);
	
	}
	
	if(checkCounter == 0) {
		
		return currentTotal;
		
	} else {
		
		int leftBranch = checkAdvance(rows, currentTotal, index + 1, xPos, checkCounter - 1);
		int rightBranch = checkAdvance(rows, currentTotal, index + 1, xPos + 1, checkCounter - 1);
		
		if(leftBranch < rightBranch) {

			return rightBranch;
			
		} else {

			return leftBranch;
			
		}
		
	}
	
}

void initRows(std::vector<row> &rows) {
	
	rows.push_back(row("75"));
	rows.push_back(row("95 64"));
	rows.push_back(row("17 47 82"));
	rows.push_back(row("18 35 87 10"));
	rows.push_back(row("20 04 82 47 65"));
	rows.push_back(row("19 01 23 75 03 34"));
	rows.push_back(row("88 02 77 73 07 63 67"));
	rows.push_back(row("99 65 04 28 06 16 70 92"));
	rows.push_back(row("41 41 26 56 83 40 80 70 33"));
	rows.push_back(row("41 48 72 33 47 32 37 16 94 29"));
	rows.push_back(row("53 71 44 65 25 43 91 52 97 51 14"));
	rows.push_back(row("70 11 33 28 77 73 17 78 39 68 17 57"));
	rows.push_back(row("91 71 52 38 17 14 91 43 58 50 27 29 48"));
	rows.push_back(row("63 66 04 68 89 53 67 30 73 16 69 87 40 31"));
	rows.push_back(row("04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"));
	
}