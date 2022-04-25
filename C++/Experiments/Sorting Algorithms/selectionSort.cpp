#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vec_int;

// Ascending
void selectionSortAsc(vec_int *numbers) {
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
}

// Descending
void selectionSortDsc(vec_int *numbers) {
	int rounds = (*numbers).size();
	int current_pos = 0;
	int temp;

	while(rounds--) {
		// Set maximum as the first element of vector
		vec_int::iterator it_max = (*numbers).begin() + current_pos;
		
		// Find maximum
		for(vec_int::iterator it = it_max; it < (*numbers).end(); it++) {
			if(*it < *it_max) {
				it_max = it;
			}
		}
		
		// Swapping...
		temp = (*numbers)[current_pos];
		(*numbers)[current_pos] = *it_max;
		*it_max = temp;

		current_pos++;
	}
}

// Ascending with visualization
void selectionSortAscVis(vec_int *numbers) {
	int rounds = (*numbers).size();
	int current_pos = 0;
	int temp;

	while(rounds--) {
		printf("\nGo to the next index >>>>>");
		// Set minimum as the first element of vector
		vec_int::iterator it_min = (*numbers).begin() + current_pos;
		
		// Find minimum
		for(vec_int::iterator it = it_min; it < (*numbers).end(); it++) {
			printf("\nComparing current minimum with current number (%d with %d)", *it_min, *it);
			if(*it < *it_min) {
				printf("\nCurrent number is smaller than current minimum");
				printf("\nCurrent minimum has been set from %d to %d", *it_min, *it);
				it_min = it;
			} else { printf("\nCurrent minimum doesn't changed"); }
		}
		
		// Swapping...
		*it_min != (*numbers)[current_pos]? 
					printf("\n...\nSwapping index %d to %d and index %d to %d", current_pos, *it_min, it_min - (*numbers).begin(),(*numbers)[current_pos])
					: printf("\n...\nNothing to swap");
		printf("\nBefore: ");
		for(int num: *numbers) { printf("%d ", num); }

		temp = (*numbers)[current_pos];
		(*numbers)[current_pos] = *it_min;
		*it_min = temp;
		
		printf("\nAfter : ");
		for(int num: *numbers) { printf("%d ", num); }
		printf("\n");
		current_pos++;
	}
	printf("\nSort completed!\nResult: ");
}

// Descending with visualization
void selectionSortDscVis(vec_int *numbers) {
	int rounds = (*numbers).size();
	int current_pos = 0;
	int temp;

	while(rounds--) {
		printf("\nGo to the next index >>>>>");
		// Set maximum as the first element of vector
		vec_int::iterator it_max = (*numbers).begin() + current_pos;
		
		// Find maximum
		for(vec_int::iterator it = it_max; it < (*numbers).end(); it++) {
			printf("\nComparing current maximum with current number (%d with %d)", *it_max, *it);
			if(*it > *it_max) {
				printf("\nCurrent number is bigger than current maximum");
				printf("\nCurrent minimum has been set from %d to %d", *it_max, *it);
				it_max = it;
			} else { printf("\nCurrent maximum doesn't changed"); }
		}
		
		// Swapping...
		*it_max != (*numbers)[current_pos]? 
					printf("\n...\nSwapping index %d to %d and index %d to %d", current_pos, *it_max, it_max - (*numbers).begin(),(*numbers)[current_pos])
					: printf("\n...\nNothing to swap");
		printf("\nBefore: ");
		for(int num: *numbers) { printf("%d ", num); }

		temp = (*numbers)[current_pos];
		(*numbers)[current_pos] = *it_max;
		*it_max = temp;
		
		printf("\nAfter : ");
		for(int num: *numbers) { printf("%d ", num); }
		printf("\n");
		current_pos++;
	}
	printf("\nSort completed!\nResult: ");
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

	std::cout << "\nASCENDING  | ";
	selectionSortAscVis(&numbers);
	for(int num: numbers) { printf("%d ", num);}

	std::cout << "\n\nDESCENDING | ";
	selectionSortDscVis(&numbers);
	for(int num: numbers) { printf("%d ", num);}


}
