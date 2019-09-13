#include <iostream>
using namespace std;

#if 0
class Complex {
	int real, imag;
public:
	Complex(int x = 0, int y = 0) :real(x), imag(y) {}
	~Complex() { cout << "this= " << this << ", Real: " << real << ", Imag: " << imag << '\n'; }
	Complex& operator +(int rhs) {
		cout << "void operator +(int rhs) : rhs= " << rhs << '\n';
		imag += rhs;
		return *this;
	}
	//void __thiscall operator+( Complex *const this, int lhs, Complex &rhs)

	//friend void operator+(int lhs, Complex &rhs);
	friend void operator+(int lhs, Complex &rhs) {
		cout << "void operator+(int lhs, Complex &rhs): lhs= " << lhs << '\n';
		rhs.real += lhs;
	}
};

/*
void operator+(int lhs, Complex &rhs) {
	cout << "void operator+(int lhs, Complex &rhs): lhs= " << lhs << '\n';
	rhs.real += lhs;
}
*/
int main() {
	Complex obj(10, 20);

	//obj + 4;
	// obj.operator+(4);

	5 + obj;
	// ::operator + (5, obj);
}
#endif




#if 0
class Complex {
	int real, imag;
	friend ostream& operator << (ostream &os, Complex& rhs);
public:
	Complex(int x = 0, int y = 0) :real(x), imag(y) {}
	~Complex() { cout << "this= " << this << ", Real: " << real << ", Imag: " << imag << '\n'; }
};

ostream& operator << (ostream &os, Complex& rhs) {
	os << rhs.real << " +j " << rhs.imag << "\n";
	return os;
}
int main() {
	Complex obj(10, 20);

	cout << obj ;
	cout << "---------------\n";
}
#endif



class Complex {
	int real, imag;
	friend ostream& operator << (ostream &os, Complex& rhs);
public:
	Complex(int x = 0, int y = 0) :real(x), imag(y) {}
	~Complex() { cout << "this= " << this << ", Real: " << real << ", Imag: " << imag << '\n'; }
	Complex& operator ++();
	Complex& operator ++(int );
};

Complex& Complex::operator ++() {
	cout << " Complex& operator ++(): this= " << this << endl;
	++real;
	return *this;
}

Complex& Complex::operator ++(int Dummy) {
	cout << " Complex& operator ++(int Dummy): this= " << this <<":Dummy= "<< Dummy<< endl;
	++imag;
	return *this;
}

ostream& operator << (ostream &os, Complex& rhs) {
	os << rhs.real << " +j " << rhs.imag << "\n";
	return os;
}

int main() {
	Complex obj(10, 20);

	cout << "-----------------\n";
	++obj;
	// obj.operator++()
	cout << "-----------------\n";
	obj++;
	// obj.operator++(0)
	cout << "-----------------\n";
}





