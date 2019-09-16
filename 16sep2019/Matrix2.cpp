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
				arr[i][j] = i * COL + j;
	}
	~Matrix() {
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << '\n';
	}
	/*
	1. Complete name: ::Matrix::Helper
	2. Access Specifiers
	3. Friend of outer class
	*/
	class Helper { // ::Matrix::Helper
		Matrix *m_p;
		int rInd;
	public:
		int operator [] (int cindex) {
			cout << "int Helper::operator [] (int cindex) : " << cindex << '\n';
			return m_p->arr[rInd][cindex];
		}
		Helper(int ri, Matrix* p) : m_p(p), rInd(ri) {}
	};
	Helper  operator [](int rindex) {
		cout << "void Matrix::operator [](int rindex) : rindex = " << rindex << "\n";

		return Helper(rindex, this);
	}
};

// ------------- App ---------------
int main() {
	Matrix obj;
	//Matrix::Helper hObj; // due to 2nd point

	//obj[2] [1];
	
	int val = obj[2][1];
	cout << "val = " << val << '\n';
	
	//[0][2] = 12345;
	//obj[1][2] = obj[3][0];
	
	cout << "--------------------\n";
}