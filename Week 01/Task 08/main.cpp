#include <iostream>

using namespace std;

int main() {

	int a, b;

	cin >> a >> b;

	int divident{ a };
	int theBiggestDivider{ 1 };

	if (a > b) divident = b;

	for (int divider = 1; divider <= divident; divider++) {

		if (((a % divider) == 0) && ((b % divider) == 0)) {
			theBiggestDivider = divider;
		}

	}

	cout << theBiggestDivider;
}