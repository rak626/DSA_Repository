#include <iostream>

using namespace std;



class Animal {
public:
	static int cnt;
	int a;

	Animal(){
		a = 0;
		cnt++;
	}

	static int getCnt(){
		// a++;
		return ++cnt;
	}
};


int Animal::cnt = 0;


int main(int argc, char const *argv[]) {


	Animal a, b, c, d, e;

	cout << a.getCnt() << endl;
	cout << b.getCnt() << endl;
	// cout << Animal::getCnt() << endl;

	
	return 0;
}