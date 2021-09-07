#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> v) {
	for (auto i : v) {
		cout << i << ' ';
	}
}

vector<int> getTemperatures(int daysCount) {
	vector<int>temperatures;
	int temp;
	for (int i = 0; i < daysCount; i++) {
		cin >> temp;
		temperatures.push_back(temp);
	}

	return temperatures;
}

int getMediumTemp(vector<int> temperatures) {

	int sum{ 0 };
	for (unsigned i = 0; i < temperatures.size(); i++) {
		sum += temperatures[i];
	}

	int medium = (sum / temperatures.size());

//	cout << "\nMedium is " << medium << '\n';

	return medium;
}

vector<int> filterTemperatures(int mediumTemp, vector<int> inputTemperatures) {
	vector<int> filteredDays{};

	for (unsigned int i = 0; i < inputTemperatures.size(); i++) {
		if (inputTemperatures[i] > mediumTemp) {
			filteredDays.push_back(i);
		}
	}

	return filteredDays;
}

int main() {

	int daysCount{};

	cin >> daysCount;
	cin.ignore(5, '\n');

	vector<int> temp{ getTemperatures(daysCount) };

	if (temp.size() != 0) {
		int medium = getMediumTemp(temp);

		vector<int>filteredDays{ filterTemperatures(medium, temp) };
		cout << filteredDays.size() << endl;
		printVector(filteredDays);
	}
	else {
		cout << 0;
	}
	
	return 0;
}