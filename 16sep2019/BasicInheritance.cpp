#include <iostream>
using namespace std;

class Base {
	int m_i;
public:
	Base(int x = 0) :m_i(x) { cout << "Base Cons: this= " << this << '\n'; }
	~Base() { cout << "Base Des: this= " << this << '\n'; }
	void f1() { cout << "Base::f11111\n"; }
};
class Derived : public Base{
	int m_j;
public:
	/*
	Derived(int y = 1) :m_j(y)  // Base(0)
		{ cout << "Derived Cons: this= " << this << '\n'; }
	~Derived() { cout << "Derived Des: this= " << this << '\n'; }// ~Base()
	*/
	void f2() { cout << "Derived::f22222\n"; }
};
int main() {
	//size();
	Derived dObj;
	/*
		sub esp, sizeof(Derived)
		push 1		//y
		push &dObj	//this
		call Derived::Derived(int y=1)
	*/
	dObj.f1();
	dObj.f2();
	cout << "---------------------\n";
}// dObj.~Derived()

void size() {
	cout << "sizeof(Base): " << sizeof(Base) << endl;
	cout << "sizeof(Derived): " << sizeof(Derived) << endl;
}