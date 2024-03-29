#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        sorted_strings.push_back(s);
        SortStrings();
    }
    vector<string> GetSortedStrings() {
        return sorted_strings;
    }
private:
    vector<string> sorted_strings;
    void SortStrings() {
        sort(begin(sorted_strings), end(sorted_strings));
    }
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}

