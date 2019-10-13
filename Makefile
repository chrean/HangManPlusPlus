all: hangman

hangman: main.o
	g++ -o hangman main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm main.o hangman