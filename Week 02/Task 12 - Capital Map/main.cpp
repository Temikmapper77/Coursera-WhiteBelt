#include <iostream>
#include <map>
#include <string>

using namespace std;

void dumpMap(const map<string, string> m) {

	if (m.size() == 0) {
		cout << "There are no countries in the world";
	}
	else
	{
		for (const auto& item : m) {
			cout << item.first << "/" << item.second << " ";
		}
	}
	cout << "\n";
}

bool isCountryInMap(map<string, string>& capitalsMap, string country) {
	if (capitalsMap.size() == 0) {
		return 0;
	}
	for (const auto& item : capitalsMap) {
		if (item.first == country) {
			return 1;
		}
	}
	return 0;
}

void changeCapital(map<string, string>& capitalsMap, string country, string newCapital) {
	
	if (!isCountryInMap(capitalsMap, country)) {
		capitalsMap[country] = newCapital;
		cout << "Introduce new country " << country << " with capital " << newCapital << "\n";
	}
	else {
		for (const auto& item : capitalsMap) {
			if (item.first == country) {
				if (item.second == newCapital) {
					cout << "Country " << country << " hasn't changed its capital\n";
				}
				else {
					string oldCapital = item.second;
					capitalsMap[country] = newCapital;
					cout << "Country " << country << " has changed its capital from " << oldCapital << " to " << newCapital << "\n";
				}
			}
		}
	}
}

void renameCountry(map<string, string>& capitalsMap, string oldCountryName, string newCountryName) {
	
	if ((!isCountryInMap(capitalsMap, oldCountryName)) || 
		(isCountryInMap(capitalsMap, newCountryName)) || 
		(oldCountryName == newCountryName)) {
		cout << "Incorrect rename, skip\n";
	}
	else {
		string oldCapital = capitalsMap[oldCountryName];
		capitalsMap.erase(oldCountryName);
		capitalsMap[newCountryName] = oldCapital;
		cout << "Country " << oldCountryName << " with capital " << oldCapital << " has been renamed to " << newCountryName << "\n";
	}
}

void aboutCountry(map<string, string>& capitalsMap, string countryName) {
	if (isCountryInMap(capitalsMap, countryName)) {
		cout << "Country " << countryName << " has capital " << capitalsMap[countryName] << "\n";
	}
	else {
		cout << "Country " << countryName << " doesn't exist\n";
	}
}

int main(){

	map<string, string> capitalsMap;

	int operationsCount{};
	cin >> operationsCount;

	for (int i = 0; i < operationsCount; i++) {
		string command;
		cin >> command;

		if (command == "CHANGE_CAPITAL") {

			string country, newCapital;
			cin >> country >> newCapital;

			changeCapital(capitalsMap, country, newCapital);

		}

		if (command == "RENAME") {

			string oldCountryName, newCountryName;
			cin >> oldCountryName >> newCountryName;

			renameCountry(capitalsMap, oldCountryName, newCountryName);
		}

		if (command == "ABOUT") {

			string countryName;
			cin >> countryName;

			aboutCountry(capitalsMap, countryName);
		}

		if (command == "DUMP") {
			dumpMap(capitalsMap);
		}
	}

	return 0;
}