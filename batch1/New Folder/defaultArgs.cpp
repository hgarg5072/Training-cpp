#include <iostream>
using namespace std;

void fun(int x, int y=600, int z=700);
/*
void fun(int , int , int )
void fun(int , int, int=700  )
void fun(int , int=600, int )
*/

//void fun(int){}

void fun(int, float) {}

int main() {
	fun(10, 20, 30);
	/*
		push 30 //z
		push 20 // y
		push 10 // x
		call funiii
	*/
	fun(40, 50);
	/*
		push 700
		push 50
		push 40
		call funiii
	*/
	fun(60);
	/*
		push 700
		push 600
		push 60
		call funiii
	*/
}

void fun(int x, int y, int z) {
	cout << "x= " << x << ", y= " << y << ", z= " << z << endl;
}