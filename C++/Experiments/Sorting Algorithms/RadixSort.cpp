#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>

void radixSortPositive(std::vector<int> *numbers) {
	long long int sz = (*numbers).size();
	long long int mult = 1;
	std::map<int, std::vector<int>> groups {
		{1, {}}, {2, {}},
		{3, {}}, {4, {}},
		{5, {}}, {6, {}},
		{7, {}}, {8, {}},
		{9, {}}, {0, {}}
	};

	bool arranged = false;
	while(!arranged) {
		// Insert numbers into groups
		for(int num: *numbers) {
			int currentDig = (num % (mult*10)) / mult;
			groups[std::abs(currentDig)].push_back(num);
		}
		
		// Periodical Update
		arranged = groups[0].size() == sz;
		mult *= 10;

		// Insert things
		*numbers = {};
		for(int i= 0; i < 10; i++) {
			for(int num: groups[i]) { (*numbers).push_back(num); }
			groups[i] = {};
		}
	}
}

void radixSortNegative(std::vector<int> *numbers) {
	long long int sz = (*numbers).size();
	long long int mult = 1;
	std::map<int, std::vector<int>> groups {
		{1, {}}, {2, {}},
		{3, {}}, {4, {}},
		{5, {}}, {6, {}},
		{7, {}}, {8, {}},
		{9, {}}, {0, {}}
	};

	bool arranged = false;
	while(!arranged) {
		// Insert numbers into groups
		for(int num: *numbers) {
			int currentDig = (num % (mult*10)) / mult;
			groups[std::abs(currentDig)].push_back(num);
		}
		
		// Periodical Update
		arranged = groups[0].size() == sz;
		mult *= 10;

		// Insert things
		*numbers = {};
		for(int i= 10; i >= 0; i--) {
			for(int num: groups[i]) { (*numbers).push_back(num); }
			groups[i] = {};
		}
	}
}

void radixSortMixed(std::vector<int> *numbers, short code) {
	std::vector<int> positives {};
	std::vector<int> negatives {};

	for(int num: *numbers) {
		num < 0? negatives.push_back(num): positives.push_back(num);
	}

	*numbers = {};
	if(code % 2) { // Odd for ascending
		radixSortPositive(&positives);
		radixSortNegative(&negatives);
		for(int num: negatives) { (*numbers).push_back(num); }
		for(int num: positives) { (*numbers).push_back(num); }
	} else { // Even for descending
		radixSortPositive(&negatives);
		radixSortNegative(&positives);
		for(int num: positives) { (*numbers).push_back(num); }
		for(int num: negatives) { (*numbers).push_back(num); }
	}
}

void printVector(std::vector<int> vect) {
	for(int item: vect) { std::cout << item << " "; };
}

void printSorted(std::vector<int> *numbers) {
	std::cout << "Before: ";
	printVector(*numbers);

	std::cout << "\n============== ASCENDING =================\n";
	radixSortMixed(numbers, 1);
	printVector(*numbers);

	std::cout << "\n============== DESCENDING =================\n";
	radixSortMixed(numbers, 0);
	printVector(*numbers);
	std::cout << "\n";
}

int main() {
	std::vector<int> sample1 {-1, -4, -2, -3, -2, -5, -1, -6, -4, -9, -8};
	std::vector<int> sample2 {682, 631, 151, 222, 519, 870, 360, 738, 281, 341};
	std::vector<int> sample3 {-1, 4, 2, 3, -2, 5, 1, -6, -4, 9, 8};
	std::vector<int> numbers {};

	std::string response = "";
	std::cout << "Enter your decimal number (Enter x to stop) ";
	std::cin >> response;

	while(response != "x") {
		numbers.push_back(std::stoi(response));
		std::cout << "Enter your decimal number (Enter x to stop) ";
		std::cin >> response;
	}
	printSorted(&numbers);
}
