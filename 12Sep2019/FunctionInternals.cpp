/* Calling convensions:
stdcall: The Calley unwinds the stack for it's arguments.
cdecl: The caller unwinds the stack for Calley arguments.
fastcall: Request to store in register.
thiscall: 
*/

//VC++: void __stdcall fun(int x, int y) // Calley
//g++: void __attibute__((stdcall)) fun(int x, int y) // Calley

void __fastcall fun(int x, int y, int z, ...) // Calley
// offset(args): sum_sizes_args_declared_before + sizeof(context_switch)
// offset(x): 0+8
// offset(y): 4+8
{ /* Prologue
	push ebp
	mov ebp, esp
	sub esp, sizeof(locals) // for m,n
  */
	int m, n;

	// use m,n,x,y
	x = m - n + y;
	/*
		mov Acc, [m] => ebp + offset(m) =>  -4
		sub Acc, [n] => ebp + offset(n) =>  -8
		add Acc, [y] => ebp + offset(y) =>  +12
		mov [x], Acc => ebp + offset(x) => +8
	*/
} /*
	add esp, sizeof(locals)
	or 
	mov esp, ebp
	pop ebp
	ret
  */

int main() { // Caller
	int a = 10, b = 20;
// offset(locals): -(sum_sizes_locals(declared_before) + it's_size)
// offset(a): -(0+4)
// offset(b): -(4+4)
	/*
		sub esp, sizeof(int) // for a
		sub esp, sizeof(int) // for b
		or
		sub esp, sizeof(locals)

	*/

	a = a + b;
	/*
		mov Acc, [a] => [a] => ebp + offset(a)
		add Acc, [b] => [b] => ebp + offset(b)
		mov [a], Acc => [a] => ebp + offset(a)
	*/
	fun(a, b, 40);
	/*
		push [b]
		push [a]
		call fun
	*/
}




