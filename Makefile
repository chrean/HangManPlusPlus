all: hangman

hangman: main.o
	g++ -o hangman main.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm main.o hangman