#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printVector(vector<string> v) {
    for (auto i : v) {
        cout << i << ' ';
    }
}

vector<string> findNames(int year, const map<int, string>& names) {

    vector<string> result = {};

    for (const auto& item : names) {
        if (item.first <= year) {
            if (result.size() == 0) {
                result.push_back(item.second);
            }
            else if (result[result.size() - 1] != item.second) {
                result.push_back(item.second);
            }
        }
    }

    return result;
}

string getNameString(vector<string> names) {
    string result = { '0' };
    if (names.size() > 0) {
        result = names[names.size() - 1];
    }
    if (names.size() > 1) {
        result.append(" (");
        for (unsigned int i = names.size() - 1; i > 0; i--) {
            result.append(names[i - 1]);
            if (i - 1 > 0) {
                result.append(", ");
            }
        }
        result.append(")");
    }
    return result;
}


class Person {
public:
    Person() {

    }

    Person(string first_name, string last_name, int year) {
        year_of_birth = year;
        ChangeFirstName(year, first_name);
        ChangeLastName(year, last_name);
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year >= year_of_birth) {
            first_names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= year_of_birth) {
            last_names[year] = last_name;
        }
    }

    string GetFullName(int year) const {
        if (year < year_of_birth) {
            return "No person";
        }

        bool name_changed = 0;
        bool surname_changed = 0;

        string name = "Undefined";
        string surname = "Undefined";

        for (const auto& item : first_names) {
            if (item.first <= year) {
                name_changed = 1;
                name = item.second;
            }
        }
        for (const auto& item : last_names) {
            if (item.first <= year) {
                surname_changed = 1;
                surname = item.second;
            }
        }
        if ((name_changed == 1) & (surname_changed == 0)) {
            return name + " with unknown last name";
        }
        if ((name_changed == 0) & (surname_changed == 1)) {
            return surname + " with unknown first name";
        }
        if ((name_changed == 1) & (surname_changed == 1)) {
            return name + ' ' + surname;
        }
        return "Incognito";

    }

    string GetFullNameWithHistory(int year) const {
        if (year < year_of_birth) {
            return "No person";
        }
        vector<string> names = { findNames(year, first_names) };
        vector<string> surnames = { findNames(year, last_names) };

        string result_name = getNameString(names);
        string result_surname = getNameString(surnames);

        bool name_changed = { 0 };
        bool surname_changed = { 0 };
        if (result_name != "0") {
            name_changed = 1;
        }
        if (result_surname != "0") {
            surname_changed = 1;
        }

        if ((name_changed == 1) & (surname_changed == 0)) {
            return result_name + " with unknown last name";
        }
        if ((name_changed == 0) & (surname_changed == 1)) {
            return result_surname + " with unknown first name";
        }
        if ((name_changed == 1) & (surname_changed == 1)) {
            return result_name + ' ' + result_surname;
        }
        return "Incognito";
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
    int year_of_birth;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}