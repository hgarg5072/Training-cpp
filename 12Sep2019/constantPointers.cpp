#include <iostream>
using namespace std;


void c1fun() {
	int i = 10, j = 20;
	const int *ip = &i;

	cout << "i= " << i << ", &i= " << &i << '\n';
	cout << "j= " << j << ", &j= " << &j << '\n';
	cout << "ip= " << ip << ", &ip= " << &ip << ", *ip= "<< *ip <<'\n';

	ip = &j; // Valid
	//*ip = 1234; // In-valid
	cout << "ip= " << ip << ", &ip= " << &ip << ", *ip= " << *ip << '\n';
}

void c2fun() {
	int i = 10, j = 20;
	//const int *ip = &i;
	int const *ip = &i;

	cout << "i= " << i << ", &i= " << &i << '\n';
	cout << "j= " << j << ", &j= " << &j << '\n';
	cout << "ip= " << ip << ", &ip= " << &ip << ", *ip= " << *ip << '\n';

	ip = &j; // Valid
	//*ip = 1234; // In-valid
	cout << "ip= " << ip << ", &ip= " << &ip << ", *ip= " << *ip << '\n';
}

void c3fun() {
	int i = 10, j = 20;
	//const int *ip = &i;
	//int const *ip = &i;
	int * const ip = &i; // C-Style reference

	cout << "i= " << i << ", &i= " << &i << '\n';
	cout << "j= " << j << ", &j= " << &j << '\n';
	cout << "ip= " << ip << ", &ip= " << &ip << ", *ip= " << *ip << '\n';

	//ip = &j; // In-Valid
	*ip = 1234; // Valid
	cout << "ip= " << ip << ", &ip= " << &ip << ", *ip= " << *ip << '\n';
	cout << "i= " << i << ", &i= " << &i << '\n';
	cout << "j= " << j << ", &j= " << &j << '\n';
}

void cppfun() {
	int i = 10, j = 20;
	int & ip = i; //int * const ip = &i; // C-Style reference

	cout << "i= " << i << ", &i= " << &i << '\n';
	cout << "j= " << j << ", &j= " << &j << '\n';
	cout << "ip= " << ip << ", &ip= " << &ip << '\n';
	//cout << "ip= " << *ip << ", &ip= " << &(*ip) << ", *ip= " << *(*ip) << '\n';

	ip = 1234;
	//*ip = 1234; // Valid
	cout << "ip= " << ip << ", &ip= " << &ip << '\n';
	cout << "i= " << i << ", &i= " << &i << '\n';
	cout << "j= " << j << ", &j= " << &j << '\n';
}

int main() {
	//c1fun();
	//c2fun();
	//c3fun();
	cppfun();
}