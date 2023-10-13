#include <numeric>
#include <iostream>
#include <vector>
#include <array>

int main(void){
	std::vector<int> vec 		= {34, 6, 2, 6, 2, };
	std::array<int, 5> arr 	= {34, 6, 2, 6, 2, };
	int vec_sum, arr_sum;
	vec_sum = std::accumulate(vec.begin(), vec.end(), 0);
	arr_sum = std::accumulate(arr.begin(), arr.end(), 0);

	std::cout << "VEC SUM: " << vec_sum << std::endl << 
					"ARR SUM: " << arr_sum << std::endl;

	return 0;
}
