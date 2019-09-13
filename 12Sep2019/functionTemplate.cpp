#include <iostream>
using namespace std;


template <typename Type1>
inline Type1 GETMAX(Type1 x, Type1 y) {
	cout << " I'm here 11111\n";
	return (x > y ? x : y);
}

template <typename Type1, typename Type2>
inline Type1 GETMAX(Type1 x, Type2 y) {
	cout << " I'm here 11111\n";
	return (x > y ? x : y);
}

template <>
inline const char * GETMAX(const char * x, const char * y) {
	cout << " I'm here 22222\n";
	return "True";
}

// GETMAX ii
int main() {
	//GETMAX(10, 20);
	//GETMAX(10.4, 20.2);

	//GETMAX<int>(40, 'A');
	//GETMAX<char>(40, 'A');
	//GETMAX("Hello ", "World");

	GETMAX<int>(10, 20); // template <typename Type1>
	GETMAX<int, char>(10, 'A'); //template <typename Type1, typename Type2>
}