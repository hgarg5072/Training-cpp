#include <iostream>
using namespace std;

class Complex {
	int real, imag;
public:
	Complex(int x = 0, int y = 0) :real(x), imag(y) {}
	~Complex() { cout << "this= " << this << ", Real: " << real << ", Imag: " << imag << '\n'; }
	int getImag() { return imag; }
	void setImag(int val) { imag = val; }
	Complex& operator +(int rhs) { 
		cout << "void operator +(int rhs) : rhs= " << rhs << '\n';
		imag += rhs; 
		return *this;
	}
};

/*
void operator+(Complex& lhs, int rhs) {
	cout << "void operator+(Complex& lhs, int rhs): rhs= " << rhs << '\n';
	//lhs.imag += rhs;
	lhs.setImag( lhs.getImag() + rhs);
}
*/
int main() {
	Complex obj(10, 20);
	/*
		sub esp, sizeof(Complex)
		push 20
		push 10
		push &obj // this
		call Complex::Complex(int x=0, int y=0)
	*/

	obj + 4 + 5;
	/*
		push 4	 //rhs
		push &obj // lhs // this
		Complex & namelessRef = call Complex::operator+(int rhs)

		push 5	 //rhs
		push &namelessRef // lhs // this
		Complex & namelessRef = call Complex::operator+(int rhs)

	*/
	//obj.operator+(4).operator+(5);

	cout << "---------------\n";
	//::operator+(obj, 5);
	//obj.operator+(5);
	cout << "---------------\n";
}