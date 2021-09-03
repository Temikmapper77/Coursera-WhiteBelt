#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a, b, c;

	cin >> a >> b >> c;

	double discr{ (pow(b, 2)) - 4.0 * a * c };

	if ((discr < 0) || ((a == 0) && (b == 0))) {
		return 0;
	}

	if (a == 0) {
		cout << (-c / b);
		return 0;
	}

	if (discr == 0) {
		cout << (-b / (2 * a));
	}
	else {
		double x_1 = ((-b - sqrt(discr)) / (2 * a));
		double x_2 = ((-b + sqrt(discr)) / (2 * a));

		cout << x_2 << " " << x_1;
	}

	return 0;
}