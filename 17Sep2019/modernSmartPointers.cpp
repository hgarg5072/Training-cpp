#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << " cA Cons: this = " << this << '\n'; }
	void disp() const { cout << " cA::disp\n"; }
	~cA() { cout << " cA Des: this = " << this << '\n'; }
};

int main() {
	shared_ptr<cA> sp1(new cA());
	weak_ptr <cA> wp1 = sp1;

	cout << "wp1= " << wp1.use_count() << endl;
	if (wp1.expired())
		cout << "Expired...\n";
	else
		cout << "Alive\n";
	cout << "sp1 = " << sp1 << endl;
	cout << "sp1.use_count() = " << sp1.use_count() << endl;
	sp1->disp();
	{
		shared_ptr<cA> sp2(sp1);
		wp1 = sp2;
		cout << "sp1 = " << sp1 << endl;
		cout << "sp2 = " << sp2 << endl;
		cout << "sp1.use_count() = " << sp1.use_count() << endl;
		cout << "sp2.use_count() = " << sp2.use_count() << endl;
		cout << "wp1= " << wp1.use_count() << endl;
		//wp1->disp();
	}
	cout << "sp1.use_count() = " << sp1.use_count() << endl;
	cout << "----------------\n";
}



int main_unique() {
	unique_ptr<cA> up1(new cA());

	//unique_ptr<cA> up2( up1);
	
	unique_ptr<cA> up2( std::move(up1) );

	cout << "up1= " << up1 << '\n';
	cout << "up2= " << up2 << '\n';

	unique_ptr<cA> up4;

	cout << "up4= " << up4 << '\n';

	//up4 = up2; // unique_ptr::operator = ( unique_ptr &) // l-value Reference
	up4 = std::move(up2); // unique_ptr::operator = ( unique_ptr && ) // r-value reference

	cout << "up1= " << up1 << '\n';
	cout << "up2= " << up2 << '\n';
	cout << "up4= " << up4 << '\n';

	return 0;
}
