#include "4.hpp"
#include <iostream>
int* sum_cols(int** arr, size_t const r, size_t const c){
	int* ret = new int[c]; 
	for (size_t j = 0; j < c; ++j){
		for (size_t i = 0; i < r; ++i){
			ret[j] = arr[i][j];
		}
	}
	return ret;
}
void print_monodimensional_array(int* const a, size_t const sz){
	for (size_t i = 0; i < sz; ++i){
		std::cout << "A[" << i << "]: " << a[i] << std::endl;
	}
}
size_t max_index(int* const a, size_t const sz){
	size_t max = 0;
	for (size_t i = 0; i < sz; ++i){
		if (a[i] > a[max]) max = i;
	}
	return max;
}
