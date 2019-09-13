#include <iostream>
using namespace std;

/*
void swap(int x, int y) { // Receive by value
	cout << " Swap: x= " << x << ", y= " << y << '\n';
	x ^= y; // x = x ^ y
	y ^= x; // y = y ^ x // y = y ^ (x = x ^ y)
	x ^= y; // x = x ^ y
	cout << " Swap: x= " << x << ", y= " << y << '\n';
}
*/

#if 0
void swap(int * x, int * y) { // Receive by Address
	cout << " Swap: *x= " << *x << ", *y= " << *y << '\n';
	*x ^= *y;
	*y ^= *x;
	*x ^= *y; // *x = *x ^ *y
	cout << " Swap: *x= " << *x << ", *y= " << *y << '\n';
}

#endif

void swap(int & x, int &y) { // Receive by reference
	cout << " Swap: x= " << x << ", y= " << y << '\n';
	x ^= y; // x = x ^ y
	y ^= x; // y = y ^ x // y = y ^ (x = x ^ y)
	x ^= y; // x = x ^ y
	cout << " Swap: x= " << x << ", y= " << y << '\n';
}
void main() {
	int i = 10, j = 20;

	cout << "Main: i = " << i << ", j= " << j << '\n';
//	swap(i, j); // pass by value
	/*
		push 20 // value of j
		push 10 // value of i
		call swap(int, int)
	*/
//	swap( &i, &j); // pass by Address
	/*
		push &j // Address of j
		push &i // Address of i
		call swap(int *, int*)
	*/
	swap(i, j); // pass by reference
	/*
		push &j // reference of j
		push &i // refernce of i
		call swap(int &, int &)
	*/
	cout << "Main: i = " << i << ", j= " << j << '\n';
}


int main_cpp_reference() {
	int i = 10, j = 20;
	int & ip = i; //int * const ip = &i; // C++ Reference

	cout << "i = " << i << ", j= " << j << endl;
	cout << "&i = " << &i << ", &j= " << &j << endl;
	cout << " ip = " << ip << ", &ip = " << &ip << endl;
	//cout << "  ip= " << ip << ", &ip = " << & (*ip) << endl;

	
	ip = 12345; // Valid
	//*ip = 12345; // Valid
	cout << " ip = " << ip << ", &ip = " << &ip << endl;
	//cout << " *ip = " << * (*ip) << ", ip= " << ip << ", &ip = " << &ip << endl;
	cout << "i = " << i << ", j= " << j << endl;
	return 0;
}




int main_c_reference() {
	int i = 10, j = 20;
	
	//const int *ip = &i;
//	int const *ip = &i;
	int * const ip = &i;
	//(int *const)  * ipp = &ip;

	cout << "i = " << i << ", j= " << j << endl;
	cout << "&i = " << &i << ", &j= " << &j << endl;
	cout << " *ip = " << *ip << ", ip= " << ip << ", &ip = " << &ip << endl;

	//ip = &j; // In-Valid
	*ip = 12345; // Valid
	cout << " *ip = " << *ip << ", ip= " << ip << ", &ip = " << &ip << endl;
	cout << "i = " << i << ", j= " << j << endl;
	return 0;
}




int main_02() {
	int i = 10, j = 20;
	//const int *ip = &i;
	int const *ip = &i;

	cout << "i = " << i << ", j= " << j << endl;
	cout << "&i = " << &i << ", &j= " << &j << endl;
	cout << " *ip = " << *ip << ", ip= " << ip << ", &ip = " << &ip << endl;

	ip = &j; // Valid
	//*ip = 12345; // In-valid
	cout << " *ip = " << *ip << ", ip= " << ip << ", &ip = " << &ip << endl;
	return 0;
}

int main_01() {
	int i = 10, j = 20;
	const int *ip = &i;

	cout << "i = " << i << ", j= " << j << endl;
	cout << "&i = " << &i << ", &j= " << &j << endl;
	cout << " *ip = " << *ip << ", ip= " << ip << ", &ip = " << &ip << endl;

	ip = &j; // Valid
	//*ip = 12345; // In-valid
	cout << " *ip = " << *ip << ", ip= " << ip << ", &ip = " << &ip << endl;
	return 0;
}












