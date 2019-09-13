#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
	int data;
public:
	Node *next;
	Node(Node *p, int info) : data(info), next(p) {}
	~Node() {
		cout << " The deleted node is: " << data << endl;
		if (next)
			delete next;
	}
	friend ostream& operator <<(ostream& os, Node& rhs) {
		os << rhs.data << " ";
		return os;
	}
};

class List {
	Node *head;
public:
	List() :head(nullptr) {}
	List &operator ++();
	List &operator --();
	List &operator --(int);
	friend ostream& operator <<(ostream& os, List& rhs) { 
		if (rhs.head) {
			for (Node *trav = rhs.head; trav; trav = trav->next)
				os << *trav << ", ";
			cout << '\n';
		}
		else cout << " No nodes to display...\n";
		return os; 
	}
};


List & List::operator ++() {
	int value = 0;

	cout << " Enter value to be pushed: ";
	cin >> value;
	cout << '\n';
	head = new Node(head, value);
	return *this;
}

List &List::operator --() {
	if (head) {
		Node * temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
	}
	else
		cout << " No nodes to pop\n";
	return *this;
}

List &List::operator --(int) {
	if (head) {
		delete head;
		head = nullptr;
	}
	else
		cout << " No nodes to pop All\n";
	return *this;
}

// -------------- App -------
int main() {
	List obj;
	int choice;

	while (1) {
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. PopAll\n";
		cout << "4. Display\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cout << "\n";
		cin >> choice;
		switch (choice) {
		case 1: ++obj; break;
		case 2: --obj; break;
		case 3: obj--; break;
		case 4: cout << obj; break;
		case 5:
		default:
			cout << " Program is exiting... \n";
			obj--; 
			exit(0);
		}
	}
}