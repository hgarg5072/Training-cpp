#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(int x=0):m_i(x){}

	void m_fun() { cout << "cA::m_fun\n"; }
	void m_fun2() { cout << "cA::m_fun2222\n"; }

	void operator ()() {
		//m_fun();
		m_fun2();
	}
};

void callback(cA &aObj) {
	cout << " Initialize resources...\n";
//	aObj.m_fun();
//	aObj.m_fun2();

	//cA();
	aObj(); // Callable objects
	cout << " relaize resources...\n";
	cout << "--------------\n";
}

int main() {
	cA obj(10);

	callback(obj);
}