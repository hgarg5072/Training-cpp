/*
Calling convensions:
stdcall: Calley unwinds the stack for it's arguments.
cdecl: Caller unwinds the stack for Calley arguments.
fastcall: VC++
thiscall:
*/

// gcc: void __attribute__((stdcall)) fun(int x, int y) // Calley
// VC++: void __stdcall fun(int x, int y) // Calley
void __fastcall fun(int x, int y, int z, ...) // Calley
// offset(arg): +( sum_sizes_args_declared_before + sizeof(context_switch))
// offset(x): +( 0+8)
// offset(y): +( 4+8)
{ /* Prologue
	push ebp
	mov ebp, esp
	sub esp, sizeof(locals)
  */
	int m, n;

	// use m, n, x, y
	x = m - n + y;
	/*
		mov Acc, [m] => ebp + offset(m) => -(0+4) => -4
		sub Acc, [n] => ebp + offset(n) => -(4+4) => -8
		add Acc, [y] => ebp + offset(y) =>
		mov [x], Acc => ebp + offset(x) => +8
	*/
} /* Epilogue
	add esp, sizeof(locals)
	or
	mov esp, ebp
	pop ebp
	ret
  */

int main() { // CAller
	int a = 10, b = 20;
	//offset(locals): -( sum_sizes_locals_declared_before + it's size)
	// offset(a): -(0+4) => -4
	// offset(b): -(4+4) => -8
	/*
		sub esp, sizeof(int) // for a
		sub esp, sizeof(int) // for b
		or
		sub esp, sizeof(locals)
	*/

	// use a, b
	//a = a + b;
	/*
		mov Acc, [a] => ebp + offset(a) => 
		add Acc, [b] => ebp + offset(b) =>
		mov [a], Acc => ebp + offset(a) =>
	*/
	fun(a, b, 40);
	/*
		push b
		push a
		call fun
	*/
}






