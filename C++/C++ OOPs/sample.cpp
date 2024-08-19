#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle();
    Rectangle(int length,int breadth);
    Rectangle(Rectangle *rec);
    int getLength();
    int getbreadth();
    void setLength(int);
    void setBreadth(int);
    int area();
    int perimeter();
    Rectangle operator+(Rectangle temp);
    friend Rectangle operator*(Rectangle temp1, Rectangle temp2);
    // ~Rectangle();
};

//default constuctor
Rectangle::Rectangle(){
    length = 1;
    breadth = 1;
}
// parameterized constructor
Rectangle::Rectangle(int length, int breadth){
    setLength(length);
    setBreadth(breadth);
}
// copy constructor
Rectangle::Rectangle(Rectangle *rec){
    this->length = rec->length;
    this->breadth = rec->breadth;
}
int Rectangle::getLength() {
    return this->length;
}


void Rectangle::setLength(int length) {
    this->length = length < 0 ? 1 : length;
}

void Rectangle::setBreadth(int breadth) {
    this->breadth = breadth < 0 ? 1 : breadth;
}
int Rectangle:: getbreadth() {
    return this->breadth;
}
int Rectangle::area() {
    return this->length * this->breadth;
}
int Rectangle::perimeter() {
    return (this->breadth + this->length) * 2;
}

// operator overloading
Rectangle Rectangle::operator+(Rectangle temp){
    Rectangle rec;
    rec.length = this->length + temp.length;
    rec.breadth = this->breadth + temp.breadth;
    return rec;
}

Rectangle operator*(Rectangle temp1, Rectangle temp2){
    Rectangle rec;
    rec.breadth = temp1.breadth * temp2.breadth;
    rec.length = temp1.length * temp2.breadth;
    return rec;
}


int main() {
    cout << "--------object store in heap memory---------" << endl;
    // store in heap memory
    Rectangle* r = new Rectangle();
    r->setLength(10);
    r->setBreadth(20);
    cout << r->area() << endl;
    cout << r->perimeter() << endl;

    cout << "--------object store in stack memory---------" << endl;

    // store in stack memory
    Rectangle r2;
    r2.setLength(15);
    r2.setBreadth(2);
    cout << r2.area() << endl;
    cout << r2.perimeter() << endl;

    cout << "--------constructor---------" << endl;

    // using constructore

    Rectangle* r3 = new Rectangle(10, 20);
    Rectangle r4(30, 40);
    Rectangle r5(r4);
    cout << r3->area() << endl;
    cout << r4.perimeter() << endl;
    cout << r5.area() << endl;

    cout << "-------operator overloading----------" << endl;


    Rectangle r6;
    r6 = r4 + r5;
    cout << r6.area() << endl;

    Rectangle r7 = r5 + r3;

    // friend function

    Rectangle r8 = r7 + r3;
    cout << r8.perimeter() << endl;
}