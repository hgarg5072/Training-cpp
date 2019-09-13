#include <iostream>
using namespace std;

class cA{
private:
	int priI; // #0
protected:
	int protI; // #4
public:
	int pubI; // cA::pubI // #8
	//void __thiscall fun1( cA *const this); 
	void fun1(); // cA::fun1

	//void __thiscall fun2( cA *const this, int x, int y); 
	void fun2(int x, int y);
};
void cA::fun2(int x, int y) { cout << "cA::fun2: this= " << this << ", x= " << x << ", y= " << y << "\n"; }
void main() {
	cA obj1;

	obj1.fun2(1, 2);
	/*
		push 2 // y
		push 1 // x
		push &obj1 // this
		call cA::fun2(int, int)
	*/
}






void cA::fun1(){ 
	cout << "-----------------------\n";
	cout << " cA::fun1: this= "<< this <<"\n"; 
	cout << " priI = " << priI << "\n";
	cout << " protI = " << protI << "\n";
	cout << " pubI = " << pubI << "\n"; // this->pubI
	cout << "-----------------------\n";
} // cA::fun1






int main_01() {
	cA obj1, obj2;
	cA *ap = NULL; // nullptr;
	/*
		sub esp, sizeof(cA) // 3 * sizeof(int) // for obj1 
		sub esp, sizeof(cA) // 3 * sizeof(int) // for obj2
	*/
	cout << "&obj1= " << &obj1 << ", &obj2= " << &obj2 << '\n';
	obj1.pubI = 1234;
	ap = &obj1;
	cout << "ap->pubI= " << ap->pubI << endl;
	obj1.fun1();
	/*
		push &obj1 // this
		call cA::fun1()
	*/
	obj2.fun1();
	/*
		push &obj2 // this
		call cA::fun1()
	*/

	ap->fun1();
	/*
		push ap // this
		call cA::fun1
	*/
	return 0;
}