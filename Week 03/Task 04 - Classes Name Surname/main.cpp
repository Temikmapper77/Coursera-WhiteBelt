#include <string>
#include <iostream>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
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
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}