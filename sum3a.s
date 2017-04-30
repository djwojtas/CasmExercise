	.type sum3a, @function #informacja dla debuggera jakby cos nam nie siadlo za 1 razem
        .globl sum3a #bez tego linker nie bedzie wiedzial o istnieniu tej fukcji
sum3a:
	mov %rdi, %rax #przesuwamy int a do wartosci zwracanej
	add %rsi, %rax #dodajemy int b do wart. zwracanej
	add %rdx, %rax #dodajemy int c do wart. zwracanej
	ret #nara

