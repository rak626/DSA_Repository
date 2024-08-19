#include <iostream>

using namespace std;

class Human {
	int age;
	int height;
	int weight;
public:
	int getAge() {
		return this-> age;
	}
	void setWeight(int weight) {
		this->weight = weight;
	}
};


class male : public Human {


public:
	void setHeight(int height){
		this->setHeight(height);
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}