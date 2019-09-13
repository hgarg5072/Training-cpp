#include <iostream>
using namespace std;

#if 0
void swap(int x, int y) { // receive by value
	cout << "Swap: x = " << x << ", &x= " << &x << ", y= " << y << ", &y= " << &y << '\n';
	x ^= y;
	y ^= x;
	x ^= y;
	cout << "Swap: x = " << x << ", &x= " << &x << ", y= " << y << ", &y= " << &y << '\n';
}
#endif

#if 0
void swap(int *x, int *y) { // receive by Address
	cout << "Swap: *x = " << *x << ", &(*x)= " << &(*x) << ", *y= " << *y << ", &(*y)= " << &(*y) << '\n';
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	cout << "Swap: *x = " << *x << ", &(*x)= " << &(*x) << ", *y= " << *y << ", &(*y)= " << &(*y) << '\n';
}
#endif

#if 0
void swap(int & x, int & y) { // receive by reference
	cout << "Swap: x = " << x << ", &x= " << &x << ", y= " << y << ", &y= " << &y << '\n';
	x ^= y;
	y ^= x;
	x ^= y;
	cout << "Swap: x = " << x << ", &x= " << &x << ", y= " << y << ", &y= " << &y << '\n';
}
int main() {
	int i = 10, j = 20;

	cout << "Main: i = " << i << ", &i= " << &i << ", j= " << j << ", &j= " << &j << '\n';
	//swap(i, j); // Pass by value
	//swap( &i, &j); // Pass by address
	swap(i, j); // Pass by reference
	/*
		push &j
		push &i
	*/

	cout << "Main: i = " << i << ", &i= " << &i << ", j= " << j << ", &j= " << &j << '\n';
}
#endif

void change(const int * ip) {
	cout << " ip = " << ip << ", *ip= " << *ip << '\n';
	//*ip = 1234;
	int * iip = const_cast<int*> (ip);

	*iip = 12345;
}

int main() {
	int i = 10;

	cout << " i = " << i << ", &i= " << &i << '\n';
	change(&i);
	cout << " i = " << i << ", &i= " << &i << '\n';
}

