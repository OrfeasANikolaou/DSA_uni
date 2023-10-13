#include <iostream>
#include "4.hpp"
int main(void){
	size_t constexpr N  = 5;
	size_t constexpr M  = 5;
	int* col = NULL;
	int** a = NULL;
	// malloc is better than new, I hate new
	a = new int*[N];
	for (size_t i = 0; i < N; ++i){
		a[i] = new int[M];
	}
/*	a = (int**)malloc(sizeof(int*) * N);
	for (size_t i = 0; i < N; ++i){
		a[i] = (int *)malloc(sizeof(int) * M);
	}
	*/
	srand(12345);
	for (size_t i = 0; i < N; ++i){
		for (size_t j = 0; j < M; ++j){
			a[i][j] = ( rand() % 1000) + 1;
		}
	}
	col = new int[M];	
	col = sum_cols(a, N, M);
	print_monodimensional_array(&col[0], M);
	std::cout << "Max col sum index: " << max_index(&col[0], M) << std::endl;	
}
