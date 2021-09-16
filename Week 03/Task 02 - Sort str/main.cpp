#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void printVector(const vector<string>& v) {
	for (const auto& i : v) {
		cout << i << ' ';
	}
}

bool compareStrings(string x, string y) {

	for (auto& ch : x) {
		ch = char(tolower(ch));
	}
	for (auto& ch : y) {
		ch = char(tolower(ch));
	}
	return (x < y);
}

int main() {
	int count_of_strings;
	vector<string> strs;
	cin >> count_of_strings;

	for (int i = 0; i < count_of_strings; i++) {
		string str;
		cin >> str;
		strs.push_back(str);
	}

	sort(begin(strs), end(strs), compareStrings);
	printVector(strs);
	return 0;
}