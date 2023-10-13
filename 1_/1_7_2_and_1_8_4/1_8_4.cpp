#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
using std::string;
using std::fstream;
typedef struct{
	string name;
	int grade;
}student;

int main(void){
	size_t constexpr N = 10;
	size_t index = 0;
	student st[N];
	fstream file;
	string buffer;
	double normal_avg = 0.0;
	double good_avg = 0.0;
	size_t cnt = 0;
	file.open("data_student_struct10.txt", std::ios::in);
	if(!file.is_open()){
		std::cerr << "could not open file.\n";
		exit(1);
	}
	while(getline(file, buffer) && index < N){
	std::stringstream ss(buffer);
	ss >> st[index].name;
	ss >> st[index].grade;
	++index;
	}
	for ( auto s : st ){
		normal_avg += s.grade;
	}
	normal_avg /= 10;
	std::cout << "Average for all students: " << normal_avg / 10 << std::endl;
	for ( auto s : st){
		if (s.grade > normal_avg){
			std::cout << s.name << " had a better grade than average, with a " << s.grade / 10.0 << std::endl;
			good_avg += s.grade;
			++cnt;
		}
	}
	good_avg /= cnt;
	std::cout << "Average for good students: " << good_avg / 10 << std::endl;
	return 0;
}
