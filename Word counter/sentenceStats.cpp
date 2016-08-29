#include <sstream>     	// std::istringstream
#include <fstream>
#include <map>		// std::multimap
#include <algorithm>   	// std::copy, std::for_each

#include "mr.hpp"
#include "ioutils.hpp"
#include "sentenceStats.hpp"

namespace mr {

void
sentenceStats::MRmap(const std::map<std::string,std::string> &input,
					std::multimap<int,int> &out_values) {
	IOUtils io;
	// input: in a real Map Reduce application the input will also be a map
	// where the key is a file name or URL, and the value is the document's contents.
	// Here we just take the string input and process it.
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);

		// Split up the input into words
		std::istringstream iss(inputString);
		int word_count = 0;
		do {
			std::string word;
			iss >> word;
			word_count += 1;
			for(int i = 0; i < word.length(); i++) {
				if(word[i] == '.' || word[i] == '!' || word[i] == '?') {
					out_values.insert(std::pair<int,int>(word_count,1));
					word_count = 0;
				}
			}
		} while (iss);				
	}
}

// A specialized reduce function with string keys and int values
void
sentenceStats::MRreduce(const std::multimap<int,int> &intermediate_values,
					std::map<int,int> &out_values) {

	// Sum up the counts for all intermediate_values with the same key
	// The result is the out_values map with each unique word as
	// the key and a total count of occurrences of that word as the value.
	std::for_each(intermediate_values.begin(), intermediate_values.end(),
			// Anonymous function that increments the sum for each unique key (word)
			[&](std::pair<int,int> mapElement)->void
			{
				out_values[mapElement.first] += 1;
			});  // end of for_each
			
	out_values.erase(0);		
	int min = out_values.begin()->first;
	int max = out_values.rbegin()->first;
	double total = 0.0;
	for(auto it = out_values.begin(); it != out_values.end(); ++it) {
		total += it->first;
	}
	
	std::cout << "Maximum sentence length: " << max << " words" << std::endl;
	std::cout << "Minimum sentence length: " << min << " words" << std::endl;
	std::cout << "Average sentence length: " << total / out_values.size() << " words" << std::endl;
}

};