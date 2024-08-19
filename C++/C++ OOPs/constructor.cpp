#include <iostream>

using namespace std;



class Base {
public:
	Base() {
		cout << "Base class contructor " << endl;
	}
	virtual ~Base() {
		cout << "Base class destructor " << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		cout << "derived class contructor " << endl;
	}
	~Derived() {
		cout << "derived class destructor " << endl;
	}
};





int main(int argc, char const *argv[]) {

	// // Derived d;

	// Base a;

	Base *a = new Derived;

	delete a;

	return 0;
}