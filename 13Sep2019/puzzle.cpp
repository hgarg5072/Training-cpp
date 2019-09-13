#include <iostream>
using namespace std;

#if 0
class cA {
	int  x, y, z;
public:
	cA(int i = 0) :y(i), x(y), z(y) {}
	~cA() { cout << "x= " << x << ", y= " << y << ", z= " << z << '\n'; }
};

int main() {
	cA obj(10);
	cout << "---------------\n";
}
#endif

#if 0
class cA {
	int m_i;
public:
	cA(int m_i = 0)  : m_i(m_i)
	{
		//m_i = m_i;
		//this->m_i = m_i;
	}
	~cA() { cout << "m_i = " << m_i << '\n'; }
};

int main() {
	cA obj(10);
	cout << "---------------\n";
}
#endif