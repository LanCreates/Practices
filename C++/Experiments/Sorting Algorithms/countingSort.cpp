#include <iostream>
#include <map>
#include <vector>
#include <string>

typedef std::map<int, int> map_int;
typedef std::vector<int> vec_int;

void countSort(vec_int *numbers, short code) {
	map_int groups {};

	for(int num: *numbers) {
		(groups[num])++;
	}
	
	*numbers = {};
	for(std::pair<int, int> num: groups) {
		while(num.second--) {
			(*numbers).push_back(num.first);
		}
	}
	
	if(code % 2) {  // Odd for ascending
		for(int num: *numbers) { std::cout << num << " "; }
	} else {		// Even for descending
		for(vec_int::iterator it = (*numbers).end() - 1; it >= (*numbers).begin(); it--) {
			std::cout << (*it) << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	vec_int numbers {};
	std::string message = "Insert a number! (x to end)", inp = "";
	std::cout << message << std::endl;
	std::cin >> inp;
	while(inp != "x") {
		numbers.push_back(std::stoi(inp));
		std::cout << message << std::endl;
		std::cin >> inp;
	}
	std::cout << "\nASCENDING  | ";
	countSort(&numbers, 1);
	std::cout << "\nDESCENDING | ";
	countSort(&numbers, 0);
}
