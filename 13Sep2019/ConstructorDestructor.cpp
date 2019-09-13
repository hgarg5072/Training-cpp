#include <iostream>
using namespace std;

class cA {
	int m_i;
	int m_j;
	int *ip;
public:
	cA() { cout << "Default cA cons: this= " << this << '\n'; m_i = m_j = 0; 
		ip = (int*)malloc(sizeof(int));
		*ip = 1234;
		cout << "cA::cA: ip= " << ip << ", *ip = "<< *ip <<'\n';
	}
	void display() { cout << "cA::display: this= " << this << ", m_i= " << m_i << ", m_j= " << m_j << '\n'; }

	~cA() { 
		cout << "cA Des: this= " << this << '\n'; 
		if (ip) {
			cout << " Released resource of ip = " << *ip << '\n';
			free(ip);
			ip = NULL; // nullptr;
		}
	}
};


void helper(cA &ref) {
	ref.~cA();
}

void fun_default() {
	cA obj;
	/*
		sub esp, sizeof(cA) // for obj
		call cA::cA
	*/

	obj.display();
	cout << "------------------\n";
	obj.~cA();
	//helper(obj);
	cout << "------------------\n";
} // obj.~cA()
 // add esp, sizeof(cA) // obj

int main() {
	fun_default();
}