#include <iostream>
#include <map>
#include <string>

using namespace std;

void printMap(const map<char, int> m){
	for (const auto& item : m) {
		cout << item.first << ": " << item.second << "\n";
	}
}

void compare() {
	map<char, int> counter1, counter2;

	string word1, word2;
	cin >> word1 >> word2;
	
	for (char ch : word1) {
		counter1[ch]++;
	}
	for (char ch : word2) {
		counter2[ch]++;
	}


	if (counter1 == counter2) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

//	printMap(counter1);
//	printMap(counter2);
}

int main() {

	int operationsCount{};
	cin >> operationsCount;

	for (int i = 0; i < operationsCount; i++) {
		compare();
	}

	return 0;
}
