#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << " cA Cons: this = " << this << '\n'; }
	void disp() const { cout << " cA::disp\n"; }
	~cA() { cout << " cA Des: this = " << this << '\n'; }
};


class cB {
	int m_j;
public:
	cB(int y = 1) :m_j(y) { cout << " cB Cons: this = " << this << '\n'; }
	void disp() const { cout << " cB::disp\n"; }
	~cB() { cout << " cB Des: this = " << this << '\n'; }
};

/*
class SmartPtr {
	cA *m_p;
public:
	SmartPtr(cA* p = nullptr) :m_p(p) {}
	~SmartPtr() {
		if (m_p) {
			cout << m_p << " Object  destroyed...\n";
			delete m_p;
			m_p = nullptr;
		}
	}
	cA* operator ->() { return m_p; }
};


class SmartPtrcB {
	cB *m_p;
public:
	SmartPtrcB(cB* p = nullptr) :m_p(p) {}
	~SmartPtrcB() {
		if (m_p) {
			cout << m_p << " Object  destroyed...\n";
			delete m_p;
			m_p = nullptr;
		}
	}
	cB* operator ->() { return m_p; }
};
*/

template <typename T>
class SmartPtr {
	T *m_p;
public:
	SmartPtr(T* p = nullptr) :m_p(p) {}
	~SmartPtr() {
		if (m_p) {
			cout << m_p << " Object  destroyed...\n";
			delete m_p;
			m_p = nullptr;
		}
	}
	T* operator ->() { return m_p; }
};

int main() {
	//SmartPtr <cA> ap(new cA());
	auto_ptr <cA> ap(new cA());
	ap->disp();

	//cB *bp = new cB();
	//SmartPtr<cB> bp(new cB());
	auto_ptr<cB> bp(new cB());
	bp->disp();

	cout << "-----------------\n";

	return 0;
}


#if 0
int main_02() {
	//cA *ap = new cA();
	SmartPtr ap ( new cA() ) ;

	ap->disp();

	cout << "-----------------\n";

	return 0;
}

int main_01() {
	cA *ap = new cA();

	ap->disp();
	cout << "-----------------\n";

	return 0;
}
// add esp, sizeof(ap)

#endif