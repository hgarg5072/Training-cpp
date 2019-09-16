#include <iostream>
using namespace std;

class cA { // #4
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << "cA Cons: this= " << this << '\n'; }
	void fun1() { cout << "cA::fun11111\n"; }
	~cA() { cout << "cA Des:this = " << this << '\n'; }
};
class cB { // Contained Class
	int m_j; // #4
public:
	cA aObj; // #4 // Contained Object
	
	cB(int y = 1) :m_j(y) // aObj.cA(0)
		{ cout << "cB Cons: this= " << this << '\n'; }
	~cB() { cout << "cB Des:this = " << this << '\n'; } // aObj.~cA()
	
	// Compiler synthesizes
	// cB() : aObj(0){}
	// ~cB(){} aObj.~cA()
	void afun1() { aObj.fun1(); }
};
int main() {
	//size();
	cB bObj;
	/*
		sub esp, sizeof(cB)
		push 1		//y
		push &bObj	//this
		call cB::cB(int y=1)
	*/

	bObj.aObj.fun1();
	bObj.afun1();
	cout << "--------------\n";
} /*
	push &bObj	// this
	call cB::~cB()
	add esp, sizeof(cB)
  */


void size() {
	cout << "sizeof(cA): " << sizeof(cA) << '\n';
	cout << "sizeof(cB): " << sizeof(cB) << '\n';
}
