#include <iostream>
using namespace std;

class cA {
	int *ip;
public:
	cA(int val) {
		ip = new int();

		*ip = val;
		cout << "Default" << endl;
	}
	cA(cA& rhs) {
		ip = new int();

		*ip = *rhs.ip; // Deep Copy
		cout << "Copy Cons\n";
	}

	cA(cA && rhs) {
		ip = rhs.ip; // Grap the ownership
		rhs.ip = nullptr;
		cout << "Move Cons\n";
	}
	~cA() {
		if (ip) {
			cout << " Object alive with resource....\n";
		}
		else cout << " No resource\n";
	}
};

int main() {
	cA obj1(10);

	//cA obj2(obj1);
	cA obj2( std::move(obj1) );
	cout << "-------\n";
}



int main_01() {
	int i = 10;
	int j = 20;
	int &iRef = i;

	//const 
	//int &iiRef = 10;

	int && iiRef = 104; // const int iiRef = 104;
	//int && iiRef = i;

	cout << " &i = " << &i << '\n';
	cout << " &iRef = " << &iRef <<", iRef= "<< iRef << '\n';
	cout << " &iiRef = " << &iiRef << ", iiRef= " << iiRef << '\n';

	cout << "j = " << j << ", &j= " << &j << '\n';
	//j = iiRef;
	iiRef = j;
	cout << "j = " << j << ", &j= "<< &j<<'\n';
	//cout << "*iiRef = " << *iiRef << endl;
	return 0;
}