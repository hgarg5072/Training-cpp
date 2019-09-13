#include <iostream>
using namespace std;


class cA {
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << "cA Cons: this= " << this << '\n'; }
	cA(int x, int y) :m_i(x) { cout << "cA Multiple param Cons: this= " << this<<",x= "<< x<<",y="<<y<< '\n'; }
	~cA() { cout << "cA Des: this= " << this <<", m_i= "<< m_i<< '\n'; }
};

void f1() {
	//cA(50);

	cA *ap = (cA *)malloc(sizeof(cA));

	if (NULL == ap) {
		cout << " Low mem... cleanup job...\n";
		//exit or continue without ap object
	}
	//ap->cA();

	cout << "ap = " << ap << '\n';

	ap->~cA();
	ap->~cA();
	ap->~cA();
	
	ap->~cA();
	free(ap);
	ap = NULL;
}

/*
void * operator new(size_t size){
	void *tmp = malloc(size);
	if(tmp) return tmp;
	throw bad_alloc()
}
void operator delete (void *p) { free(p); }
*/
void f2() {
	cA *ap = NULL;
	
	try {
		ap = new cA();
		/*
			void *temp = ::operator new(sizeof(cA))
			push 0			// x
			push (cA*) temp // this
			call cA::cA(int=0)
			ap = (cA*) temp
		*/
	}
	catch (bad_alloc& exObj) {
		cout << "... cleanup job...\n";
	}
	//if (NULL == ap ) // fail for new operator
	cout << "------------\n";
	delete ap;
	/*
	ap->~cA()
	::operator delete (ap)
	*/
}

/*
void * operator new(size_t size, nothrow_t&) {
	return malloc(size);
}
*/

struct Dummy {}dummy;

void * operator new(size_t size, Dummy&) {
	cout << "void * operator new(size_t size, Dummy&) \n";
	return malloc(size);
}
void f4() {
	cA *ap = NULL;
	try {
		ap =			// last step
			new(dummy)	// 1st step
			cA(10, 20);		// 2nd step
	//		ap = new(nothrow) cA();
			/*
				void *temp = ::operator new(sizeof(cA), nothrow)
				try{
					push 0			// x
					push (cA*) temp // this
					call cA::cA(int=0)
				}catch(...){}
				ap = (cA*) temp
			*/
	}
	catch (bad_alloc&) {

	}
	if(NULL == ap){
		cout << "... Low mem... cleanup job...\n";
	}
	
	cout << "------------\n";
	delete ap;
	/*
	ap->~cA()
	::operator delete (ap)
	*/
}

int main_subs() {
	//f2();
	//f4();

	cA *ap = new cA[4];
	/*
		void *temp = ::operator new[] (siezof(cA) * 4);
		ap = (cA*) temp;
		ap[0].cA()
		ap[1].cA()
		ap[2].cA()
		ap[3].cA()
	*/
	cout << "----------------\n";
	//delete ap;
	/*
		ap->~cA()
		::operator delete (ap) // free sizeof(ap);
	*/

	delete [] ap;
	/*
		ap[3]->~cA()
		ap[2]->~cA()
		ap[1]->~cA()
		ap[0]->~cA()
		::operator delete [](ap) // free sizeof(ap);
	*/
	return 0;
}

int main() {
	//char chunk[1024];
	char *chunk = new char[1024];

	// used chunk
	cA *ap1 = new(chunk) cA();
	cA *ap2 = new(chunk + sizeof(cA)) cA();
	cA *ap3 = new(chunk + 2 * sizeof(cA)) cA();
	cA *ap4 = new(chunk + 3 * sizeof(cA)) cA();
	cA *ap5 = new(chunk + 4 * sizeof(cA)) cA();

	cout << " &chunk[0]= " << (&chunk) << endl;
	cout << "ap1 = " << ap1 << endl;
	cout << "ap2 = " << ap2 << endl;
	cout << "ap3 = " << ap3 << endl;
	cout << "ap4 = " << ap4 << endl;
	cout << "ap5 = " << ap5 << endl;

	cout << "--------------------\n";
	//delete ap1;

	ap5->~cA();
	ap4->~cA();
	ap3->~cA();

	ap2->~cA();
	ap1->~cA();

	//
	delete[] chunk;
}












