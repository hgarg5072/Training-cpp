#include <iostream>
using namespace std;

#define ROW 4
#define COL 3

class Matrix {
	int arr[ROW][COL];
public:
	Matrix() {
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				arr[i][j] = i * COL + j ;
	}
	~Matrix() {
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << '\n';
	}
	int* operator [](int index) {
		cout << "void operator [](int index) : index = " << index << "\n";

		return arr[index];
	}
};

// ------------- App ---------------
int main() {
	Matrix obj;

	//obj[2] [1];
	int val = obj[2][1];
	cout << "val = " << val << '\n';

	obj[0][2] = 12345;
	obj[1][2] = obj[3][0];
	cout << "--------------------\n";
}