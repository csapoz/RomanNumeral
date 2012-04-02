CC=g++
CFLAGS=-I.

RomanNumeral_test: RomanNumeral.cpp RomanNumeral_test.cpp
	$(CC) -o RomanNumeral_test RomanNumeral.cpp RomanNumeral_test.cpp $(CFLAGS)
	./RomanNumeral_test

clean:
	rm -rf *.o RomanNumeral_test

