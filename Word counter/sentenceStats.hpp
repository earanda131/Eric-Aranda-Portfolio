#ifndef SENTENCESTATS_HPP_
#define SENTENCESTATS_HPP_

#include <fstream>
#include <string>
#include <map>

#include "mr.hpp"

namespace mr {

class sentenceStats : public MapReduce<int,int> {
public:
	virtual void MRmap(const std::map<std::string,std::string> &input,
			std::multimap<int,int> &out_values);
	virtual void MRreduce(const std::multimap<int,int> &intermediate_values,
			std::map<int,int> &out_values);
};

} /* namespace mr */

#endif /* SENTENCESTATS_HPP_ */