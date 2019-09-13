#include <iostream>
using namespace std;

namespace outer {
	namespace inner {
		namespace innerMost {
			int i = 10; // ::outer::inner::innerMost::i
			void fun() { cout << "global fun\n"; }
		}
	}
}

//using  outer::inner::innerMost::i = 10;
int main() {
	::outer::inner::innerMost::fun();
}






#if 0




int gi = 20;

namespace myns{ // ::myns
	int i = 5; // :: myns :: i
	int j = 6; // :: myns :: j
}


namespace myns {
	int k = 8;
}

namespace myns2 {
	int k2 = 28;
}

int main_03() {
	using namespace myns; // , myns2;
	//using namespace myns2;

	cout << "k = " << k << endl;
	cout << "k2 = " << k2 << endl;
}




int main_02() {
	//int j = 7;
	cout << " myns :: i= " << myns :: i << '\n';

	cout << " myns::k= " << myns::k << '\n';

	cout << " ::gi= " << ::gi << endl;
	using namespace myns;
	cout << " j= " << j << '\n';

	cout << " myns::j= " << myns::j << '\n';

	cout << " k= " << k << '\n';
	return 0;
}



int main_01() {
	int gi = 10;

	cout << " gi = " << gi << endl;
	{
		extern int gi;
		cout << " gi = " << gi << '\n';
	}
	return 0;
}
#endif