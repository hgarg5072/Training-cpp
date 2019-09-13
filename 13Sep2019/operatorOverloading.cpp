#include <iostream>
using namespace std;

class Complex {
	int real, imag;
public:
	friend ostream& operator << (ostream& os, Complex& rhs);
	Complex(int x = 0, int y = 0) :real(x), imag(y) {}
	int getReal() {
		return real;
	}int getImag() {
		return imag;
	}
	~Complex() { cout << "Real: " << real << ", Imag: " << imag << '\n'; }
//	void operator +(int rhs);
	Complex& operator +(int rhs);
	Complex& operator ++();
	Complex& operator ++(int);
};

/*
void operator +(Complex& lhs, int rhs) {
	cout << "void operator +(Complex& lhs, int rhs): rhs= " << rhs << '\n';

	//lhs.imag += rhs;
}
*/

/*
void Complex::operator +(int rhs) {
	cout << "void Complex::operator +(int rhs) : rhs= " << rhs << '\n';
	imag += rhs;
}
*/

Complex& Complex::operator +(int rhs) {
	cout << "Complex& Complex::operator +(int rhs) : rhs= " << rhs << '\n';
	imag += rhs;
	return *this;
}

Complex& Complex::operator ++() {
	cout << "Complex& Complex::operator ++() \n";
	++real;
	return *this;
}
Complex& Complex::operator ++(int dummy) {
	cout << "Complex& Complex::operator ++(int dummy):dummy= "<< dummy <<"\n";
	++imag;
	return *this;
}

ostream& operator << (ostream& os, Complex& rhs) {
	os << rhs.real << " +j " << rhs.imag << "\n";
	//os << rhs.getReal() << " +j " << rhs.getImag() << "\n";
	return os;
}

int main() {
	Complex obj(10, 20);

	cout << obj ;

}






#if 0
struct Dummy {};

void operator + (Complex& lhs, Dummy& rhs) {
	cout << " I'm here...!\n";
}
int main() {
	Complex obj(10, 20);
	Dummy dummy;

	obj + dummy;
}
#endif
int main_01() {
	Complex obj(10, 20);

	//obj + 4;
	//::operator +(obj, 5);

//	obj + 4 + 5;
	cout << "-------------\n";
	++obj;
	cout << "-------------\n";
	obj++;
	cout << "-------------\n";
	return 0;
}