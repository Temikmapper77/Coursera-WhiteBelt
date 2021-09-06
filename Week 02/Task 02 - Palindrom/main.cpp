#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string inputString) {

	string backwardsString{};

	for (int i = inputString.size()-1; i >= 0; --i) {
		backwardsString.push_back(inputString[i]);
	}
	return (backwardsString == inputString);
}

int main() {

	string input;

	cin >> input;

	cout << IsPalindrom(input);

	return 0;
}