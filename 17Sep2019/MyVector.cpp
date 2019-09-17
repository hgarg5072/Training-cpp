#include <iostream>
using namespace std;

#define MAX 5

class MyVector {
	int arr[MAX]; // Allocator
	int top;
public:
	MyVector() :top(-1) {}
	MyVector& push_back(int value) { arr[++top] = value; return *this; }
	int operator [](int index) { return arr[index]; }
	class Iterator {
		MyVector *m_p;
		int m_ind;
	public:
		Iterator(MyVector *p, int index) : m_p(p), m_ind(index) {}
		bool operator != (Iterator rhs) { 
			if (this->m_p == rhs.m_p)
				if (this->m_ind == rhs.m_ind)
					return 0;
			return 1; 
		}
		Iterator operator ++() { ++m_ind ; return *this; }
		int& operator *() { return m_p->arr[m_ind]; }
	};
	Iterator begin() { return Iterator(this, 0); };
	Iterator end() { return Iterator(this, MAX); };
};

int main() {
	MyVector vObj;

	for (int i = 0; i < MAX; i++)
		vObj.push_back(50 + i); // vObj.emplace_back()

	for (int i = 0; i < MAX; i++)
		cout << " vObj[" << i << "]= " << vObj[i] << "\n ";

	MyVector::Iterator it = vObj.begin();

	for (; it != vObj.end(); ++it)
		cout << " *it = " << *it << "\n";



	/*
	cout << "first
		second
		third";
	*/
}
