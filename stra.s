	#funcja nie jest jednakowa do tej w C!!
	#w przypadku podania n=0 ta funkcja wykona i tak 1 przejscie, ta w C nie.
	#zrobilem tak bo jest wydajniej :>
	#na kolosie polecam zrobienie sprawdzenia na poczatku i bezwarunkowego skoku na koncu petli

	.type stra, @function #informacja dla debuggera jakby cos nam nie siadlo za 1 razem
	.globl stra #bez tego linker nie bedzie wiedzial o istnieniu tej fukcji
stra:
	mov $0, %rcx #wyzerowanie rcx - czyli takie jakby int i=0 do petli for
chngc:
	#przeniesienie znaku w rejestrze dx (czyli znak startowy) do bufora
	#konkretnie do adresu znajdujacego sie w rdi, z offsetem rcx, 1 to wielkosc danych
	#czyli znaczy to takie rdi[rcx] w C, a to 1 bo char, jakby byl int to by bylo 4 itp
	mov %dx, (%rdi,%rcx,1)
	inc %rcx #zwiekszenie naszego int i w ramach iteracji bo buforku
	inc %rdx #zwiekszenie znaku ktorego wpisujemy o 1
	cmp %rcx, %rsi #porownanie int i z wymagana iloscia znakow
	jne chngc #jak nie sa rowne to robimy kolejna iteracje

	mov %rdi, %rax #w przeciwnym wypadku przenosimy adres bufora do rax - czyli wartosc zwracana
	ret #elo
