#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

bool routeExistance(map<set<string>, int>& routes, set<string> stopNames) {
	if (routes.count(stopNames) == 1) {
		cout << "Already exists for " << routes[stopNames] << "\n";
		return 1;
	}
	return 0;
}

void add_route(map<set<string>, int>& routes, set<string> stopNames) {
	int size = routes.size();
	int currentNumber = size + 1;

	if (routeExistance(routes, stopNames)) {
		return;
	}

	routes[stopNames] = currentNumber;
	cout << "New bus " << currentNumber << "\n";
}



int main() {
	int command;
	cin >> command;

	map<set<string>, int> routes;

	for (int i = 0; i < command; i++) {
		int stopsCount;
		cin >> stopsCount;
		set<string> stopNames;

		for (int n = 0; n < stopsCount; n++) {
			string stopName;
			cin >> stopName;

			stopNames.insert(stopName);
		}
		add_route(routes, stopNames);
	}

	return 0;
}