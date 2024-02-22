#include <iostream>

int main() {
	int y = 0;
	_asm {
		mov ecx, 10
		xor ebx, ebx
		xor eax, eax
		sum:
			mov ax, cx
			mul ax // result is dx:ax
			add ebx, eax
		loop sum
		mov y, ebx
	}
	std::cout << "sum my:" << y << '\n';
	_asm {
		//push esi
		mov ecx, 10
		xor ebx, ebx
		mov esi, 1
		cycle:
			mov eax, esi
			mul eax
			add ebx, eax
			inc esi
		loop cycle
		mov y, ebx
	}
	std::cout << "sum konach:" << y << '\n';
	short y1;
	_asm
	{
		mov ecx, 10
		xor bx, bx
		cikl11 :
			mov ax, cx
			mul ax
			add bx, ax
		loop cikl11
		mov y1, bx
	}
	std::cout << "y=" << y1 << std::endl;
	_asm {
		mov ecx, 10
		cycle2: // cannot name cycle
			mov eax, 2
			mul ecx
			dec eax
			mov esi, eax
			mul esi
			mul esi
			add y, eax
		loop cycle2
	}
	std::cout << "y=" << y << std::endl;
	y = 0;
	_asm {
		mov ecx, 10
		lop1:
			push ecx
			mov esi, ecx // esi -> i
			mov ecx, 10
			lop2:
				mov eax, ecx // eax -> n -> ecx
				imul eax, 5 // 5n
				sub eax, esi // 5n - i
				add y, eax
			loop lop2
			pop ecx
		loop lop1
	}
	std::cout << "y=" << y << std::endl;
	_asm
	{
		mov ecx, 10
		mov esi, 1
		xor ebx, ebx
		lab2 :
		push ecx
			mov ecx, 10
			lab1 :
			mov eax, 5
			mul ecx
			sub eax, esi
			add ebx, eax
			loop lab1
			pop ecx
			inc esi
			loop lab2
			mov y, ebx
	}
	std::cout << "y=" << y << std::endl;
	//3.4
	y = 0;
	_asm {
		xor ebx, ebx // ebx=y
		mov ecx, 5 // k
		l1:
			mov esi, 6 // n
			l2:
				dec esi
				mov eax, esi // eax = n
				imul eax // n^2
				add eax, ecx // n^2 + k
				imul eax // (n^2+k)^2
				add ebx, eax
				cmp esi, ecx
			jne l2
		loop l1
		mov y, ebx
	}
	std::cout << "y=" << y << std::endl;
	//3.5
	y = 0;
	_asm {
		xor ebx, ebx // ebx=y
		xor eax, eax
		mov ecx, 5 // k
		ll1:
			mov esi, 6 // n
			ll2 :
				dec esi
				mov eax, esi // eax = n
				imul eax // n^2
				mov edx, eax // edx = n^2
				mov eax, ecx // eax = k
				imul eax // k^2
				add eax, edx // n^2 + k^2
				imul eax // (n^2 + k^2)^2
				add ebx, eax
				cmp esi, ecx
			jne ll2
		loop ll1
		mov y, ebx
	}
	std::cout << "y=" << y << std::endl;
}