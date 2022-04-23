#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <string>

typedef std::map<int,int> map_int;
typedef std::unordered_map<int,int> umap_int;
typedef std::vector<int> vec_int;
typedef std::set<int> set_int;

// A bit cheating, but still a count sort
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

// Using unordered map
void realCountSort(vec_int *numbers, short code) {
	umap_int groups {};
	set_int inserted_keys {};
	vec_int keys {};

	for(int num: *numbers) {
		if(inserted_keys.find(num) == inserted_keys.end()) {
			keys.push_back(num);

			// Sort immediately by the time they entered
			int temp = 0;
			vec_int::iterator it1 = keys.end() - 1;
			vec_int::iterator it2 = keys.end() - 2;
			while((*it1 < *it2) && (it2 >= keys.begin())) {
				temp = *it1;
				*it1 = *it2;
				*it2 = temp;
				it1--;
				it2--;
			}
		}
		inserted_keys.insert(num);
		(groups[num])++;
	}
	
	// Insert the sorted things
	*numbers = {};
	for(int num: keys) { 
		(*numbers).insert((*numbers).end(), groups[num], num); 
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
	realCountSort(&numbers, 1);
	std::cout << "\nDESCENDING | ";
	realCountSort(&numbers, 0);
}
