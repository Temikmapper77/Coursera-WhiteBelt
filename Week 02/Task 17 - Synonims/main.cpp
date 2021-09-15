#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>

using namespace std;

void printSet(set<string> s) {
	for (const auto& item : s) {
		cout << item << ' ';
	}
}

void printMap(const map<string, set<string>> s) {
	if (s.size() == 0) {
		cout << "No words\n";
	}
	else {
		for (const auto& item : s) {
			cout << item.first << ": ";
			printSet(item.second);
			cout << "\n";
		}
	}

}

void addWords(map<string, set<string>>& sinonyms, string word_1, string word_2) {
	sinonyms[word_1].insert(word_2);
	sinonyms[word_2].insert(word_1);
}

void countSynonims(map<string, set<string>>& synonims, string word) {

	if (synonims.count(word)) {
		cout << synonims[word].size() << "\n";
	}
	else {
		cout << "0\n";
	}
}

void checkWords(map<string, set<string>>& synonims, string word_1, string word_2) {

	bool result = 0;

	if (synonims.count(word_1)) {
		if (synonims[word_1].count(word_2)) {
			result = 1;
		}
	}

	(result == 0) ? cout << "NO\n" : cout << "YES\n";
}

int main() {

	map<string, set<string>> synonims;

	int operationsCount{};
	cin >> operationsCount;

	for (int i = 0; i < operationsCount; i++) {
		string command;
		cin >> command;

		if (command == "ADD") {
			string word_1, word_2;
			cin >> word_1 >> word_2;

			addWords(synonims, word_1, word_2);
		}

		if (command == "COUNT") {
			string word;
			cin >> word;

			countSynonims(synonims, word);
		}

		if (command == "CHECK") {
			string word_1, word_2;
			cin >> word_1 >> word_2;

			checkWords(synonims, word_1, word_2);
		}

		if (command == "PRINT") {
			printMap(synonims);
		}
	}
	return 0;
}

/*
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
PRINT

*/