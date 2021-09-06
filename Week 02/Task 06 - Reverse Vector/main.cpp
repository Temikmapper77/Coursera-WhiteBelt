#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
	 
	vector<int> tmp{};

	for (int i = v.size()-1; i >= 0; --i) {
		tmp.push_back(v[i]);
	}

	v = tmp;
}


int main() {

	vector<int> numbers = { 1, 5, 3, 4, 2 };

	for (auto i : numbers) {
		cout << i << " ";
	}
	
	Reverse(numbers);
	cout << "\n------Reverse()-----\n";
	for (auto i : numbers) {
		cout << i << " ";
	}

	return 0;
}