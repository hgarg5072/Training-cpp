#include <iostream>
using namespace std;

#if 0
struct Base {
	void fun() { vfun(); } // Run-time
	virtual void vfun() { cout << "Base::vfun\n"; }
};
struct Derived : Base {
	virtual void vfun() { cout << "Derived::vfun\n"; }
};

int main() {
	Derived dObj;

	dObj.fun(); // Compile-time
}
#endif


#if 0
struct Base {
	Base()  // vptr(Base::vtable)
	{ vfun(); } // Run-time
	virtual void vfun() { cout << "Base::vfun\n"; }
	~Base() // vptr(Base::vtable)
	{		vfun();	} // Run-time
};
struct Derived : Base {
	Derived()  // Base() // vptr(Derived::vtable)
		{ vfun(); }
	virtual void vfun() { cout << "Derived::vfun\n"; }
	~Derived() // vptr(Derived::vtable)
		{ vfun(); } // ~Base()
};

int main() {
	Derived dObj;

	cout << "-----------------\n";
}
#endif



struct Base {
	Base() { cout << "Base Cons\n"; }
	virtual ~Base() { cout << "Base Des\n"; }
};
struct Derived : Base {
	Derived() { cout << "Derived Cons\n"; }
	~Derived() { cout << "Derived Des\n"; } // ~Base()
};

/*
void ::operator new (size_t size){
	void *tmp = malloc(size);
	if(tmp)
		return tmp;
	throw bad_alloc();
}

*/
int main() {
	Base *bp = nullptr;
	try {
		bp = new Derived();
		/*
			void *temp = ::operator new(sizeof(Derived))
			push (Derived*) temp // this
			try{
				call Derived::Derived()
			}catch(...){
				delete temp;
				throw;
			}
			bp = (Base*) (Derived*)temp
		*/
	}	catch (bad_alloc exObj) {
		cout << " Low memory... cleanup job...\n";
	}

	cout << "---------------\n";
	delete bp;
	/*
		bp->~?()
	*/
}
