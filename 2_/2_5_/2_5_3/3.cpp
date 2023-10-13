#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
int main(void){
	std::vector<std::string> names = {"name_3", "name_1", "name_2", };
	sort(names.begin(), names.end());
	do {
		std::cout << "PERMUTATION" << std::endl;
		for (std::string s : names){
			std::cout << s << std::endl;
		}
	}
	while(std::next_permutation(names.begin(), names.end()));
		

	return 0;
}
