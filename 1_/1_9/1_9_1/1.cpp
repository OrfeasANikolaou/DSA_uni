#include <iostream>
#include <ostream>
#include "1.hpp"
double fun(int* sarr, size_t sz, size_t* nsz){
	double avg = 0;
	double lower_range;
	double upper_range;
	for (size_t i = 0; i < sz; ++i){
		avg += sarr[i];
	}
	avg /= sz;
	lower_range = avg - (avg / 10);
	upper_range = avg + (avg / 10);
	std::cout << lower_range << std::endl << upper_range << std::endl;
	for (size_t i = 0; i < sz; ++i){
		if (lower_range <= sarr[i] && sarr[i] <= upper_range){
		 	++(*nsz);
		}
	}
	
	return avg;
}

