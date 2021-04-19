#include "string_calc.hpp"

#include <vector>

#include <algorithm>



using namespace std;



StringCalc::StringCalc()

{

}





StringCalc::~StringCalc()

{

}

int StringCalc::Add(string numbers)

{

	string delimiter = ",";

	int pos = 0;
	int num = 0;
	int sum = 0;

	do {
		pos = numbers.find(delimiter);
		num = atoi(numbers.substr(0, pos).c_str());
		if (num < 0) {
			sum = -1; 
			break;
		}
		sum += num;
		numbers.erase(0, pos + delimiter.length());
	} while (pos != string::npos);	

	return sum;

}