
class Incognizable {
public:
	Incognizable() {};
	Incognizable(int a) {
		return;
	};
	Incognizable(int a, int b) {
		return;
	};
};

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}