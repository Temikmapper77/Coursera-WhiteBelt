#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	if (y == 0) {
		cout << "Impossible";
		return 0;
	}

	cout << x / y;
	return 0;
}