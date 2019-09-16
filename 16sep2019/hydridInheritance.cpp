#include <iostream>
using namespace std;

struct sA { int m_i; sA() :m_i(-1) {} };
struct sB : sA { int m_j; sB() :m_j(0) {} };
struct sC : sA { int m_k; sC() :m_k(1) {} };
struct sD : sB, sC { int m_l; sD() :m_l(2) {} };

void size() {
	cout << "sizeof(sA): " << sizeof(sA) << endl;
	cout << "sizeof(sB): " << sizeof(sB) << endl;
	cout << "sizeof(sC): " << sizeof(sC) << endl;
	cout << "sizeof(sD): " << sizeof(sD) << endl;
	cout << "sizeof(long ): " << sizeof(long ) << endl;
	cout << "sizeof(long long): " << sizeof(long long) << endl;
}

int main() {
	//size();
	sD dObj;

	long *p = (long*)&dObj;

	cout << " *p(sD::sB::sA::m_i=-1): " << *p << '\n';
	p++;
	cout << " *p(m_j=0): " << *p << '\n';
	p++;
	cout << " *p(sD::sC::sA::m_i=-1): " << *p << '\n';
	p++;
	cout << " *p(m_k=1): " << *p << '\n';
	p++;
	cout << " *p(m_l=2): " << *p << '\n';
}





