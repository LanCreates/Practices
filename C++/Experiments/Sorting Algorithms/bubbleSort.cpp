#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vec_int;

void bubbleSort(vec_int *numbers, short code) {
	bool sorted = false;
	int temp = 0;

	if((*numbers).size() > 1) {
		while(!sorted) {
			sorted = true;
			for(vec_int::iterator it1 = (*numbers).begin(); it1 < (*numbers).end() - 1; it1++) {
				auto it2 = it1 + 1;
				if(*it1 > *it2) {
					temp = *it1;
					*it1 = *it2;
					*it2 = temp;
					sorted = false;
				}
			}
		}
	}
	
	// Print the whole thing
	if(code % 2) { // Odd for ascending
		for(int num: *numbers) { std::cout << num << " "; }
	} else {	// Even for descending
		for(vec_int::iterator it = (*numbers).end() - 1; it >= (*numbers).begin(); it--) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	vec_int numbers {};
	std::string inp = "";
	std::cout << "Insert numbers (x to end) ";
	std::cin >> inp;

	while(inp != "x") {
		numbers.push_back(std::stoi(inp));
		std::cout << "Insert numbers (x to end) ";
		std::cin >> inp;
	}

	std::cout << "ASCENDING  | ";
	bubbleSort(&numbers, 1);
	std::cout << "DESCENDING | ";
	bubbleSort(&numbers, 0);
}
