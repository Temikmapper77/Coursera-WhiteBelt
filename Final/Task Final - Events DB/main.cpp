#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

class Date {
public:
    Date() {
        year = 1;
        month = 1;
        day = 1;
    }

    Date(string date_str) {
        ValidateDate(date_str);
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
    string year_s{};
    string month_s{};
    string day_s{};

    int iter{ 0 };

    for (unsigned int i = 0; i < input.size(); i++) {
        if (input[i] == '-') {
            iter++;
            if (i == 0) {
                iter = 0;
            }
        }
        
        if (iter == 0) {
            year_s.push_back(input[i]);
        }
        if (iter == 1) {
            if ((input[i] != '-') & (input[i] != '+')) {
                month_s.push_back(input[i]);
            }
        }
        if (iter == 2) {
            if ((input[i] != '-') & (input[i] != '+')) {
                day_s.push_back(input[i]);
            }
        }
    }

    year = atoi(year_s.c_str());
    month = atoi(month_s.c_str());
    day = atoi(day_s.c_str());
//    cout << "year " << year_s << " month " << month_s << " day " << day_s;

}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) {
        return 1;
        if (lhs.GetMonth() < rhs.GetMonth()) {
            return 1;
            if (lhs.GetDay() < rhs.GetDay()) {
                return 1;
            }
        }
    }
    return 0;
};



class Database {
public:
    void AddEvent(const Date& date, const string& event);
//    bool DeleteEvent(const Date& date, const string& event);
//    int  DeleteDate(const Date& date);

//    void Find(const Date& date) const;

    void Print() const;
private:
    map<Date, set<string>> database;
};

void Database::AddEvent(const Date& date, const string& event) {

    database[date].insert(event);

}

void Database::Print() const {
    for (const auto& date : database) {
        cout << date.first.GetYear() << "."
            << date.first.GetMonth() << "."
            << date.first.GetDay() << ": ";
        for (const auto& event : date.second) {
            cout << event << " ";
        }
        cout << "\n";
    }
}

int main() {
    Database db;

    string command;
    char space_delimiter = ' ';
    
    while (getline(cin, command)) {
        vector<string> words{};

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

        }
        else if (words[0] == "Find") {
            Date date = Date(words[1]);
        }
        else if (words[0] == "Print") {
            db.Print();
        }
        else {
            throw exception("Inv arg");
        }
        
    }

    return 0;
}