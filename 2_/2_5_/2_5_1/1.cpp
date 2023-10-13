#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

int main(void){
	std::mt19937 mt(1821);
	std::uniform_int_distribution<int> random(1, 10000);
 	size_t constexpr size_A = 1000;
	size_t constexpr size_B = 100000;
	int A[size_A];
	int B[size_B];
	size_t cnt = 0;
	for (size_t i = 0; i < size_A; ++i){
		A[i] = random(mt);
	}
	for (size_t i = 0; i < size_B; ++i){
		B[i] = random(mt);
	}
	std::sort(A, A + size_A);
	for (size_t i = 0; i < size_B; ++i){
		if(std::binary_search(A, A + size_A , B[i])) ++cnt;
	}
	std::cout << "Count: " << cnt << std::endl;
	return 0;
}
