#include <iostream>
using namespace std;

class cA { // ::cA
private:
	int priI; // #0
protected:
	int protI; //#4
public:
	int pubI; //#8

	//void __thiscall display( cA *const this) 
	void display() {
		cout << "this= " << this << '\n';
		cout << " priI= " << priI << '\n'; // this->priI
		cout << " protI= " << protI << '\n';
		cout << " pubI= " << pubI << '\n';
		cout << "---------\n";
	}
};

// ---------- App ---------
int main() {
	cA aObj1, aObj2;
	cA *ap = nullptr; // NULL
	/*
		sub esp, sizeof(cA) //for aObj1


		sub esp, sizeof(cA) // for aObj2
	*/

	//cout << "typeid(aObj1).name()= " << typeid(aObj1).name() << endl;

	aObj1.pubI = 1234;
	ap = &aObj1;
	cout << " &aObj1 = " << &aObj1 << ", &aObj2 = " << &aObj2 << '\n';
	cout << "ap = " << ap << '\n';
	cout << "ap->pubI= " << ap->pubI << endl;

	aObj1.display(); // cA::display  
	/*
		push &aObj1 // this
		call cA::display
	*/


	aObj2.display(); // cA::display  
	/*
		push &aObj2 // this
		call cA::display
	*/
}