#include <iostream>
using namespace std;

/*
lambda:
 [1] (2) 3 4 {5} 6
 1. Capture
 2. Args.
 3. Mutable
 4. Return
 5. Body

*/
int main() {

	auto fn = []() {};
	/*
	class Lambda1{
	public:
	operator ()() {}
	}
	*/
	cout << "typeid(fn).name(): " << typeid(fn).name() << endl;
}

