#include "1.hpp"
#include <iostream>
#include <ostream>
int main(void){
	size_t constexpr N = 100;
	srand(12345);
	int arr[N];
	size_t new_arr_sz = 0;
	double avg = 0;
	for (size_t i = 0; i < N; ++i)
		arr[i] = ( rand() % 100 ) + 1;
	for (size_t i = 0; i < N; ++i)
		std::cout << arr[i] << std::endl;
	avg = fun(arr, 100, &new_arr_sz); 
	std::cout << "Avg: " << avg << std::endl <<
							 "cnt: " << new_arr_sz << std::endl;
	return 0;
}
