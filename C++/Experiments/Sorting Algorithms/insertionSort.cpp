#include <iostream>
#include <string>
#include <vector>

typedef std::vector<int> vec_int;

// Ascending
void insertionSortAsc(vec_int *numbers) {
	int nu;
	for(vec_int::iterator ori = (*numbers).begin() + 1; ori < (*numbers).end(); ori++) {
		auto tar = ori;
		nu = *ori;
		
		(*numbers).erase(ori);
		while(nu < *(tar - 1) && tar > (*numbers).begin()) {
			tar--;
		}
		(*numbers).insert(tar, nu);
	}
}

// Ascending with steps
void insertionSortAscVis(vec_int *numbers) {
	int nu;
	for(vec_int::iterator ori = (*numbers).begin() + 1; ori < (*numbers).end(); ori++) {
		printf("\nCurrent inspection: index %d\n", ori - (*numbers).begin());
		for(int num: *numbers) { printf("%d ", num); }
		printf("\n");

		auto tar = ori;
		nu = *ori;
		
		(*numbers).erase(ori);
		while(nu < *(tar - 1) && tar > (*numbers).begin()) {
			printf("%d is smaller than %d. Current target index is %d\n", 
					nu, *(tar - 1), tar - (*numbers).begin() - 1);
			tar--;
		}
		
		(*numbers).insert(tar, nu);
		ori != tar? printf("Move %d from index %d to %d\n\n", nu, ori - (*numbers).begin(), tar - (*numbers).begin())
					:printf("Keep the position of %d\n\n", nu);
	}
	std::cout << "\nSort complete!" << std::endl;
}

// Descending
void insertionSortDsc(vec_int *numbers) {
	int nu;
	for(vec_int::iterator ori = (*numbers).begin() + 1; ori < (*numbers).end(); ori++) {
		auto tar = ori;
		nu = *ori;
		
		(*numbers).erase(ori);
		while(nu > *(tar - 1) && tar > (*numbers).begin()) {
			tar--;
		}
		(*numbers).insert(tar, nu);
	}
}

// Ascending with steps
void insertionSortDscVis(vec_int *numbers) {
	int nu;
	for(vec_int::iterator ori = (*numbers).begin() + 1; ori < (*numbers).end(); ori++) {
		printf("\nCurrent inspection: index %d\n", ori - (*numbers).begin());
		for(int num: *numbers) { printf("%d ", num); }
		printf("\n");

		auto tar = ori;
		nu = *ori;
		
		(*numbers).erase(ori);
		while(nu > *(tar - 1) && tar > (*numbers).begin()) {
			printf("%d is bigger than %d. Current target index is %d\n", 
					nu, *(tar - 1), tar - (*numbers).begin() - 1);
			tar--;
		}
		
		(*numbers).insert(tar, nu);
		ori != tar? printf("Move %d from index %d to %d\n\n", nu, ori - (*numbers).begin(), tar - (*numbers).begin())
					:printf("Keep the position of %d\n\n", nu);
	}
	std::cout << "\nSort complete!" << std::endl;
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

	printf("\nASCENDING  |\n");
	insertionSortAscVis(&numbers);
	for(int num: numbers) {
		printf("%d ", num);
	}
	printf("\n");

	printf("\nDESCENDING |\n");
	insertionSortDscVis(&numbers);
	for(int num: numbers) {
		printf("%d ", num);
	}
	printf("\n");
}
