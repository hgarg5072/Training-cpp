#include <iostream>
using namespace std;

struct sA { int m_i; sA() :m_i(-1) {} };
struct sB : virtual sA { 
	// void *vptr
	// static int sB::offset[]
	int m_j; 
	sB() :m_j(0) {} 
};
// int sB::offset[1] = +8

struct sC : virtual sA {
	// void * vptr
	// static int sC::offset[]
	int m_k; 
	sC() :m_k(1) {} 
};
// int sC::offset[1] = +8

struct sD : sB, sC {
	// static int sD::sB::offset[]
	// static int sD::sC::offset[]
	int m_l; sD() :m_l(2) {} 
};

// int sD::sB::offset[0] = 0
// int sD::sB::offset[1] = 20

// int sD::sC::offset[0] = -8
// int sD::sC::offset[1] = 12

void size() {
	cout << "sizeof(sA): " << sizeof(sA) << endl;
	cout << "sizeof(sB): " << sizeof(sB) << endl;
	cout << "sizeof(sC): " << sizeof(sC) << endl;
	cout << "sizeof(sD): " << sizeof(sD) << endl;
}

int main() {
//	size();
	sD dObj;
	
	long *p = (long*)&dObj;
	long *vptr = (long*)p;
	long* offset = (long*)*vptr;

	++offset;
	cout << " *offset(20): " << *offset << '\n';
	p++;
	cout << " *p(m_j=0): " << *p << '\n';
	p++;

	vptr = (long*)p;
	offset = (long*)*vptr;
	++offset;
	cout << " *offset(12): " << *offset << '\n';
	p++;
	cout << " *p(m_k=1): " << *p << '\n';
	p++;
	cout << " *p(m_l=2): " << *p << '\n';
	p++;
	cout << " *p(m_i=-1): " << *p << '\n';
}





