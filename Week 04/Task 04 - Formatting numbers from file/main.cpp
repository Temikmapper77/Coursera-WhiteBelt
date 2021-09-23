#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	ifstream input("input.txt");
	string line;
	while (getline(input, line)) {
		cout << fixed << setprecision(3);
		cout << atof(line.c_str()) << endl;
	}

	return 0;
}