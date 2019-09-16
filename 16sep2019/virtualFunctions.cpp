#include <iostream>
using namespace std;

struct Base {
	// void *vptr;
	// static void ::* vtable[]
	virtual void fun1() { cout << "Base::fun1111:this= " << this << '\n'; } // Base::fun1
	virtual void fun2() { cout << "Base::fun2222:this= " << this << '\n'; } // virtual Base::fun2
};

// static void Base::* vtable[0] = Base::fun1
// static void Base::* vtable[1] = Base::fun2

struct Derived : Base {
	// static void ::* vtable[]
	//virtual void fun1() { cout << "Derived::fun1111:this= " << this << '\n'; } // Derived::fun1
	void fun2() { cout << "Derived::fun2222\n"; } // Derived::fun2	
};
// static void Derived::* vtable[0] = Base::fun1
// static void Derived::* vtable[1] = Derived::fun2 //Base::fun2

int main() {
	Base bObj;
	Derived dObj;

	Base *bp = &dObj;

	bp->fun1();
	/*
	1. Derefer bp to reach vptr.
	2. Derefer vptr to reach respective v-table.
	3. Add offset of fun1.
	4. Derefer and get member-function base address.
	5. Pass args and make a call.
	*/

	bp->fun2();
}






void callback(Base &bRef) {
	bRef.fun1();
	bRef.fun2(); // call ?::fun2
	cout << "-----------------\n";
}



int main_01() {
	Derived dObj;

	//callback(dObj);
	cout << "sizeof(Base): " << sizeof(Base) << endl;
	cout << "sizeof(Derived): " << sizeof(Derived) << endl;
	return 0;
}
