#include <iostream>
using namespace std;

//int Count = 0;

class cA {
	static int Count; // cA::Count
public:
	cA() { ++Count; }
	~cA() { --Count; }
	//	int __thiscall getCount( cA *const this )
	//	int __cdecl getCount(  )
	static int getCount() { return Count; }
};
int cA::Count = 0;


int main() {
	cout << " Total instances of cA are: " << cA::getCount() << '\n';

	cA aObj1;
	cout << " Total instances of cA are: " << aObj1.getCount() << '\n';
	{
		cA aObj2;
		cout << " Total instances of cA are: " << aObj2.getCount() << '\n';
	}
	cout << " Total instances of cA are: " << aObj1.getCount() << '\n';
}

#if 0
int main() {
	//size();
	cA::Count = 505;
	cout << " Total instances of cA are: " << cA::Count << '\n';

	cA aObj1;
	cout << " Total instances of cA are: " << aObj1.Count << '\n';
	{
		cA aObj2;
		cout << " Total instances of cA are: " << aObj2.Count << '\n';
	}
	cout << " Total instances of cA are: " << cA::Count << '\n';
}

#endif

#if 0
void size() { cout << "sizeof(cA): " << sizeof(cA) << endl; }

int main() {
	//size();
	Count = 505;
	cout << " Total instances of cA are: " << ::Count << '\n';

	cA aObj1;
	cout << " Total instances of cA are: " << ::Count << '\n';
	{
		cA aObj2;
		cout << " Total instances of cA are: " << ::Count << '\n'; 
	}
	cout << " Total instances of cA are: " << ::Count << '\n';
}
#endif

