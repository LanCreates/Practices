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
void countSort(vec_int *numbers) {
	map_int groups {};

	for(int num: *numbers) {
		(groups[num])++;
	}
	
	*numbers = {};
	for(std::pair<int, int> num: groups) {
		(*numbers).insert((*numbers).end(), num.second, num.first); 
	}
}

// Using unordered map
void realCountSortAsc(vec_int *numbers) {
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
}

void realCountSortDsc(vec_int *numbers) {
	umap_int groups {};
	set_int inserted_keys {};
	vec_int keys {};

	for(int num: *numbers) {
		if(inserted_keys.find(num) == inserted_keys.end()) {
			keys.push_back(num);

			// Sort immediately by the time they entered 
			// Visualization disabled here as it's an other topic
			int temp = 0;
			vec_int::iterator it1 = keys.end() - 1;
			vec_int::iterator it2 = keys.end() - 2;
			while((*it1 > *it2) && (it2 >= keys.begin())) {
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
}

void realCountSortAscVis(vec_int *numbers) {
	umap_int groups {};
	set_int inserted_keys {};
	vec_int keys {};

	for(int num: *numbers) {
		if(inserted_keys.find(num) == inserted_keys.end()) {
			keys.push_back(num);

			// Sort immediately by the time they entered 
			// Visualization disabled here as it's an other topic
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

		printf("\n\n%d found. Current data: ", num);
		for(std::pair<int, int> group: groups) {
			group.first != num? printf("\n%d : %dx", group.first, group.second)
								: printf("\n%d : %dx (+1)", group.first, group.second);
		}
	}

	// Insert the sorted things
	*numbers = {};
	for(int num: keys) { 
		(*numbers).insert((*numbers).end(), groups[num], num); 
	}
	printf("\nSort complete!\n");
}

void realCountSortDscVis(vec_int *numbers) {
	umap_int groups {};
	set_int inserted_keys {};
	vec_int keys {};

	for(int num: *numbers) {
		if(inserted_keys.find(num) == inserted_keys.end()) {
			keys.push_back(num);

			// Sort immediately by the time they entered 
			// Visualization disabled here as it's an other topic
			int temp = 0;
			vec_int::iterator it1 = keys.end() - 1;
			vec_int::iterator it2 = keys.end() - 2;
			while((*it1 > *it2) && (it2 >= keys.begin())) {
				temp = *it1;
				*it1 = *it2;
				*it2 = temp;
				it1--;
				it2--;
			}
		}
		inserted_keys.insert(num);
		(groups[num])++;

		printf("\n\n%d found. Current data: ", num);
		for(std::pair<int, int> group: groups) {
			group.first != num? printf("\n%d : %dx", group.first, group.second)
								: printf("\n%d : %dx (+1)", group.first, group.second);
		}
	}

	// Insert the sorted things
	*numbers = {};
	for(int num: keys) { 
		(*numbers).insert((*numbers).end(), groups[num], num); 
	}
	printf("\nSort complete!\n");
}

int main() {
	vec_int numbers {};
	std::string inp;

	printf("Insert a number! (x to stop)");
	std::cin >> inp;

	while(inp != "x") {
		numbers.push_back(std::stoi(inp));
		std::cin >> inp;
	}

	std::cout << "\n\nASCENDING  | ";
	realCountSortAscVis(&numbers);
	for(int num: numbers) {printf("%d ", num); }
	
	std::cout << "\n\nDESCENDING | ";
	realCountSortDscVis(&numbers);
	for(int num: numbers) {printf("%d ", num); }
}
