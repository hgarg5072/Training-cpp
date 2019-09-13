#include <iostream>
using namespace std;

//int Count = 0;
#if 0
class cA {
public:
	static int Count; // cA::Count
	cA() { Count++; }
	~cA() { --Count; }
};
int cA::Count = 0;

int main() {
	cA::Count = 500;
	cout << " Total objects are: " << cA::Count << endl;

	cA aObj1;
	cout << " Total objects are: " << cA::Count << endl;
	{
		cA aObj2;
		cout << " Total objects are: " << aObj1.Count << endl;
	}// aObj2.~cA()
	cout << " Total objects are: " << aObj1.Count << endl;
}
#endif


class cA {
	static int Count; // cA::Count
	int m_i;
public:
	cA() { Count++; }
	// 	int __thiscall getCount( cA *const this)
	// 	int __cdecl getCount( )
	static int getCount() { return Count; }
	~cA() { --Count; }
};
int cA::Count = 0;

int main() {
//	cA::Count = 500;
	cout << " Total objects are: " << cA::getCount() << endl;

	cA aObj1;
	cout << " Total objects are: " << aObj1.getCount() << endl;
	{
		cA aObj2;
		cout << " Total objects are: " << aObj1.getCount() << endl;
	}// aObj2.~cA()
	cout << " Total objects are: " << aObj1.getCount() << endl;
}












