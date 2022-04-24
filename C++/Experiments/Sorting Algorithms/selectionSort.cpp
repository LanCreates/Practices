#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vec_int;

void selectionSort(vec_int *numbers, short code) {
	int rounds = (*numbers).size();
	int current_pos = 0;
	int temp;

	while(rounds--) {
		// Set minimum as the first element of vector
		vec_int::iterator it_min = (*numbers).begin() + current_pos;
		
		// Find minimum
		for(vec_int::iterator it = it_min; it < (*numbers).end(); it++) {
			if(*it < *it_min) {
				it_min = it;
			}
		}
		
		// Swapping...
		temp = (*numbers)[current_pos];
		(*numbers)[current_pos] = *it_min;
		*it_min = temp;

		current_pos++;
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

	std::cout << "\nASCENDING  | ";
	selectionSort(&numbers, 1);
	std::cout << "DESCENDING | ";
	selectionSort(&numbers, 0);
}
