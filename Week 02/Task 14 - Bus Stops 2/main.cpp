#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

bool routeExistance(const map<int, vector<string>> routes, vector<string> stopNames) {
	for (const auto& item : routes) {
		if (item.second == stopNames) {
			cout << "Already exists for " << item.first << "\n";
			return 1;
		}
	}
	return 0;
}

void add_route(map<int, vector<string>>& routes, vector<string> stopNames) {
	int size = routes.size();
	int currentNumber = size + 1;

	if (routeExistance(routes, stopNames)) {
		return;
	}
	
	routes[currentNumber] = stopNames;
	cout << "New bus " << currentNumber << "\n";
}

int main() {
	int command;
	cin >> command;

	map<int, vector<string>> routes;

	for (int i = 0; i < command; i++) {
		int stopsCount;
		cin >> stopsCount;
		vector<string> stopNames;

		for (int n = 0; n < stopsCount; n++) {
			string stopName;
			cin >> stopName;

			stopNames.push_back(stopName);
		}
		add_route(routes, stopNames);
	}
}