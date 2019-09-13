

void fun(void) {}
/*
In C: _fun
In GCC: funv
In VC++: ? fun @@YA X X Z
*/

extern "C++" {
	void fun(int) {}
	/*
	In C: _fun
	In G++: funi
	In VC++: ? fun @@YA X H @Z
	*/

	void fun(float) {}
	/*
	In C: _fun
	In G++: funf
	In VC++: ? fun @@YA X M @Z
	*/
	void fun(int, float) {}
	/*
	In C: _fun
	In G++: funif
	In VC++: ? fun @@YA X HM @Z
	*/
	//void fun(float, int) {} // fun(1.1f, 12)
	/*
	In C: _fun
	In G++: funfi
	In VC++: ? fun @@YA X MH @Z
	*/

	//int fun(float, int) {} // int retVal = fun(2.1f, 45)
	/*
	In C: _fun
	In G++: funfi
	In VC++: ? fun @@YA H MH @Z
	*/

}
int main() {
	fun();
	// call funv
	fun(10);
	// push 10
	// call funi

	fun(2.1f);
}





