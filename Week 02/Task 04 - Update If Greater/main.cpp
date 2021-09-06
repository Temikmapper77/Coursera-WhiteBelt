#include <iostream>

using namespace std;

void UpdateIfGreater(int a, int& b) {
	if (a > b) {
		b = a;
	}
}

int main() {
	
//	int a{ 5 };
	int b{ 2 };

	UpdateIfGreater(7, b);

	cout << "b is " << b;
	return 0;
}