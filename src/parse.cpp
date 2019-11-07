#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
#include <functional>

int main() {
	std::vector<std::string> words;
	std::string filename;

	std::cout << "Filename to parse? " << std::endl;
	std::cin >> filename;
	std::ifstream infile( filename );

	std::string line;
	while ( std::getline( infile, line ) ) {
		std::string line_without_punctuation;

		// Clear out punctuation
		line.erase ( std::remove_if ( line.begin (), line.end (), ispunct ), line.end ());

		std::istringstream iss( line );

		copy( std::istream_iterator<std::string>( iss ),
			std::istream_iterator<std::string>(),
			back_inserter( words ) );
	}

	// Make unique
	std::unique_ptr<std::vector<std::string>> unique_words = std::make_unique<std::vector<std::string>>( words );
	// TODO: delete punctuation + words shorter than 4 characters
	//words.erase( std::unique( words.begin(), words.end(), words.end() ) );

    std::ofstream outFile("dictionary.txt");
    // the important part
    for ( const auto &w : *unique_words ) {
		outFile << w << std::endl;
	}
}