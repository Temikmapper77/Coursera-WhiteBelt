#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		
	};
	ReversibleString(string s) {
		original = s;
	};
	void Reverse() {
		reverse(original.begin(), original.end());
	};
	string ToString() const {
		return original;
	};
private:
	string original;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	ReversibleString t("");
	t.Reverse();
	cout  << "check " << t.ToString() << endl;

	ReversibleString m("hello moto");
	m.Reverse();
	cout << "multi " << m.ToString() << endl;


	return 0;
}

