#include <iostream>
using namespace std;

class MyException {};

class cA {
	int m_i;
	//static void *operator new(size_t size) {}
	/*{
		cout << "void *operator new(size_t size) " << endl;
		return nullptr;
	}*/
public:
	cA(int x = 0) :m_i(x) { cout << "cA Cons: this= " << this << '\n'; }
	~cA() { cout << "cA Des: this= " << this << '\n'; }
	//static void *operator new(size_t size) = delete;

	void f1() = delete; // {}
};

int main() {
	cA obj;

	obj.f1();

	cA * ap = new cA();
	ap->f1();
	cout << "---------------\n";
}


#if 0
class cA {
	static cA * m_p;
	int m_i;
	// Method 2
	cA(int x = 0) :m_i(x) {		cout << "cA Cons: this= " << this << '\n';	}
public:
	/* Method 1
	cA(int x = 0) :m_i(x) {
		cout << "cA Cons: this= " << this << '\n';  
		throw MyException(); 
	}
	*/
	~cA() { cout << "cA Des: this= " << this << '\n'; }

	static cA* Creator() { 
		if(!m_p) 
			m_p = new cA(); 
		return m_p;
	}
};

cA* cA::m_p = nullptr;

int main() {
	//cA obj; // Stack

	//cA *ap = new cA(); // heap

	cA *ap1 = cA::Creator();
	cA *ap2 = cA::Creator();
	cA *ap3 = cA::Creator();
	cA *ap4 = cA::Creator();

	cout << "ap1= " << ap1 << '\n';
	cout << "ap2= " << ap2 << '\n';
	cout << "ap3= " << ap3 << '\n';
	cout << "ap4= " << ap4 << '\n';
	cout << "----------------\n";
	delete ap1;
	delete ap2;
	delete ap3;
	delete ap4;
}
#endif