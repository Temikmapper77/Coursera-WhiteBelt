#include <iostream>

using namespace std;

void EnsureEqual(string left, string right) {
    if (left != right) {
        throw runtime_error(left + " != " + right);
    }
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}