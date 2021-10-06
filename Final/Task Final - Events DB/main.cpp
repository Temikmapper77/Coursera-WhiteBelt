#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

class Date {
public:
	Date() {
		year = 1;
		month = 1;
		day = 1;
	}

	Date(string date_str) {
		try {
			ValidateDate(date_str);
		}
		catch (invalid_argument& err) {
			std::cout << err.what() << "\n";
			exit(-1);
		}
		catch (exception) {
			std::cout << "Wrong date format: " << date_str << "\n";
			exit(-2);
		}

	}

	void SetYear(int i_year) {
		year = i_year;
	}
	void SetMonth(int i_month) {
		month = i_month;
	}
	void SetDay(int i_day) {
		day = i_day;
	}

	int GetYear() const {
		return year;
	};
	int GetMonth() const {
		return month;
	};
	int GetDay() const {
		return day;
	};
private:
	void ValidateDate(string input);
	int year;
	int month;
	int day;
};

void Date::ValidateDate(string input) {
	stringstream date_str;
	date_str << input;

	int year_i{ 0 };
	int month_i{ 0 };
	int day_i{ 0 };
	char sign_m;
	char sign_d;
	if ((date_str >> year_i >> sign_m >> month_i >> sign_d >> day_i) && (date_str.peek() == EOF)) {

		if (sign_m != '-' || sign_d != '-') {
			throw exception();
		}
		if ((month_i > 12) || (month_i <= 0)) {
			string error_msg = "Month value is invalid: " + to_string(month_i);
			throw invalid_argument(error_msg);
		}
		if ((day_i > 31) || (day_i <= 0)) {
			string error_msg = "Day value is invalid: " + to_string(day_i);
			throw invalid_argument(error_msg);
		}

		year = year_i;
		if (year_i < 0) {
			return;
		}
		month = month_i;
		day = day_i;
	}
	else {
		//        cout << sign_m << "  " << month_i;
		throw exception();
	}
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) {
		return 1;
	}
	else if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() < rhs.GetMonth()) {
			return 1;
		}
		else if (lhs.GetMonth() == rhs.GetMonth()) {
			if (lhs.GetDay() < rhs.GetDay()) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
};



class Database {
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);
	void Find(const Date& date);
	void Print() const;
private:
	map<Date, set<string>> database;
};

void Database::AddEvent(const Date& date, const string& event) {
	if (date.GetYear() >= 0) {
		database[date].insert(event);
	}
}

bool Database::DeleteEvent(const Date& date, const string& event) {

	if (database[date].count(event) == 1) {
		database[date].erase(event);
		if (database[date].empty()) {
			database.erase(date);
		}
		cout << "Deleted successfully\n";
		return 1;
	}
	else {
		cout << "Event not found\n";
		return 0;
	}

}

int Database::DeleteDate(const Date& date) {
	if (database.count(date) == 1) {
		int events_count = database[date].size();
		cout << "Deleted " << events_count << " events\n";
		database.erase(date);
		return events_count;
	}
	else {
		cout << "Deleted 0 events\n";
		return 0;
	}
}

void Database::Print() const {
	for (const auto& date : database) {
		for (const auto& event : date.second) {
			cout << setw(4) << setfill('0') << date.first.GetYear() << "-";
			cout << setw(2) << setfill('0') << date.first.GetMonth() << "-";
			cout << setw(2) << setfill('0') << date.first.GetDay() << " ";
			cout << event << "\n";
		}
	}
}

void Database::Find(const Date& date) {
	if (database.count(date) == 1) {
		for (const auto& event : database[date]) {
			cout << event << "\n";
		}
	}
}

int main() {
	Database db;

	string command;
	char space_delimiter = ' ';

	while (getline(cin, command)) {
		vector<string> words{};
		if (command == "") {
			continue;
		}
		stringstream sstream(command);
		string word;
		while (getline(sstream, word, space_delimiter)) {
			words.push_back(word);
		}
		if (words[0] == "Add") {
			Date date{ Date(words[1]) };
			string event{ words[2] };
			db.AddEvent(date, event);
		}
		else if (words[0] == "Del") {
			Date date{ Date(words[1]) };
			if (words.size() == 3) {
				string event{ words[2] };
				db.DeleteEvent(date, event);
			}
			else {
				db.DeleteDate(date);
			}
		}
		else if (words[0] == "Find") {
			Date date = Date(words[1]);
			db.Find(date);
		}
		else if (words[0] == "Print") {
			db.Print();
		}
		else {
			cout << "Unknown command: " << words[0] << "\n";
			return 0;
		}
	}
	return 0;
}