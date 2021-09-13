#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> vec) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}
}

void printAllBuses(const map<string, vector<string>> busesMap) {
	if (busesMap.size() == 0) {
		cout << "No buses\n";
	}
	else {
		for (const auto& item : busesMap) {
			cout << "Bus " << item.first << ": ";
			printVector(item.second);
			cout << "\n";
		}
	}

}

void printBusesForStop(const map<string, vector<string>> stopsMap, string stopName) {
	if (stopsMap.count(stopName) == 0) {
		cout << "No stop\n";
	}
	else 
	{
		for (const auto& item : stopsMap) {
			if (item.first == stopName) {
				printVector(item.second);
			}
		}
		cout << "\n";
	}
}

vector<string> getStopsForBus(const map<string, vector<string>> busesMap, string busName) {
	vector<string> stops;

	for (const auto& item : busesMap) {
		if (item.first == busName) {
			stops = item.second;
		}
	}

	return stops;
}

vector<string> getBusesForStop(const map<string, vector<string>> stopsMap, string stopName) {
	vector<string> buses;

	for (const auto& item : stopsMap) {
		if (item.first == stopName) {
			buses = item.second;
		}
	}

	return buses;

}

vector<string> subtractCurBus(vector<string> buses, string busName) {
	vector<string> result;

	if (buses.size() == 1) {
		result.push_back("no interchange");
		return result;
	}

	for (const auto& item : buses) {
		if (item != busName) {
			result.push_back(item);
		}
	}

	return result;
}

void printStopsForBus(const map<string, vector<string>> busesMap, const map<string, vector<string>> stopsMap, string busName) {
	if (busesMap.count(busName) == 0) {
		cout << "No bus\n";
	}
	else {
		map<string, vector<string>> chosenBuses;
		vector<string> stops = getStopsForBus(busesMap, busName);
		

		for (const auto& item : stops) {
			vector<string> buses;
			buses = getBusesForStop(stopsMap, item);
			buses = subtractCurBus(buses, busName);
			cout << "Stop " << item << ": ";
			printVector(buses);
			cout << "\n";
		}
	}
}


void addNewBus(map<string, vector<string>>& busesMap, string busName, vector<string>stopsNames) {
	busesMap[busName] = stopsNames;
}

void addNewStops(map<string, vector<string>>& stopsMap, string busName, vector<string> stopsNames) {
	for (int unsigned i = 0; i < stopsNames.size(); i++) {
		stopsMap[stopsNames[i]].push_back(busName);
	}
}

int main() {
	map<string, vector<string>> busesMap;
	map<string, vector<string>> stopsMap;

	int operationsCount{};
	cin >> operationsCount;

	for (int i = 0; i < operationsCount; i++) {
		string command;
		cin >> command;

		if (command == "NEW_BUS") {
			string busName;
			int stopsCount;
			string stopName;
			vector<string> stopsNames;

			cin >> busName >> stopsCount;

			for (int k = 0; k < stopsCount; k++) {
				cin >> stopName;
				stopsNames.push_back(stopName);
			}

			addNewBus(busesMap, busName, stopsNames);
			addNewStops(stopsMap, busName, stopsNames);
		}

		if (command == "BUSES_FOR_STOP") {
			string stopName;

			cin >> stopName;

			printBusesForStop(stopsMap, stopName);
		}

		if (command == "STOPS_FOR_BUS") {
			string busName;

			cin >> busName;

			printStopsForBus(busesMap, stopsMap, busName);
		}

		if (command == "ALL_BUSES") {
			printAllBuses(busesMap);
		}

	}

	return 0;
}