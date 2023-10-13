#include <iostream>
#include <fstream>
#include <sstream>
// Γραψτε 10.000 τυχαριεσ ακεραιες τιμες στο διαστημα [1, 10.000] στο αρχειο data_int_10000.txt
// χρησιμοποιωντας τισ συναρτησεις rand και srand και seed την τιμη 1729. Διαβαστε τισ τιμες απο
// το αρχειο. Εντοπιστε τη μεγαλυτερη τιμη στα δεδομενα. Ποιεσ ειναι οι τιμεσ που εμφανιζονται
// τισ περισσοτερες φορες στα δεδομενα;
using std::fstream;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::cerr;
using std::getline;
using std::stringstream;
	enum max_indexes{ LARGEST, MOST_COMMON, N_MOST_COMMON };
int main(void){
	srand(1729);
	fstream file;
	string buf;
	size_t index = 0;
	size_t* cnt_nums = NULL;
	size_t num[10000];
	size_t max[3] ={ 0 };
	file.open("data_int_10000.txt", ios::out);
	if (!file.is_open()){
		cerr << "Could not create or access file." << endl;
		exit(1);
	}

	//add random numbers
	for (size_t i = 0; i < 10000; ++i){
		file << ((rand() % 10000) + 1) << endl;
	}
	file.close();
	file.open("data_int_10000.txt", ios::in);
	if (!file.is_open()){
		cerr << "Could not access file." << endl;
		exit(1);
	}
	// find largest
	while (getline(file, buf)){
		stringstream ss(buf); // Converts string to stream???? I think
		ss >> num[index];
		if (num[index] > max[LARGEST]) max[LARGEST] = num[index];
		++index;
	}
	// count how many times each number appears
	cnt_nums = new size_t[max[LARGEST] + 1];
	for (size_t i = 0; i < max[LARGEST] + 1; ++i){
		cnt_nums[i] = 0;
	}
	for (size_t i = 0; i < max[LARGEST] + 1; ++i){
		++cnt_nums[num[i]];
	}
	// get most common
	for (size_t i = 0; i < max[LARGEST] + 1; ++i){
		if (cnt_nums[i] > max[N_MOST_COMMON]){
		 	max[N_MOST_COMMON] = cnt_nums[i];
			max[MOST_COMMON] = i;
		}
	}
	cout << "Largest random number: " << max[LARGEST] << endl;
	cout << "Most common random number: " << max[MOST_COMMON] << endl <<
					"Number of times that the most common has appeared: " << max[N_MOST_COMMON] << endl;


	return 0;
}
