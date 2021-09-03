#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;

	cin >> input;

	int countOfF{ 0 };

	for (unsigned int i = 0; i < input.size(); i++) {
		if (input[i] == 'f') {
			countOfF++;

			if (countOfF == 2) cout << i;
		}
	}

	if (countOfF == 0) cout << -2;
	if (countOfF == 1) cout << -1;

	return 0;
}