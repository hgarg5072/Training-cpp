#include <iostream>
using namespace std;

void fun(int x, int y=500, int z=600);
/*
void fun(int x, int y, int z)
void fun(int x, int y, int=600)
void fun(int x, int y=500, int)
*/
int main() {
	fun(10, 20, 30);
	/*
		push 30
		push 20
		push 10
		call funiii
	*/
	fun(40, 50);
	/*
		push 600
		push 50
		push 40
		call funiii
	*/
	fun(60);
	/*
		push 600
		push ?
		push 60
		call funiii
	*/
	//fun(1, , 4);
}
void fun(int x, int y, int z) {
	cout << "x= " << x << ", y= " << y << ", z= " << z << endl;
}