#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
std::ostream& operator<<(std::ostream& os, std::vector<int> const v);
int main(void){
	std::vector<int> vec;
	int val;
	do{
		std::cout << "Enter value: ";
		std::cin >> val;
		auto it= std::upper_bound(vec.begin(), vec.end(), val, std::greater<int>());
		vec.insert(it, val);
		std::cout << "-------NEW SORTED-------" << std::endl;
		std::cout << vec << std::endl;
	}while(1);


	return 0;
}
std::ostream& operator<<(std::ostream& os, std::vector<int> const v){
	
	for (auto vec : v)
		std::cout << vec << std::endl;	

	return os;
}
