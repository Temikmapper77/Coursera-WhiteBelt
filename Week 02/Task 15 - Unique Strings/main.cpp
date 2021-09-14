#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int command;
	cin >> command;

	set<string> words;

	for (int i = 0; i < command; i++) {
		string word;
		cin >> word;
		words.insert(word);
	}
	cout << words.size();
}