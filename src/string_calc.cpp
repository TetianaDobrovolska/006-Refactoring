#include "string_calc.hpp"

#include <vector>

#include <algorithm>

#include <regex>



using namespace std;



int const UPPER_LIMIT = 1000;

int const LOWER_LIMIT = 0;



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

	

	regex expr("-?([0-9]*)(?!\n|,)-?([0-9]*)|(?!//[^A-Za-z0-9]*\n)-?([0-9]*)(?!/[^A-Za-z0-9]*)-?([0-9]*)");

	regex_token_iterator<string::iterator> iter (numbers.begin(), numbers.end(), expr);

	regex_token_iterator<string::iterator> end;

	while (iter != end) {

		num = atoi(iter->str().substr(0, iter->str().length()).c_str());

		if (LOWER_LIMIT < 0) {

			throw invalid_argument("Number must be positive.");	

		}

		else if (num <= UPPER_LIMIT) {

			sum += num;

		}

		++iter;

	}



	return sum;

}