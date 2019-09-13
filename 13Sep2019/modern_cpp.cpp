#include <iostream>
using namespace std;

#if 0
// why nullptr
void fun(int) { cout << "void fun(int)\n"; }
void fun(const char*) { cout << "void fun(const char*)\n"; }

int main() {
	fun(10);
	cout << "-----------\n";
	fun("Hello");
	cout << "-----------\n";

	// #define NULL (void*) 0
	fun(NULL);
	cout << "-----------\n";

	// class nullptr_t{}nullptr;
	fun(nullptr);

	cout << "typeid(nullptr).name()= " << typeid(nullptr).name() << '\n';
	cout << "typeid(cout).name()= " << typeid(cout).name() << '\n';
}
#endif

//auto

auto fun() {
	int i = 4;
	cout << "float fun()\n";
	if( i<4)
		return 4.5f;
	if (4 == i)
		return 2.1f;
	if (i > 4)
		return 1.1f;
	return 0.0f;
}
int auto_fun() {
	//auto i = 10;
	//cout << "typeid(i).name()= " << typeid(i).name() << endl;

	/*
	auto varf = fun();
	cout << "typeid(varf).name()= " << typeid(varf).name() << endl;
	cout << "varf = " << varf << '\n';
	*/

	//auto varf = fun();
	decltype(fun()) varf;
	cout << "typeid(varf).name()= " << typeid(varf).name() << endl;
//	cout << "varf = " << varf << '\n';
	return 0;
}


//int fun2() {}
//float fun2() {}

int main_decltype() {
	//auto var = 'A' + 10 - 10.0;

	decltype('A' + 10 - 10.0) var;
	cout << "var= " << typeid(var).name() << '\n';
	//cout << "var= " << var << '\n';
	return 0;
}

auto gfun() -> decltype('A' + 10)
{
	cout << "auto gfun() -> decltype('A' + 10)\n";
	return 'A' + 10; // +4.5;
}

//void fun5(auto x, auto y) {}

int main_02() {
	//auto var = gfun();
	decltype( gfun())  var ;
	cout << "var= " << typeid(var).name() << '\n';
//	cout << "var= " << var << '\n';

	return 0;
}

template<typename T>
void myFun(T *ap) {
	auto first = ap[0];
}

/*
void myFun(int *ap) {
	auto first = ap[0];
}

void myFun(float *ap) {
	auto first = ap[0];
}
*/


int main() {
	int arr[]{ 1,2,3,4,5 }; // int arr[] = { 1,2,3,4,5 }; // old-style
	float farr[]{ 1.1f, 1.2f };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		auto val = arr[i];
		cout << "arr[" << i << "]= " << arr[i] << '\n';
		cout << " val = " << val << '\n';
	}

	for (auto val : farr)
		cout << "val= " << val << '\n';
}




























