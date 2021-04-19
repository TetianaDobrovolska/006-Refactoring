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

	string delimiter = ",\n";

	size_t pos = 0;
	int sum = 0;
	int num = 0;

	do {
		if (numbers.find(delimiter[0]) < numbers.find(delimiter[1])) {
			pos = numbers.find(delimiter[0]);
		}
		else {
			pos = numbers.find(delimiter[1]);
		}
		num = atoi(numbers.substr(0, pos).c_str());
		if (num < 0) {
			sum = -1; 
			break;
		}
		sum += num;
		numbers.erase(0, pos + 1);
	} while (pos != string::npos);


	return sum;

}