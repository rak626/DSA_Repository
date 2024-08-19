#include <iostream>
using namespace std;
class construct {
public:
	int a, b;
// Parameterized Constructor
	construct() {

	}
	construct(int x, int y) {
		a = x;
		b = y;
	}
	friend construct add(construct c1, construct c2);
};


construct add(construct c1, construct c2) {
	construct c3(c1.a + c2.a , c1.b + c2.b);
	return c3;
}

int main() {
// Parameterized constructor is called
	construct c(40, 50), d(10, 20), e;
	cout << "a: " << c.a << endl << "b: " << c.b << endl;
	e = add(c, d);
	cout << "a: " << e.a << endl << "b: " << e.b;

	return 0;
}