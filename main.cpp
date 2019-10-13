#include <iostream>
#include <string>
#include <vector>

void printHintSoFar( std::vector<char> guessed_letters ) {
	std::string str( guessed_letters.begin(), guessed_letters.end() );
	std::cout << str << std::endl;
}

int main() {
	std::string hint;
	int errors = 0;
	const int MAX_ERRORS = 7;

	hint = "whatever";

	std::vector<char> guessed;

	for ( int i; i < hint.length(); ++i ) {
		guessed.push_back( '_' );
	}

	while ( errors < MAX_ERRORS ) {
		char guessed_char = 0;

		std::cout << "Guess a character" << std::endl;
		std::cin >> guessed_char;
		std::cout << "You typed " << guessed_char << std::endl;

		int pos = hint.find( guessed_char );
		if ( pos != std::string::npos ) {
			guessed[ pos ] = guessed_char;
		} else {
			// TODO: adds one to hangman
			errors++;
			std::cout << guessed_char << " was not found, you have " << ( MAX_ERRORS - errors ) << " errors left!" << std::endl;
		}
		printHintSoFar( guessed );
	}
}
