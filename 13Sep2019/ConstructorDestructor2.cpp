#include <iostream>
using namespace std;

class cA {
	int m_i;
	int m_j;
public:
	cA() { cout << "Default cA cons: this= " << this << '\n'; m_i = m_j = 0; }
	explicit cA(int x) { cout << "Single param cA cons: this= " << this << '\n'; m_i = m_j = x; }
	cA(int x, int y) { cout << "Multiple Param cA cons: this= " << this << '\n'; m_i = x; m_j = y; }
	void display() { cout << "cA::display: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }

	explicit cA(cA & rhs) { 
		cout << " Copy Constructor: this= " << this << "\n"; 
		this->m_i = rhs.m_i;
		this->m_j = rhs.m_j;
	}
	~cA() { cout << "cA Des: this= " << this << ", m_i= "<<m_i<<", m_j= "<< m_j<< '\n'; }
};

void fun_default() {
	cA obj;
	/*
		sub esp, sizeof(cA)
		push &obj // this
		call cA::cA()
	*/
	
	cout << "------------------\n";
}// obj.~cA()
 // add esp, sizeof(cA)

void fun_single() {
	cA obj(10);
	/*
		sub esp, sizeof(cA)
		push 10 // x
		push &obj // this
		call cA::cA(int)
	*/
	//int i = 10;
	//cA obj2 (20);
	//cA obj2 = 20;
	/*
		cA temp = (cA) 20;
		sub esp, sizeof(cA)
		push (int) temp // x // Copy by value
		push &obj2 // this
		call cA::cA(int)
	*/

	cout << "------------------\n";
}
/*
	obj2.~cA()
	obj.~cA()
	add esp, sizeof(cA) * 2
*/

void fun_multiple() {
	cA obj(40, 50);
	/*
		sub esp, sizeof(cA)
		push 50
		push 40
		push &obj // this
		call cA::cA(int, int)
	*/

	cout << "------------------\n";

}// obj.~cA()
 // add esp, sizeof(cA)


void fun_copy() {
	cA obj(40, 50);
	/*
		sub esp, sizeof(cA)
		push 50	// y
		push 40 // x
		push &obj // this
		call cA::cA(int x, int y)
	*/

	cout << "------------------\n";
	cA clone(obj);
	/*
		sub esp, sizeof(cA)
		push &obj	// cA &rhs
		push &clone	// this
		call cA::cA(cA&)
	*/

	//cA obj2;

	//obj2 = obj;
	cout << "------------------\n";
	//cA clone2 = (cA) obj;
	cA clone2 (obj);

	cout << "------------------\n";

}
 // clone.~cA()
 // obj.~cA()
 // add esp, sizeof(cA) * 2

int main() {
	//fun_default();
	//fun_single();
	//fun_multiple();
	fun_copy();
} 

