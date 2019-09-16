#include <iostream>
using namespace std;

struct Base {
	void fun1() { cout << "Base::fun1111\n"; } // Base::fun1
	void fun2() { cout << "Base::fun2222\n"; } // Base::fun2
};

struct Derived : Base {
	void fun2() { cout << "Derived::fun2222\n"; } // Derived::fun2
	void bfun2() { Base::fun2(); }
};

int main() {
	Derived dObj;

	dObj.fun1(); // call Base::fun1
	
	dObj.fun2(); // call Derived::fun2
	dObj.Base::fun2(); // call Base::fun2 // hidden function

	dObj.bfun2();
}