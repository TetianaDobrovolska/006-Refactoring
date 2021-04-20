#include "string_calc.hpp"
#include <vector>
#include <algorithm>
#include <regex>
#include <numeric>

using namespace std;

StringCalc::StringCalc()
{
}


StringCalc::~StringCalc()
{
}


int StringCalc::Add(string numbers)
{
	int sum_of_elems = 0;
	std::replace(numbers.begin(), numbers.end(), '\n', ',');
	if(!numbers.empty()){
		vector<int> vect;
		static const regex regular("\\d+");
		int i = 0;
		while(i != -1) {
			string temp = numbers.substr(i, numbers.find(",", i+1));
    		regex_token_iterator<string::iterator> num( temp.begin(), temp.end(), regular);
    		string t = *num;
    		int elem = atoi( t.c_str() );
			i = numbers.find(",", i+1);
			vect.push_back(elem);
		}
		sum_of_elems = std::accumulate(vect.begin(), vect.end(), 0);
	}
	return sum_of_elems;
}
