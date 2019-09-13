#include <iostream>
using namespace std;

class cA {
	int m_i;
	int m_j;
public:
	cA(int x = 0, int y = 0) { cout << "cA cons: this= " << this << '\n'; m_i = x;  m_j = y; }
	void f1() {}
	void f2()const {}
	//	void __thiscall display( cA *const this)
	//	void __thiscall display( const cA *const this)
	void display() const
	{ 
		cout << "cA::display: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; 
		//m_i = 12345;
		//m_j = 5678;
		f2();
		//f1();
	}

	~cA() { cout << "cA Des: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }
};

int main() {
	cA obj(10, 20);

	obj.display();
	cout << "------------------\n";
}






int main_autoMalloc() {

	auto ap = malloc(sizeof(int));
	cout << typeid(ap).name() << endl;
	return 0;
}