#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void printVector(const vector<int>& v) {
	for (const auto& i : v) {
		cout << i << ' ';
	}
}

bool compareByModule(int x, int y) {
	return (abs(x) < abs(y));
}

int main() {
	int count_of_nums;
	vector<int> nums;
	cin >> count_of_nums;

	for (int i = 0; i < count_of_nums; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	
	sort(begin(nums), end(nums), compareByModule);
	printVector(nums);
	return 0;
	
}