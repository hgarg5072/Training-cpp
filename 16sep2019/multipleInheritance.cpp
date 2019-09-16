#include <iostream>
using namespace std;

class Base1 {
	int m_i1;
public:
	Base1(int x1 = -1) :m_i1(x1) { cout << "Base111 Cons: this= " << this << '\n'; }
	~Base1() { cout << "Base111 Des: this= " << this << '\n'; }
};

class Base2 {
	int m_i2;
public:
	Base2(int x2 = 0) :m_i2(x2) { cout << "Base2 Cons: this= " << this << '\n'; }
	~Base2() { cout << "Base2 Des: this= " << this << '\n'; }
};

class Derived : public Base1, public Base2 {
	int m_j;
public:
	Derived(int y = 1) :m_j(y)  // Base1(-1), Base2(0)
	{
		cout << "Derived Cons: this= " << this << '\n';
	}
	~Derived() { cout << "Derived Des: this= " << this << '\n'; }// ~Base2(), ~Base1()	
};
void size() {
	cout << "sizeof(Base1): " << sizeof(Base1) << endl;
	cout << "sizeof(Base2): " << sizeof(Base2) << endl;
	cout << "sizeof(Derived): " << sizeof(Derived) << endl;
}

int main() {
	//size();
	Derived dObj;
}