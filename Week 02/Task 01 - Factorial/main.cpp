#include <iostream>

int Factorial(int x) {

	if (x < 0) {
		return 1;
	}

	int result{ 1 };

	for (int i = 1; i <= x; i++) {
		result *= i;
	}

	return result;
}

int main() {

	int input{};

	std::cin >> input;

	std::cout << Factorial(input);

	return 0;
}