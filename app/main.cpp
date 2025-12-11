#include "MyPriorityQueue.hpp"
#include "convert.hpp"
#include <iostream>
#include <fstream>

int main()
{
	std::string WORD_ONE, WORD_TWO;

    std::cout << "Enter the start word: ";
    std::cin >> WORD_ONE;

    std::cout << "Enter the target word: ";
    std::cin >> WORD_TWO;

	if (WORD_ONE.length() != WORD_TWO.length()) {
		std::cerr << "Error: start and target words must be the same length.\n";
		return 1;
	}

	std::unordered_set<std::string> words;
	std::ifstream in("../words.txt");
	loadWordsIntoTable(words, in);

 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);
	if (r.empty()) {
        std::cout << "No valid transformation sequence found.\n";
    }
	return 0;
}

