#include <iostream>
using namespace std;

#if 0
class cA {
	int m_i;
	int m_j;
public:
	cA(int x = 0, int y = 1) { m_i = x; m_j = y; }
	~cA() { cout << "~cA: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }
	void fun2() {}
	void fun4 () const {}
	//void __thiscall display(cA *const this) 
	//void __thiscall display( const cA *const this) 
	void display() const {
		//const cA *const temp = this;

		cout << "~cA: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; 
		//this->m_i = 1234; // this->m_i = 1234;
		//this->m_j = 5678;
		//m_i = 678;
		//fun2();
		fun4();
	}
};

int main() {
	cA obj(10, 20);

	obj.display();
	cout << "-----------------\n";
}

#endif



class cA {
	int m_i;
	mutable int m_j;
public:
	cA(int x = 0, int y = 1) { m_i = x; m_j = y; }
	~cA() { cout << "~cA: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }
	void display() const {
		cout << "~cA: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n';
		//this->m_i = 1234; // this->m_i = 1234;
		this->m_j = 5678;
	}
};

int main() {
	cA obj(10, 20);

	obj.display();
}