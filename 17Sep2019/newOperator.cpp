#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(cA&) = default; // Copy Constructor is default synthesized by Compiler
	cA(cA&&) = default;
	//void f1() = default;
	cA(int x = 0) :m_i(x) { cout << "cA Cons: this= " << this << '\n'; }
	~cA() { cout << "cA Des: this= " << this << '\n'; }
};

void *operator new(size_t size) {
	cout << "void *operator new(size_t size) : size= " << size << '\n';
	return malloc(size);
}

struct Dummy {} dummy;

void *operator new(size_t size, Dummy& dum) {
	cout << "void *operator new(size_t size, Dummy& dum) : size= " << size << '\n';
	return malloc(size);
}

int main() {
//	cA *ap = new cA();
	cA *ap = new(dummy) cA();

	cout << "-------------\n";
	delete ap;
}

/*
void *operator new(size_t size){
	void *tmp = malloc(size);
	if(tmp)
		return tmp;
	throw bad_alloc();
}

void *operator new(size_t size, nothrow_t){ // Nothrow New
	return malloc(size);
}

void* ::operator new[](size_t size){
	void *tmp = malloc(size);
	if(tmp) return tmp;
	throw bad_alloc();
}

void *operator new(size_t size, void *p ){
	return p;
}
*/

int main_04() {
	//char chunk[1];
	char *chunk = new char[1000];

	// used chunk....

	cA *ap1 = new(chunk) cA(); // Placement New

	cA *ap2 = new(chunk + sizeof(cA) ) cA();
	cA *ap3 = new(chunk + sizeof(cA) * 2) cA();
	cA *ap4 = new(chunk + sizeof(cA) * 3) cA();

	cout << "ap1 = " << ap1 << endl;
	cout << "ap2 = " << ap2 << endl;
	cout << "ap3 = " << ap3 << endl;
	cout << "ap4 = " << ap4 << endl;

	//delete ap1; // Never use delete on placement new...
	ap4->~cA();
	ap3->~cA();
	ap2->~cA();
	ap1->~cA();

	//
	delete[] chunk;
	return 0;
}



//constexpr int fun() { return 4; }

int main_newSubscript() {
	//cA arr[fun()];

	cA *ap = new cA[4]; // fun() ];
	/*
		void *temp = ::operator new[](sizeof(cA) * 4);
		ap = (cA*)temp;
		ap[0].cA()
		ap[1].cA()
		ap[2].cA()
		ap[3].cA()
	*/

	cout << "--------------\n";
	delete[] ap;
	/*
		ap[3]->~cA()
		ap[2]->~cA()
		ap[1]->~cA()
		ap[0]->~cA()
		call ::operator delete[](ap, sizeof(cA) * 4)
	*/
	//delete ap; // Never use when new[]
	/*
		ap->~cA()
		:: operator delete(ap, sizeof(cA) ); // free(ap)
	*/
	return 0;
}

int main_02() {
	cA *ap = new(nothrow) cA();

	if (nullptr == ap) {
		cout << "Low mem";
	}
	return 0;
}
int main_01() {
	cA *ap = nullptr;
	try {
		ap = new cA(); // Clean code
	}catch(bad_alloc){}

	if (ap) { // Fails for Global new
		cout << " Low...";
	}
	return 0;
}
