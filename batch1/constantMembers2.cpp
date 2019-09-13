#include <iostream>
using namespace std;

class cA {
	const int m_i ;
	int m_j;
public:
	cA(int x = 0, int y = 1) :m_i(x), m_j(y) // Initializer-list
	{ // mov [this->m_i], x
		//m_i = x; 
		//m_j = y; 
	}
	~cA() { cout << "~cA: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }	
};

int main() {
	cA obj(10, 20);
	cA obj2(40, 50);
	cout << "-----------------\n";
}