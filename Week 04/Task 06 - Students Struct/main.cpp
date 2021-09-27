#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Student {
	string name{};
	string surname{};
	int day{};
	int month{};
	int year{};
};

void printVector(vector<Student> s) {
	for (auto i : s) {
		cout << i.name << ' '
			<< i.surname << ' '
			<< i.day << ' '
			<< i.month << ' '
			<< i.year << '\n';
	}
};

int main() {

	int input_studs_count = {};
	vector<Student> students_list{};

	cin >> input_studs_count;

	for (int i = 0; i < input_studs_count; i++) {
		Student student;
		cin >> student.name >> student.surname >> student.day >> student.month >> student.year;

		students_list.push_back(student);
	}

	int requests_count = {};
	cin >> requests_count;

	for (int i = 0; i < requests_count; i++) {
		string command;
		unsigned int number{};
		bool found = 0;

		cin >> command;
		cin >> number;

		number--;

		if (command == "name") {
			for (unsigned int n = 0; n < students_list.size(); n++) {
				if (n == number) {
					cout << students_list[n].name << ' ' << students_list[n].surname << '\n';
					found = 1;
				}
			}
		}

		if (command == "date") {
			for (unsigned int n = 0; n < students_list.size(); n++) {
				if (n == number) {
					cout << students_list[n].day << '.'
						<< students_list[n].month << '.'
						<< students_list[n].year << '\n';
					found = 1;
				}
			}
		}

		if (found == 0) {
			cout << "bad request\n";
		}
	}

	return 0;
}