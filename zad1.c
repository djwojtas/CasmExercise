#include <stdio.h>
#include <stdlib.h>

//przykladowa kompilacja: gcc -Wall zad1.c stra.s sum3a.s

/*
Przedrostek r to 64 bity, dla 32 dajemy e, np. rax => eax
Przykladowe dzielenie rejestrow
                                                  AH      AL
|                              |               |       |       |
                              RAX             EAX     AX

rax - 64 bity
eax - mlode 32 bity
ax - mlode 16 bitow
ah - stare 8 bitow rejestru ax
al - mlode 8 bitow

dla np rejestru rdx bloby to rdx, edx, dx, dh, dl

Cheat sheet do asm podpinanego do C:
	Po kolei argumenty przekazywane do fukcji:
		rdi
		rsi
		rdx
		rcx
		r8
		r9
		reszta NA STOS OGIEN JE OCZYSCI
	Wartosci zwracane:
		rax
		rdx (jak cos jest duze)
	Chronione sa rejestry:
		rbp
		rbx
		r12
		r13
		r14
		r15
	Chronione to znaczy ze albo nie ruszamy ich w asm albo
	musimy zapamietac ich wartosc np na stosie.
	Jak tego nie zrobimy to bedzie undefined behavior czyli
	powo z debugowaniem siupa over 9000

	Rejestr rsp to wskaznik stosu, nie potrzebny w tym zadaniu
*/

//ma dodac 3 liczby
long long sum3c(int a, int b, int c) {
	return a + b + c;
}

long long sum3a(int a, int b, int c);

//przyjmuje wskaznik na bufor, ilosc znakow do wpisania oraz znak startowy, zwraca wskaznik na ten sam bufor
//np strc(buf, 10, '0') => buf = {0,1,2,3,4,5,6,7,8,9}
char* strc(char* buf, int n, int c) {
	int i;
	for(i=0; i<n; ++i) {
		buf[i] = c+i;
	}
	return buf;
}

char* stra(char* buf, int n, int c);

int main() {
	int i, a = 1, b = 2, c = 3;
	printf("%d + %d + %d = (C) %lld = (asm) %lld\n", a, b, c, sum3c(a,b,c), sum3a(a,b,c));
	int n = 10, ch = 'a';
	//rezerwacja miejsca na n znakow + null
	char* buf = malloc(sizeof(char)*(n+1));

	buf = strc(buf, n, ch);
	//dodanie nulla na pozycji n zeby printf nie wyhasal na segfaulta
	buf[n] = '\0';
	printf("\nC str: %s", buf);

	//przemieszanie stringa tak zeby nie bylo ze funkcja w asm nic nie zrobila
	for(i=0; i<n; ++i) {
		buf[i] = '0' + i;
	}
	printf("\nMangled str: %s", buf);

	buf = stra(buf, n, ch);
	printf("\nAsm str: %s\n", buf);
}
