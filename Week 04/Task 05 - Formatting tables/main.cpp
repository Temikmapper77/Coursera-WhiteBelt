#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {

	ifstream input("input.txt");
	string rows_string;
	string cols_string;
	string number;
	vector<int> numbers{};

	if (input) {



	//	getline(input, rows_string, ' ');
	//	getline(input, cols_string, '\n');

		input >> rows_string >> cols_string;
		input.ignore(1);
	/*	while (cols_string == "") {
			getline(input, cols_string, '\n');

		}

/*		cout << rows_string;
		cout << "\"" << cols_string << "\"";*/

		int rows = atoi(rows_string.c_str());
		int cols = atoi(cols_string.c_str());
		
		
		for (int i = 0; i < rows; i++) {
			for (int n = 0; n < cols-1; n++) {
				getline(input, number, ',');
				cout << setw(10) << number << ' ';
				numbers.push_back(atoi(number.c_str()));
				number = {};
			}
			getline(input, number, '\n');
			cout << setw(10) << number << endl;
			numbers.push_back(atoi(number.c_str()));
			number = {};
		}

/*		unsigned int k = 0;
		for (int i = 0; i < rows; i++) {
			for (int n = 0; n < cols; n++) {
				cout << setw(10) << numbers[k] << ' ';
				if (n != cols - 1) {
					cout << ' ';
				}
				++k;
			}
			if (k != numbers.size()) {
				cout << endl;
			}
		}*/
	}
	return 0;
}