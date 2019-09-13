#include <iostream>
using namespace std;

void fun(int) {} // funi
void fun(int, int) {} // funii
void fun(int, float) {} // funif
void fun(float, int) {} // funfi
void fun(float, int, int, ...) {} // funfia
// fun(1.2f, 10, 20);
#if 0
// first.h
namespace myns {
	int gi = 10; // myns::gi
}

// second.h
namespace myns {
	int gj = 20; // myns::gj
}

namespace myns2 {
	int gj = 40; // myns2::gj
}

int main() {
	cout << "Hello\n";

	cout << " myns::gi = " << myns ::gi << '\n';
	cout << " myns::gj = " << myns::gj << '\n';

	{
		using namespace myns;
		using namespace myns2;

		cout << " gi = " << gi << '\n';
		cout << " gj = " << myns::gj << '\n';
		cout << " gj = " << myns2::gj << '\n';
	}
	//cout << " gi = " << gi << '\n';
}
#endif

int gi = 10;

int main() {
	int gi = 20;

	cout << " gi= " << gi << endl;
	{
		//extern int gi; // C-Style
		cout << " gi= " << gi << endl;
		cout << " ::gi= " << ::gi << endl; // C++-Style
	}
}

















