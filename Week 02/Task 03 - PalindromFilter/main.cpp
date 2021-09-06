#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string inputString) {

	string backwardsString{};

	for (int i = inputString.size() - 1; i >= 0; --i) {
		backwardsString.push_back(inputString[i]);
	}
	return (backwardsString == inputString);
}

vector<string> PalindromFilter(vector<string> words, unsigned int minLength) {
	
	vector<string> result{};

	for (auto w : words) {
		if (IsPalindrom(w)) {
			if (w.size() >= minLength) {
				result.push_back(w);
			}
		}
	}

	return result;
}


int main() {

	vector<string> words{ "abba", "fire", "water", "12321", "-12abccba21-"};
	vector<string> examples{ "weew", "bro", "code" };
	cout << "Words are ";
	for (auto w : examples) {
		cout << w << " ";
	}

	unsigned int minLength{ 4 };
	cout << "\nMin length is " << minLength << "\n";

	vector<string> filteredWords{ PalindromFilter(examples, minLength) };
	
	cout << "Filtered words are ";

	for (auto w : filteredWords) {
		cout << w << " ";
	}

	return 0;
}
