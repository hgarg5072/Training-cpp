#include <iostream>
using namespace std;

#define MAX 5

template <typename T>
class MyVector {
	T arr[MAX]; // Allocator
	int top;
public:
	MyVector() :top(-1) {}
	MyVector& push_back(T value) { arr[++top] = value; return *this; }
	T operator [](int index) { return arr[index]; }
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
		Iterator operator ++() { ++m_ind; return *this; }
		T& operator *() { return m_p->arr[m_ind]; }
	};
	Iterator begin() { return Iterator(this, 0); };
	Iterator end() { return Iterator(this, MAX); };
};

int main_myVector() {
	MyVector<int> vObj;

	for (int i = 0; i < MAX; i++)
		vObj.push_back(50 + i); // vObj.emplace_back()

	for (int i = 0; i < MAX; i++)
		cout << " vObj[" << i << "]= " << vObj[i] << "\n ";

	//MyVector<int>::Iterator it = vObj.begin();
	auto it = vObj.begin();

	for (; it != vObj.end(); ++it)
		cout << " *it = " << *it << "\n";
	return 0;
}


#include <vector>
int main() {
	vector<int> vObj;

	for (int i = 0; i < MAX; i++)
		vObj.push_back(50 + i); // vObj.emplace_back()

	for (int i = 0; i < MAX; i++)
		cout << " vObj[" << i << "]= " << vObj[i] << "\n ";

	//MyVector<int>::Iterator it = vObj.begin();

	vector<int>::iterator it = vObj.begin();
	//auto it = vObj.begin();

	for (; it != vObj.end(); ++it)
		cout << " *it = " << *it << "\n";

}
