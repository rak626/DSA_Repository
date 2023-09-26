#include <iostream>

using namespace std;



class Animal {
public:
	int a;
	Animal(){
		a = 0;
	}
	virtual void speak() = 0;
	// virtual void walk() = 0;
};


class Dog : public Animal{

public:
	int a;
	 void speak(){
		a = 200;
		Animal::a = 100;
		cout << "Dog speaking " << a << endl;
	}

	void walk(){
		cout << "dog is walking " << endl;
	}

};


class Lab : public Dog{

	 void speak(){
		cout << "lab is speaking " << endl;
	}

};

class Cat : public Animal{

	void speak(){
		cout << "cat is speaking " << endl;
	}
};

int main(int argc, char const *argv[])
{

	// Dog d;
	// d.speak();

	// d.Animal::speak();

	// // Animal a;
	// // a.speak();

	// Animal *ab = new Dog;

	// // // Animal *abc = new Animal;

	// // // abc->speak();

	// ab->speak();
	

	Animal *adog = new Lab;

	adog->speak();
	return 0;
}






// #include <iostream>

// using namespace std;



// class Animal {
// public:
// 	virtual void speak() = 0;
// 	// virtual void walk() = 0;
// };


// class Dog : public virtual Animal {

// public:
// 	void speak() {
// 		cout << "Dog speaking " << endl;
// 	}

// 	void walk() {
// 		cout << "dog is walking " << endl;
// 	}

// };

// class Cat : public virtual Animal {

// 	void speak() {
// 		cout << "cat is speaking " << endl;
// 	}
// };

// class Lab : public Dog, public  Cat {

// 	void speak() {
// 		cout << "lab is speaking " << endl;
// 	}

// };



// int main(int argc, char const *argv[]) {


// 	Animal *ab = new Dog;

// 	ab->speak();

// 	return 0;
// }