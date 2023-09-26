#include <iostream>
// #pragma pack(1)
using namespace std;

class Hero {

	char a;
	char b;
	int c;
	long d;

};

int main(){

	int x{10};
	char y{'A'};

	const int* i = &x;
	const char* j = &y;

	x = 5 , y = 'B';

	int c = 0;
	i = &c;

	cout << "i : " << *i << endl;
	cout << "j : " << *j << endl;

	int* const p = &x;
	char* const q = &y;

	x = 100;
	y = 'Z';

	cout << "p : " << *p << endl;
	cout << "q : " << *q <<endl;


	// Hero h1, h2;
	// cout << sizeof(h1) << endl;
	// cout << sizeof(h2) << endl;


	return 0;
}