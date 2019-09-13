#include <iostream>
using namespace std;

template < typename Type1 = int>
inline Type1 GETMAX(Type1 x, Type1 y) {
	return (Type1)(x > y ? x : y);
}
/*
template <>
inline const char* GETMAX(const char *p1, const char *p2) {
	cout << " Hey! I've called....\n";
	return "ABCD";
}
*/
/*
template < typename Type1, typename Type2>
inline Type1 GETMAX(Type1 x, Type2 y) {
	return (Type1)(x > y ? x : y);
}*/
/*
inline int GETMAX(int x, int y) { // GETMAX ii // GETMAX HHH
	return (Type1)(x > y ? x : y);
}
inline char GETMAX(char x, char y) { // GETMAX cc // GETMAX DDD
	return (Type1)(x > y ? x : y);
}
*/
int main() {
	//GETMAX(10, 20);
	//GETMAX('A', 'B');
	//GETMAX<int> ('A', 10);
	//GETMAX<char> ('A', 10);
	GETMAX("Hello", " World");
}



