#include <iostream>
using namespace std;

class Base {
	int m_i;
public:
	Base(int x = 0) :m_i(x) { cout << "Base Cons: this= " << this << '\n'; }
	~Base() { cout << "Base Des: this= " << this << '\n'; }
};
class Derived : public Base {
	int m_j;
public:	
	Derived(int y = 1) :m_j(y)  // Base(0)
		{ cout << "Derived Cons: this= " << this << '\n'; }
	~Derived() { cout << "Derived Des: this= " << this << '\n'; }// ~Base()	
};

class MostDerived : public Derived{
	int m_k;
public:
	MostDerived(int z = 2) :m_k(z)  // Derived(1)
	{
		cout << "MostDerived Cons: this= " << this << '\n';
	}
	~MostDerived() { cout << "MostDerived Des: this= " << this << '\n'; }// ~Derived()
};
void size();
int main() {
	//size();
	MostDerived mdObj;
	/*
		sub esp, sizeof(MostDerived)
		push 2		//z
		push &mdObj	//this
		call MostDerived::MostDerived(int y=1)
	*/
	cout << "---------------------\n";
}// mdObj.~MostDerived()

void size() {
	cout << "sizeof(Base): " << sizeof(Base) << endl;
	cout << "sizeof(Derived): " << sizeof(Derived) << endl;
	cout << "sizeof(MostDerived): " << sizeof(MostDerived) << endl;
}