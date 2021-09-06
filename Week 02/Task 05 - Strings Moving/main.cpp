#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	
	for (auto w : source) {
		destination.push_back(w);
	}

	source.clear();
}

int main() {

	vector<string> source{ "a", "b", "c" };
	vector<string> destination{ "z" };

	for (auto w : destination) {
		cout << w << " ";
	}

	cout << "\n--------MoveStrings()---------\n";
	MoveStrings(source, destination);

	for (auto w : source) {
		cout << w << " ";
	}

	return 0;
}