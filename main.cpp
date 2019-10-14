#include <iostream>
#include <string>
#include <vector>

void printHintSoFar( std::vector<char> guessed_letters ) {
	std::string str( guessed_letters.begin(), guessed_letters.end() );
	std::cout << str << std::endl;
}

bool compareVectorToString( std::vector<char> vec, std::string str ) {
	std::string converted_vector( vec.begin(), vec.end() );

	return ( str == converted_vector );
}

std::vector<size_t> findAllOccurrencesOfCharInString( std::string data, char toSearch )
{
	std::vector<size_t> vec;
	// Get the first occurrence
	size_t pos = data.find( toSearch );
 
	// Repeat till end is reached
	while( pos != std::string::npos )
	{
		// Add position to the vector
		vec.push_back( pos );
 
		// Get the next occurrence from the current position
		pos = data.find( toSearch, pos + 1 );
	}
	return vec;
}

bool findInVector( std::vector<char> haystack, char needle) {
	for ( auto & elem : haystack ) {
		std::cout << "Elem: " << elem << ", needle: " << needle << std::endl;
		if ( elem == needle ) {
			std::cout << "You have already typed the character: " << needle << std::endl;
			std::cout << "Please try with another letter!" << std::endl;
			return true;
		}
	}
	return false;
}

int main() {
	std::string hint;
	int errors = 0;
	const int MAX_ERRORS = 7;

	hint = "whatever";

	// To convert string into vector:
	//const std::vector<char> charvect(json_str.begin(), json_str.end()); 
	std::vector<char> guessed;
	std::vector<size_t> matches;
	std::vector<char> previous_attempts;

	for ( int i; i < hint.length(); ++i ) {
		guessed.push_back( '_' );
	}

	while ( errors < MAX_ERRORS ) {
		char guessed_char = 0;

		std::cout << "Guess a character" << std::endl;
		std::cin >> guessed_char;

		if ( findInVector( previous_attempts, guessed_char ) ) {
			continue;
		}
		previous_attempts.push_back( guessed_char );
		// TODO: some validation on the char!

		// TODO: check if the character has already been searched for (add a vector of characters that have been already typed in)
		matches = findAllOccurrencesOfCharInString( hint, guessed_char );
		if ( ! matches.empty() ) {
			std::cout << "Character " << guessed_char << " found!" << std::endl;
			while ( ! matches.empty() ) {
				guessed[ matches.back() ] = guessed_char;
				matches.pop_back();
			}
		} else {
			// TODO: adds one to hangman, draw something!
			errors++;
			std::cout << guessed_char << " was not found, you have " << ( MAX_ERRORS - errors ) << " errors left!" << std::endl;
		}
		if ( compareVectorToString( guessed, hint ) ) {
			std::cout << "You got it right!" << std::endl;
			exit( 1 );
		}
		printHintSoFar( guessed );
	}
}
