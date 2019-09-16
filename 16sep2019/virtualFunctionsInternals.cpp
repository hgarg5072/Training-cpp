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
	virtual void fun1() { cout << "Derived::fun1111:this= " << this << '\n'; } // Derived::fun1
	//void fun2() { cout << "Derived::fun2222\n"; } // virtual Derived::fun2	
};
// static void Derived::* vtable[0] = Base::fun1
// static void Derived::* vtable[1] = Derived::fun2 //Base::fun2


int main() {
	Base bObj;
	Derived dObj;
	Base *bp = &dObj;

	((void(*)())(*((long*)(*((long*)bp))))) ();

	((void(*)()) (*(1 + (long*)(*((long*)bp))))) ();
}


int main_02() {
	Base bObj;
	Derived dObj;
	Base *bp = &dObj;

	/*
	1. Derefer bp to reach vptr.
	2. Derefer vptr to reach respective v-table.
	3. Add offset of fun1.
	4. Derefer and get member-function base address.
	5. Pass args and make a call.
	*/
	long * p = (long*)bp;
	long * vptr = (long*)p;
	long *vtable = (long*)*vptr;

	//void (*fp1)();

	//fp1 = ( void (*)()) *vtable;

	//typedef unsigned int UINT;
	//using UINT = unsigned int;
	//UINT ui1, ui2;

	typedef void(*FNPTR)() ;

	FNPTR fp1, fp2;

	fp1 = (FNPTR)*vtable;
	vtable++;
	fp2 = (FNPTR)*vtable;

	fp1();
	fp2();

	return 0;
}









