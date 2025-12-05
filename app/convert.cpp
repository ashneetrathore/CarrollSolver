#include "convert.hpp"
#include "MyPriorityQueue.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <map>

struct Bundle 
{
	std::string s;
	int LCD;
	int priority;
	inline bool operator<(const Bundle &x) {
		if (this->priority == x.priority) {
			if (this->LCD < x.LCD) {
				return true;
			}
			else {
				return false;
			}
		}
		return this->priority < x.priority;
	}
	inline bool operator==(const Bundle &x) {

		if (this->priority == x.priority) {
			if (this->LCD == x.LCD) {
				return true;
			}
			else {
				return false;
			}
		}
		return this->priority == x.priority;
	}
};

void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}

int diff_btwn_s2(const std::string & curr, const std::string & s2) {
	int diff_count = 0;
	for (int i = 0; i < curr.size(); i++) {
		if (curr[i] != s2[i]) {
			diff_count += 1;
		}
	}
	return diff_count;
}

std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words)
{
	std::vector<std::string> path;
	std::map<std::string, std::string> path_mapping;
	std::unordered_set<std::string> discovered;
	MyPriorityQueue<Bundle> pQueue;

	if (s1 == s2) {
		return path;
	}
	Bundle b1;
	b1.s = s1;
	b1.LCD = 0;
	b1.priority = b1.LCD + diff_btwn_s2(s1, s2);
	pQueue.insert(b1);
	discovered.insert(b1.s);
	bool path_end = false;

	while(pQueue.isEmpty() != true) {
		Bundle frontBundle = pQueue.min();
		pQueue.extractMin();
		std::string front = frontBundle.s;
		
		for (int i = 0; i < front.size(); i++) {
	 		std::string adjv = front;
	 		for (char x = 'a'; x <= 'z'; x++) {
	 			adjv[i] = x;
	 			if (words.count(adjv) != 0) {
	 				if (discovered.count(adjv) == 0) {
						Bundle newb;
						newb.s = adjv;
						newb.LCD = frontBundle.LCD + 1;
						newb.priority = newb.LCD + diff_btwn_s2(adjv, s2);
						pQueue.insert(newb);
	 					discovered.insert(adjv);
	 					path_mapping.insert({adjv, front});
					}
	 			}
	 			if (adjv == s2) {
	 				path_end = true;
	 			}
	 			if (path_end == true) {
	 				break;
	 			}
	 		}
	 	}
	 }
	if (path_end == false) {
	 	return path;
	 }
	
	std::string key = s2;
	path.push_back(s2);
	bool last_key = false;
	
	while (last_key == false) {
		path.push_back(path_mapping[key]);
		key = path_mapping[key];
		if (key == s1) {
			last_key = true;
		}
	}
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) {
		std::cout << path[i] << std::endl;
	}
	return path;
}