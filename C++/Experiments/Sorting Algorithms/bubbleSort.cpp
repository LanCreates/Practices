#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vec_int;

// Ascending
void bubbleSortAsc(vec_int *numbers) {
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
}

// Descending
void bubbleSortDsc(vec_int *numbers) {
	bool sorted = false;
	int temp = 0;

	if((*numbers).size() > 1) {
		while(!sorted) {
			sorted = true;
			for(vec_int::iterator it1 = (*numbers).begin(); it1 < (*numbers).end() - 1; it1++) {
				auto it2 = it1 + 1;
				if(*it1 < *it2) {
					temp = *it1;
					*it1 = *it2;
					*it2 = temp;
					sorted = false;
				}
			}
		}
	}
}

// Ascending with visualization
void bubbleSortAscVis(vec_int *numbers) {
	bool sorted = false;
	int temp = 0;

	if((*numbers).size() > 1) {
		while(!sorted) {
			sorted = true;
			for(vec_int::iterator it1 = (*numbers).begin(); it1 < (*numbers).end() - 1; it1++) {
				auto it2 = it1 + 1;

				printf("\nNow inspecting: Index %d with %d (%d with %d)",
						it1 - (*numbers).begin(), it2 - (*numbers).begin(), *it1, *it2);
				if(*it1 > *it2) {
					printf("\nBefore: ");
					for(int num: *numbers) { printf("%d ", num); }

					temp = *it1;
					*it1 = *it2;
					*it2 = temp;

					printf("\nAfter: ");
					for(int num: *numbers) { printf("%d ", num); }
					printf("\n%d is smaller than %d", *it1, *it2);
					printf("\nSwap %d to index %d and %d to index %d\n",
							*it1, it1 - (*numbers).begin(), *it2, it2 - (*numbers).begin());
					sorted = false;
				} else { printf("\nNothing to swap\n");}
			}
			sorted? printf("\nRecheck for something to be sorted...\n"): printf("");
		}
		printf("Sort complete!\nResult: ");
	}
}

// Descending with visualization
void bubbleSortDscVis(vec_int *numbers) {
	bool sorted = false;
	int temp = 0;

	if((*numbers).size() > 1) {
		while(!sorted) {
			sorted = true;
			for(vec_int::iterator it1 = (*numbers).begin(); it1 < (*numbers).end() - 1; it1++) {
				auto it2 = it1 + 1;

				printf("\nNow inspecting: Index %d with %d (%d with %d)",
						it1 - (*numbers).begin(), it2 - (*numbers).begin(), *it1, *it2);
				if(*it1 < *it2) {
					printf("\nBefore: ");
					for(int num: *numbers) { printf("%d ", num); }

					temp = *it1;
					*it1 = *it2;
					*it2 = temp;

					printf("\nAfter: ");
					for(int num: *numbers) { printf("%d ", num); }
					printf("\n%d is bigger than %d", *it1, *it2);
					printf("\nSwap %d to index %d and %d to index %d\n",
							*it1, it1 - (*numbers).begin(), *it2, it2 - (*numbers).begin());
					sorted = false;
				} else { printf("\nNothing to swap\n");}
			}
			sorted? printf("\nRecheck for something to be sorted...\n"): printf("");
		}
		printf("Sort complete!\nResult: ");
	}
}

int main() {
	vec_int numbers {};
	std::string inp = "";
	printf("Insert numbers (x to end) ");
	std::cin >> inp;

	while(inp != "x") {
		numbers.push_back(std::stoi(inp));
		std::cin >> inp;
	}

	printf("\n\nASCENDING  |=====");
	bubbleSortAscVis(&numbers);
	for(int num: numbers) { std::cout << num << " "; }

	printf("\n\nDESCENDING  |=====");
	bubbleSortDscVis(&numbers);
	for(int num: numbers) { std::cout << num << " "; }
}
