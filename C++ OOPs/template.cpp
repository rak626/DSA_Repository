#include <iostream>

using namespace std;

template<class T, class R>
T fun(T x, R y){
	return(T)(x + y);
}


int main(int argc, char const *argv[]) {

	auto ans  =fun(10, 9.4);

	cout << typeid(ans).name() << endl;

	cout << ans << endl;

	cout << fun(10, 5.0) << endl;

	
	return 0;
}