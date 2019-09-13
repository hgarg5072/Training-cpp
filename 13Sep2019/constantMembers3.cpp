#include <iostream>
using namespace std;

class cA {
	const int m_i;
	int m_j;
public:
	cA(int x = 0, int y = 0) : m_i(x), m_j(y) // Initializer_list
	{ 
		cout << "cA cons: this= " << this << '\n'; 
	//	m_i = x;  
		//m_j = y; 
	}

	~cA() { cout << "cA Des: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }
};

int main() {
	cA obj(10, 20);

	cout << "------------------\n";
}



