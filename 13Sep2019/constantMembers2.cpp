#include <iostream>
using namespace std;

class cA {
	int m_i;
	mutable int m_j;
public:
	cA(int x = 0, int y = 0) { cout << "cA cons: this= " << this << '\n'; m_i = x;  m_j = y; }
	void display() const
	{
		cout << "cA::display: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n';
		//m_i = 12345;
		m_j = 5678;
	}

	~cA() { cout << "cA Des: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }
};

int main() {
	cA obj(10, 20);

	obj.display();
	cout << "------------------\n";
}



