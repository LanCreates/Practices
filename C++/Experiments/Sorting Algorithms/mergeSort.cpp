#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> vec_int;

vec_int mergeSortAsc(vec_int numbers) {
	if(numbers.size() == 1) {
		return numbers;
	} else {
		if(numbers.size() == 2) {
			if(numbers[0] > numbers[1]) {
				int temp = numbers[1];
				numbers[1] = numbers[0];
				numbers[0] = temp;
			} 
			return numbers;
		} else {
			int mid = numbers.size()/2;
			vec_int result {};
			vec_int half1, half2;

			half1.insert(half1.end(), numbers.begin(), numbers.begin() + mid);
			half2.insert(half2.end(), numbers.begin() + mid, numbers.end());

			// Recursion here
			half1 = mergeSortAsc(half1);
			half2 = mergeSortAsc(half2);

			vec_int::iterator ptr1 = half1.begin();
			vec_int::iterator ptr2 = half2.begin();

			int target_sz = half1.size() + half2.size();
			while(result.size() < target_sz) {
				if(ptr1 == half1.end()) { // Add all the way to the end
					result.insert(result.end(), ptr2, half2.end());
					break;
				} else if(ptr2 == half2.end()) {
					result.insert(result.end(), ptr1, half1.end());
					break;
				}

				// Compare
				if(*ptr1 <= *ptr2){
					result.push_back(*ptr1);
					ptr1++;
				} else if(*ptr1 > *ptr2) {
					result.push_back(*ptr2);
					ptr2++;
				}
			}
			return result;
		}
	}
}

vec_int mergeSortDsc(vec_int numbers) {
	if(numbers.size() == 1) {
		return numbers;
	} else {
		if(numbers.size() == 2) {
			if(numbers[0] < numbers[1]) {
				int temp = numbers[1];
				numbers[1] = numbers[0];
				numbers[0] = temp;
			} 
			return numbers;
		} else {
			int mid = numbers.size()/2;
			vec_int result {};
			vec_int half1, half2;

			half1.insert(half1.end(), numbers.begin(), numbers.begin() + mid);
			half2.insert(half2.end(), numbers.begin() + mid, numbers.end());
			
			// Recursion here
			half1 = mergeSortDsc(half1);
			half2 = mergeSortDsc(half2);

			vec_int::iterator ptr1 = half1.begin();
			vec_int::iterator ptr2 = half2.begin();

			int target_sz = half1.size() + half2.size();
			while(result.size() < target_sz) {
				if(ptr1 == half1.end()) { // Add all the way to the end
					result.insert(result.end(), ptr2, half2.end());
					break;
				} else if(ptr2 == half2.end()) {
					result.insert(result.end(), ptr1, half1.end());
					break;
				}

				// Compare
				if(*ptr1 >= *ptr2){
					result.push_back(*ptr1);
					ptr1++;
				} else if(*ptr1 < *ptr2) {
					result.push_back(*ptr2);
					ptr2++;
				}
			}
			return result;
		}
	}
}

vec_int mergeSortAscVis(vec_int numbers) {
	printf("\n\nNEW CALL===================================");
	if(numbers.size() == 1) {
		printf("\nOnly one element\nReturn {%d}", numbers[0]);
		printf("\n===Call complete!===\n");
		return numbers;
	} else {
		if(numbers.size() == 2) {
			printf("\n%d - %d", numbers[0], numbers[1]);
			if(numbers[0] > numbers[1]) {
				printf("\n%d is bigger than %d. Swap them", numbers[0], numbers[1]);
				int temp = numbers[1];
				numbers[1] = numbers[0];
				numbers[0] = temp;
			} else { printf("\nNothing to swap"); }
			printf("\nReturn {%d, %d}", numbers[0], numbers[1]);
			printf("\n===Call complete!===\n");
			return numbers;
		} else {
			int mid = numbers.size()/2;
			vec_int result {};
			vec_int half1, half2;
			
			printf("\nCurrently we have:\n");
			for(int n: numbers) {printf("%d ", n); }

			half1.insert(half1.end(), numbers.begin(), numbers.begin() + mid);
			half2.insert(half2.end(), numbers.begin() + mid, numbers.end());
			printf("\nSplit them into half! Current middle point: %d", mid);
			printf("\nFirst Half: ");
			for(int n: half1) {printf("%d ", n); }
			printf("\nSecond Half: ");
			for(int n: half2) {printf("%d ", n); }

			// Recursion here
			half1 = mergeSortAscVis(half1);
			half2 = mergeSortAscVis(half2);

			vec_int::iterator ptr1 = half1.begin();
			vec_int::iterator ptr2 = half2.begin();
			
			printf("\n\nNow that we have two vectors, let's arrange them into one");
			int target_sz = half1.size() + half2.size();
			int insertion_nu = 0;
			while(result.size() < target_sz) {
				printf("\nINSERTION %d =====================", insertion_nu);
				printf("\nVector1: %s", ptr1 == half1.end()? "-": "");
				for(vec_int::iterator it = ptr1; it != half1.end(); it++) {printf("%d ", *it); }
				printf("\nVector2: %s", ptr2 == half2.end()? "-": "");
				for(vec_int::iterator it = ptr2; it != half2.end(); it++) {printf("%d ", *it); }
				printf("\nResult: %s\n", result.size() == 0? "-": "");
				for(int m: result) {printf("%d ", m); }

				if(ptr1 == half1.end()) { // Add all the way to the end
					printf("\n\nNo more item in Vector 1 to be added");
					printf("\nAdd all remaining items in Vector 2\n");
					result.insert(result.end(), ptr2, half2.end());
					break;
				} else if(ptr2 == half2.end()) {
					printf("\n\nNo more item in Vector 2 to be added");
					printf("\nAdd all remaining items in Vector 1\n");
					result.insert(result.end(), ptr1, half1.end());
					break;
				}

				// Compare
				if(*ptr1 <= *ptr2){
					result.push_back(*ptr1);
					ptr1++;
				} else if(*ptr1 > *ptr2) {
					result.push_back(*ptr2);
					ptr2++;
				}
				insertion_nu++;
			}
			printf("\nReturn: {");
			for(int k: result) {printf("%d ", k); }
			printf("}");
			printf("\n===Call complete!===\n");
			return result;
		}
	}
}

