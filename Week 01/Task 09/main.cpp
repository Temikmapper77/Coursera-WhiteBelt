#include <iostream>
#include <vector>

using namespace std;

int main() {

	int input;
	vector <int> num;

	cin >> input;

	while (input > 0) {
		int result = input % 2;
		if (result == 0) {
			num.push_back(0);
		}
		else {
			num.push_back(1);
		}
		input = input / 2;
	}

	for (unsigned int i = num.size(); i > 0; --i) {
		cout << num[i-1];
	}

	return 0;
}