//variant 3
//33  "c"  n = 3  (bait)
//33) y=(a+b)*c-d/e 
//в виде двух массивов: массива аргумента, 
//содержащего n пар значений “порядковый номер - аргумент”, и массива функции, 
//содержащего n пар значений “порядковый номер - функция”;
//аргумент mass[i +1]
//функция mass[i]
//порядковый номер mass[i+2]

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	__int8 a11 = 6; //переменная a11
	__int8 b11 = 2;
	__int8 c11 = 3;
	__int8 d = 4;
	__int8 e = 2;
	__int8 h = 4;
	__int8 y;
	__int8 mass1[20];
	__int8 mass2[20];
	_asm {
		
		mov ecx, 10
		
		lea esi, mass1
		
			cycle2:
			//(a + b) * c - d / e
			mov al, a11
			add al, b11
			imul c11
			mov bl, d
			cbw
			idiv e
			sub al, bl
			//значение функции
			mov[esi], al
			add esi, 1
		
			mov[esi], ecx
			add esi, 1
			
				mov al, h
				add c11, al
			loop cycle2
				mov ecx, 10
				lea esi, mass2
				cycle1:
			//(a + b) * c - d / e

				//значение аргумента
				mov al, c11
				mov[esi], al
				add esi, 1
				mov[esi], ecx
				add esi, 1

				mov al, h
				add c11, al
				loop cycle1
	}
	
	
	printf("Порядковый номер   | Функция  \n");
	
	for (int i = 0; i < 20; i += 2) {
		printf("%d                  | %d", mass1[i + 1], mass1[i]);
		printf("\n");
	}
	printf("Порядковый номер   | Аргумент\n");
	for (int i = 0; i < 20; i += 2) {
		printf("%d                  | %5d", mass2[i + 1], mass2[i]);
		printf("\n");
	}
	
	
	return 0;
}
