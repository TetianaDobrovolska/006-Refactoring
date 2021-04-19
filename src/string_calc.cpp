#include "string_calc.hpp"

#include <vector>

#include <algorithm>
#include <regex>



using namespace std;



StringCalc::StringCalc()

{

}





StringCalc::~StringCalc()

{

}





int StringCalc::Add(string numbers)

{

	int sum = 0;
	int num = 0;
	numbers += ",";

	regex expr("-?([0-9]*)(?=\n|,)-?([0-9]*)");
	regex_token_iterator<string::iterator> iter (numbers.begin(), numbers.end(), expr);
	regex_token_iterator<string::iterator> end;
	while (iter != end) {
		num = atoi(iter->str().substr(0, iter->str().length()).c_str());
		if (num < 0) {
			sum = -1;
			break;
		}
		sum += num;
		++iter;
	}

	return sum;

}