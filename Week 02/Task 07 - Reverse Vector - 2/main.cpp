#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {

	vector<int> result{};

	for (int i = v.size() - 1; i >= 0; --i) {
		result.push_back(v[i]);
	}

	return result;
}


int main() {

	vector<int> numbers = { 1, 5, 3, 4, 2 };

	for (auto i : numbers) {
		cout << i << " ";
	}

	vector<int> reversed{ Reversed(numbers) };
	cout << "\n------Reverse()-----\n";
	for (auto i : reversed) {
		cout << i << " ";
	}

	return 0;
}