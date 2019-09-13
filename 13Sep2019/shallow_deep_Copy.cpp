#include <iostream>
using namespace std;

class cA {
	int * m_i;
	int * m_j;
public:
	cA(int x = 0, int y = 0) { 
		cout << "cA cons: this= " << this << '\n'; 
		m_i = (int *)malloc(sizeof(int));
		if (NULL == m_i) {
			cout << " m_i... Low memory... cleanup...\n";
		}
		*m_i = x;
		m_j = (int *)malloc(sizeof(int));
		if (NULL == m_j) {
			cout << "m_j... Low memory... cleanup...\n";
		}
		*m_j = y; 
	}
	void display() { cout << "cA::display: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }

	~cA() {
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout << "cA Des: this= " << this << '\n';
		if (m_i) {
			cout << " *m_i= " << *m_i << " memory is getting  released: " << m_i << "\n";
			free(m_i);
			m_i = nullptr;
		}
		if (m_j) {
			cout << "*m_j= " << *m_j << " memory is getting  released:, m_j= " << m_j << '\n';
			free(m_j);
			m_j = nullptr;
		}
		cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvv\n";
	}
	cA(cA&rhs);
};


/*
cA::cA(cA& rhs) { // Copy cons: by value // Deep Copy
	this->m_i = (int*)malloc(sizeof(int));
	this->m_j = (int*)malloc(sizeof(int));

	*m_i = *rhs.m_i;
	*m_j = *rhs.m_j;
	cout << "cA::Copy Cons: this= " << this << "\n";
}
*/

/*
cA::cA(cA& rhs) { // Copy cons: by value // Deep Copy

	m_i = rhs.m_i;
	m_j = rhs.m_j;
	cout << "cA::Copy Cons: this= " << this << "\n";
}*/

cA::cA(cA& rhs) { // Copy cons: by value // Shallow Copy

	m_i = rhs.m_i;
	m_j = rhs.m_j;
	rhs.m_i = nullptr;
	rhs.m_j = nullptr;
	cout << "cA::Copy Cons: this= " << this << "\n";
}

int main() {
	cA obj(10, 20);

	cout << "-------------\n";
	cA obj2(obj);

	cout << "-------------\n";
}// obj.~cA()