vec_int mergeSortDscVis(vec_int numbers) {
	printf("\n\nNEW CALL===================================");
	if(numbers.size() == 1) {
		printf("\nOnly one element\nReturn {%d}", numbers[0]);
		printf("\n===Call complete!===\n");
		return numbers;
	} else {
		if(numbers.size() == 2) {
			printf("\n%d - %d", numbers[0], numbers[1]);
			if(numbers[0] < numbers[1]) {
				printf("\n%d is smaller than %d. Swap them", numbers[0], numbers[1]);
				int temp = numbers[1];
				numbers[1] = numbers[0];
				numbers[0] = temp;
			} else { printf("\nNothing to swap"); }
			printf("\nReturn {%d, %d}", numbers[0], numbers[1]);
			printf("\n===Call complete!===\n");
			return numbers;
		} else {
			int mid = numbers.size()/2;
			vec_int result {};
			vec_int half1, half2;
			
			printf("\nCurrently we have:\n");
			for(int n: numbers) {printf("%d ", n); }

			half1.insert(half1.end(), numbers.begin(), numbers.begin() + mid);
			half2.insert(half2.end(), numbers.begin() + mid, numbers.end());
			printf("\nSplit them into half! Current middle point: %d", mid);
			printf("\nFirst Half: ");
			for(int n: half1) {printf("%d ", n); }
			printf("\nSecond Half: ");
			for(int n: half2) {printf("%d ", n); }

			// Recursion here
			half1 = mergeSortDscVis(half1);
			half2 = mergeSortDscVis(half2);

			vec_int::iterator ptr1 = half1.begin();
			vec_int::iterator ptr2 = half2.begin();
			
			printf("\n\nNow that we have two vectors, let's arrange them into one");
			int target_sz = half1.size() + half2.size();
			int insertion_nu = 0;
			while(result.size() < target_sz) {
				printf("\nINSERTION %d =====================", insertion_nu);
				printf("\nVector1: %s", ptr1 == half1.end()? "-": "");
				for(vec_int::iterator it = ptr1; it != half1.end(); it++) {printf("%d ", *it); }
				printf("\nVector2: %s", ptr2 == half2.end()? "-": "");
				for(vec_int::iterator it = ptr2; it != half2.end(); it++) {printf("%d ", *it); }
				printf("\nResult: %s\n", result.size() == 0? "-": "");
				for(int m: result) {printf("%d ", m); }

				if(ptr1 == half1.end()) { // Add all the way to the end
					printf("\n\nNo more item in Vector 1 to be added");
					printf("\nAdd all remaining items in Vector 2\n");
					result.insert(result.end(), ptr2, half2.end());
					break;
				} else if(ptr2 == half2.end()) {
					printf("\n\nNo more item in Vector 2 to be added");
					printf("\nAdd all remaining items in Vector 1\n");
					result.insert(result.end(), ptr1, half1.end());
					break;
				}

				// Compare
				if(*ptr1 >= *ptr2){
					result.push_back(*ptr1);
					ptr1++;
				} else if(*ptr1 < *ptr2) {
					result.push_back(*ptr2);
					ptr2++;
				}
				insertion_nu++;
			}
			printf("\nReturn: {");
			for(int k: result) {printf("%d ", k); }
			printf("}");
			printf("\n===Call complete!===\n");
			return result;
		}
	}
}

int main() {
	vec_int numbers {};
	std::string inp = "";

	printf("Enter numbers (x to quit)\n");
	std::cin >> inp;
	while(inp != "x") {
		numbers.push_back(std::stoi(inp));
		std::cin >> inp;
	}

	printf("\n\nASCENDING>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	for(int m: mergeSortAscVis(numbers)) {
		printf("%d ", m);
	}

	printf("\n\nDESCENDING>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	for(int m: mergeSortDscVis(numbers)) {
		printf("%d ", m);
	}
}
