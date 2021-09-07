#include <vector>
#include <iostream>
#include <string>

using namespace std;

void printQueue(vector<bool> queue) {
	for (unsigned int i = 0; i < queue.size(); i++) {
		cout << i << ": " << queue[i] << '\n';
	}
}

int countWorry(vector<bool>& queue) {
	unsigned int peoplesCount = queue.size();
	int worriedPeople = 0;
	for (unsigned i = 0; i < peoplesCount; i++) {
		if (queue[i] == 1) {
			worriedPeople++;
		}
	}

	cout << worriedPeople << "\n";

	return worriedPeople;
}

void addPeople(vector<bool>& queue, int value) {
	unsigned int peoplesCount = queue.size();
	queue.resize(peoplesCount + value);
}

void worryPeople(vector<bool>& queue, int value) {
	unsigned int peoplesCount = queue.size();
	unsigned int index = (unsigned int)value;

	for (unsigned int i = 0; i < peoplesCount; i++) {
		if (i == index) {
			queue[i] = 1;
		}
	}
}

void calmPeople(vector<bool>& queue, int value) {
	unsigned int peoplesCount = queue.size();
	unsigned int index = (unsigned int)value;

	for (unsigned int i = 0; i < peoplesCount; i++) {
		if (i == index) {
			queue[i] = 0;
		}
	}
}


int main() {

	vector<bool> queue{};

	int operationsCount{};
	cin >> operationsCount;

	for (int i = 0; i < operationsCount; i++) {
		string command;
		int value{0};
		
		cin >> command;

		if (command == "WORRY_COUNT") {
			countWorry(queue);
		}
		else {
			cin >> value;
		}
		
		if (command == "COME") {
			addPeople(queue, value);
		}

		if (command == "WORRY") {
			worryPeople(queue, value);
		}

		if (command == "QUIET") {
			calmPeople(queue, value);
		}
	}
//	printQueue(queue);
	return 0;
}