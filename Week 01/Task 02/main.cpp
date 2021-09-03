#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string input1, input2, input3;
	string result;

	cin >> input1 >> input2 >> input3;

	if ((input1 <= input2) && (input1 <= input3)) {
		result = input1;
	};
	if ((input2 <= input1) && (input2 <= input3)) {
		result = input2;
	};
	if ((input3 <= input1) && (input3 <= input2)) {
		result = input3;
	};

	cout << result;

	return 0;
}