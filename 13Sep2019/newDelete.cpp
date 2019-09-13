#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << "cA Cons:this = " << this << "\n"; }
	void disp() { cout << "cA::disp" << endl; }
	~cA() { cout << "cA Des:this = " << this << "\n"; }
};

void heapCFun() {
	cA *ap = nullptr; // NULL;

	ap = (cA*)malloc(sizeof(cA));
	if (nullptr == ap) // if(ap == NULL)
	{
		cout << " Low memo... cleanup...\n";
	}
	cout << "ap = " << ap << '\n';
	//ap->cA();

	ap->disp();
	cout << "-----------------\n";
	ap->~cA();	
	free(ap);
	ap = nullptr;
}

/*
void * operator new (size_t size) {
	return malloc(size);
}
*/
void heapCPPFun() {
	cA *ap = nullptr;

		ap = new cA();
		/*
			void *temp = ::operator new(sizeof(cA));
			push (cA*) temp // this
			call cA::cA()

			ap = (cA*)temp
		*/

		cout << "ap = " << ap << '\n';
		cout << "-----\n";

		delete ap;
		/*
			ap->~cA()
			call ::operator delete (ap); // free(ap)
		*/
}
int main() {
	//heapCFun();
	heapCPPFun();
}