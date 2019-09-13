
void fun(void) {}
/*
In C: _fun
In g++: funv
In VC++: ? fun @@YA X X Z
*/
extern "C++" {
	void fun(int) {}
	/*
	In C: _fun
	In g++: funi
	In VC++: ? fun @@YA X H @Z
	*/
}

extern "C++" {
	void fun(float) {}
	/*
	In C: _fun
	In g++: funf
	In VC++: ? fun @@YA X M @Z
	*/

	void fun(char) {}
	/*
	In C: _fun
	In g++: func
	In VC++: ? fun @@YA X D @Z
	*/

	void fun(char *) {}
	/*
	In C: _fun
	In g++: funpc
	In VC++: ? fun @@YA X ? @Z
	*/
}
int main() {
	fun();
	fun(10);
}