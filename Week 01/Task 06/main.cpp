#include <iostream>

using namespace std;

int main() {
	int x{1}, y{1};

	cin >> x >> y;

	for (int i = x; i <= y; i++) {
		if (i % 2 == 0) {
			cout << i << " ";
		}
	}
}