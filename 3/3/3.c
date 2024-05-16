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
	__int8 a = 6, b = 2, c = 3, d = 4, e = 2, h = 4, y, mass1[20], mass2[20];
	_asm {
		
		mov ecx, 10
		
		lea esi, mass1
		
			cycle2:
			//(a + b) * c - d / e
			mov al, a
			add al, b
			imul c
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
				add c, al
			loop cycle2
				mov ecx, 10
				lea esi, mass2
				cycle1:
			//(a + b) * c - d / e

				//значение аргумента
				mov al, c
				mov[esi], al
				add esi, 1
				mov[esi], ecx
				add esi, 1

				mov al, h
				add c, al
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
