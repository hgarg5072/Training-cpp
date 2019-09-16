#include <iostream>
using namespace std;

struct Base {
	void fun1() { cout << "Base::fun1111:this= "<< this<<'\n'; } // Base::fun1
	void fun2() { cout << "Base::fun2222:this= " << this << '\n'; } // Base::fun2
};

struct Derived : Base {
	void fun2() { cout << "Derived::fun2222\n"; } // Derived::fun2	
};

int main() {
	cout << "sizeof(Base): " << sizeof(Base) << endl;
	cout << "sizeof(Derived): " << sizeof(Derived) << endl;
}

void callback(Base &bRef) { // LSP
	cout << " Allocate resources...\n";
	bRef.fun1();
	bRef.fun2(); // call Base::fun2
	cout << " Deallocate resources...\n";
	cout << "------------------\n";
}
int main_01() {
	Base bObj;
	Derived dObj;

	Base *bp = &dObj; //LSP // &bObj;
	Base &bRef = dObj; //LSP // bObj;
	cout << " &bObj= " << &bObj << '\n';
	cout << " &dObj= " << &dObj << '\n';
	callback(bObj);
	callback(dObj);
	return 0;
}