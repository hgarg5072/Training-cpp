#include <iostream>
using namespace std;

class cA {
	int m_i; // int m_i = 1234; // allowed in modern C++, not in older version
public:
	cA() { m_i = 0;	cout << " cA::Default Constructor: this= " << this << '\n'; }
	explicit cA(int x) { m_i = x;	cout << " cA::Single param Constructor: this= " << this << '\n'; }
	~cA() { cout << " cA :: Destructor: this= " << this <<": m_i= "<< m_i << '\n'; }
	explicit cA(cA & rhs) { 
		cout << "Copy Constructor: this= " << this<<'\n'; 
		this->m_i = rhs.m_i;
		//this->m_i = (*rhs).m_i;
	}
};

void fun4() {
	cA obj1(10);
	cout << "&obj1 = " << &obj1 << '\n';

	cA obj2(obj1);
	/*
		sub esp, sizeof(cA) // for obj2
		push &obj1 // rhs
		push &obj2 // this
		call cA::cA(cA&)
	*/

	//cA obj4 = obj2;
	cA obj4 (obj2);
	cout << "---------------\n";
}

void fun2() {
	cA obj (1234);
	/*
		sub esp, sizeof(cA)
		push 1234	// x
		push &obj	//this
		call cA::cA(int)
	*/

	//cA obj2 = 456;
	/*
		cA temp = (cA) 456 // extra segement
		sub esp, sizeof(cA)
		push (int)temp	// x
		push &obj2	//this
		call cA::cA(int)
		remove temp // from extra segment
	*/
	cout << "--------------\n";
}

void fun() {
	//cout << "sizeof(cA): " << sizeof(cA) << endl;
	cA obj;
	/*
		sub esp,sizeof(cA)
		push &obj // this
		call cA::cA(void)
	*/
	cout << "&obj = " << &obj << endl;
	cout << "======================\n";
} // obj.~cA()
  // add esp, sizeof(cA) // for obj

int main() {
	//fun();
	//fun2();

	fun4();
	cout << "---------------\n";
}