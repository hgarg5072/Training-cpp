#include <iostream>
using namespace std;

//#define GETMAX(x, y) ( x > y ? x : y)

template <typename Type1>
inline Type1 GETMAX(Type1 x, Type1 y) {
	return (x > y ? x : y);
}

/*
inline int GETMAX(int x, int y) {
	return (x > y ? x : y);	
}

inline double GETMAX(double x, double y) {
	return (x > y ? x : y);
}
*/

int main() {
	int i = 10, j = 20;
	double d = 24.12, e = 1.1;

	//inline void fun() {}

	cout << "i = " << i << ", j= " << j << endl;
	cout << " GETMAX(i++, j++): " << GETMAX(i++, j++) << endl;
									// i++ > j++ ? i++ : j++ // pre-processor
									// GETMAX(i,j); i++; j++ // non-inline function
									// {i > j ? i : j} ; i++; j++ // inlined function
	cout << "i = " << i << ", j= " << j << endl;

	cout << " GETMAX(d,e): " << GETMAX(d,e) << endl;
}
