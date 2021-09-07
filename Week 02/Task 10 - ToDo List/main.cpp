#include <vector>
#include <iostream>
#include <string>

using namespace std;

void printMonth(vector<vector<string>>& tasks) {
	unsigned int daysInMonth = tasks.size();

	for (unsigned int i = 0; i < daysInMonth; i++) {
		unsigned int tasksCount = tasks[i].size();
		if (tasksCount == 0) {
			cout << i+1 << ": " << "0\n";
		}
		else {
			cout << i+1 << ": ";
			for (unsigned int k = 0; k < tasksCount; k++) {
				cout << "\t" << k+1 << ": " << tasks[i][k] << "\n";
			}
		}
	}
}

void nextMonth(vector<vector<string>>& tasks, unsigned int lastDay) {
	unsigned int currentLastDay = tasks.size();

	if (currentLastDay > lastDay) {
		unsigned int difference = currentLastDay - lastDay;
		for (unsigned int i = 1; i <= difference; i++) {
			tasks[lastDay-1].insert(tasks[lastDay-1].end(), tasks[lastDay-1 + i].begin(), tasks[lastDay-1 + i].end());
		}
	}
	tasks.resize(lastDay);
}

void dumpTasks(vector<vector<string>>& tasks, int day) {
	unsigned int tasksCount = tasks[day-1].size();

	if (tasksCount == 0) {
		cout << "0\n";
	}
	else {
		cout << tasksCount << ' ';
		for (unsigned int i = 0; i < tasksCount; i++) {
			cout << tasks[day-1][i] << ' ';
		}
		cout << "\n";
	}
}

void addTask(vector<vector<string>>& tasks, int day, string task) {
	tasks[day-1].push_back(task);
}

int main() {

	vector<unsigned int> daysInMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<vector<string>> tasks;

	int operationsCount{};
	cin >> operationsCount;

	int currentMonth = 0;
	tasks.resize(daysInMonth[currentMonth]);
	for (int i = 0; i < operationsCount; i++) {
		string command;
		int day{ 0 };
		string task;

		cin >> command;

		if (command == "NEXT") {
			currentMonth++;
			if (currentMonth == 12) {
				currentMonth = 0;
			}
			nextMonth(tasks, daysInMonth[currentMonth]);
		}

		if (command == "DUMP") {
			cin >> day;
			dumpTasks(tasks, day);
		}
		
		if (command == "ADD") {
			cin >> day;
			cin >> task;
			addTask(tasks, day, task);
		}

		if (command == "PRINT") {
			printMonth(tasks);
		}
	}
	return 0;
}

/*

8
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 28
ADD 28 Payment
DUMP 28

*/