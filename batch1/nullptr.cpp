#include <iostream>
using namespace std;

void fun(int x) { cout << "fun(int)\n"; }
void fun(char *) { cout << "fun(char *)\n"; }

int main() {
	int i = 10;
	char str[] = "Hello";

	fun(i);
	fun(str);

	fun(NULL); // #define NULL (void*) 0
	fun(nullptr);
}