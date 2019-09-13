#include <iostream>
using namespace std;

//#define GETMAX(x, y) ( x > y ? x : y)

template < typename Type1, typename Type2> 
inline Type1 GETMAX(Type1 x, Type2 y) {
	return (Type1) (x > y ? x : y);
}

/*
inline int  GETMAX(int x, int y) {
	return (x > y ? x : y);
}

inline double GETMAX(double x, double y) {
	return (x > y ? x : y);
}
*/
int main() {
	int i = 10, j = 20;
	double d = 45.12, e = 1.1;

	cout << "i = " << i << ", j= " << j << '\n';
	cout << "GETMAX(i++, j++)= " << GETMAX(i++, j++) << '\n';
								// ( i++ > j++ ? i++ : j++) // pre-processor
								// { i > j ? i: j;} ; i++; j++ - inlined
	cout << "i = " << i << ", j= " << j << '\n';

	cout << "GETMAX(d,e)= " <<  GETMAX(d, e)  << '\n';
}




#if 0
#define TEST(x,y,z) x=100;y=200;z=300

int main() {
	int a = 1, b = 2, c = 3;

	if (a > 5)
		TEST(a, b, c);
	/*
	if (a > 5)
		a=100;
	b=200;
	c=300;
	
	*/
	cout << "a= " << a << ", b= " << b << ", c= " << c << '\n';
}
/*
P1: 100, 200, 300 }
P2: 1,2,3 } > 18
P3:  Error } 1
P4: 1, 200, 300 }2
*/
#endif


