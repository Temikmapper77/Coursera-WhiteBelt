#include <iostream>

using namespace std;


/*
	100 100 100

*/
int main() {

	double inputPrice, firstLimit, firstDiscount, secondLimit, secondDiscount;

	cin >> inputPrice >> firstLimit >> secondLimit >> firstDiscount >> secondDiscount;


	if ((inputPrice <= firstLimit) && (inputPrice <= secondLimit)) {

		cout << inputPrice;

		return 0;
	}

	if ((inputPrice > firstLimit) && (inputPrice <= secondLimit)) {

		double firstPrice;

		firstPrice = inputPrice * (100 - firstDiscount) * 0.01;

		cout << firstPrice;

		return 0;
	}

	if ((inputPrice > firstLimit) && (inputPrice > secondLimit)) {
		double secondPrice;

		secondPrice = inputPrice * (100 - secondDiscount) * 0.01;

		cout << secondPrice;

		return 0;
	}

	return 0;
}