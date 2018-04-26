#include "PA8.h"

/*
Function: my_str_n_cat
Date Created: 4/18/2018
Date Last Modified: 4/18/2018
Description: Adds 'n' number of characters from source array to destination character array. Stops earlier if it
encounters a null character.
Input Parameters: char* destination, const char* source, int size
Returns: char* result
*/

char* my_str_n_cat(char* destination, const char* source, int size) {

	char* result = destination;

	while (*destination != '\0') {

		destination++;

	}

	while (size > 0 && *source != '\0') {

		*destination++ = *source++;
		size--;

	}

	return result;

}

/*
Function: binary_search
Date Created: 4/18/2018
Date Last Modified: 4/18/2018
Description: Searches for an integer in a sorted integer array using the binary search algorithm. Returns index
of the item if it is found, otherwise it returns -1.
Input Parameters: int values, int target, int size
Returns: int targetindex
*/

int binary_search(int values[], int target, int size) {

	int targetindex = -1, left = 1, right = size, mid = 0;
	bool found = false;

	while (found == false && left <= right) {

		mid = (right - left) / 2 + 1;

		if (target == values[mid]) {
			found = true;
			targetindex = mid;
		}
		else if (target < values[mid]) {
			right = mid - 1;
		}
		else if (target > values[mid]) {
			left = mid + 1;
		}

	}

	return targetindex;

}

/*
Function: bubble_sort()
Date Created: 4/18/2018
Date Last Modified: 4/18/2018
Description: Sorts strings by in alphabetical order.
Input Parameters: char* strings_ptr, int string_number
Returns: none
*/

void bubble_sort(char* strings_ptr[], int string_number) {

	int min = 0, max = string_number, i = 1;
	char* temp = NULL;

	while (max > 1) {

		min = 1;

		while (min < max) {

			if (*strings_ptr[min] < *strings_ptr[min - 1]) {

				temp = strings_ptr[min - 1];
				strings_ptr[min - 1] = strings_ptr[min];
				strings_ptr[min] = temp;

			}
			else if (*strings_ptr[min] == *strings_ptr[min - 1]) {

				while (*(strings_ptr[min] + i) == *(strings_ptr[min - 1] + i)) {

					i++;

				}

				if (*(strings_ptr[min] + i) < *(strings_ptr[min - 1] + i)) {

					temp = strings_ptr[min - 1];
					strings_ptr[min - 1] = strings_ptr[min];
					strings_ptr[min] = temp;

				}

			}

			min++;

		}

		max--;

	}

}

/*
Function: is_palindrome()
Date Created: 4/22/2018
Date Last Modified: 4/22/2018
Description: Identify if a string is a palindrome or not
Input Parameters: char* strings_ptr[], int string_length
Returns: int
*/

int is_palindrome(char* string, int string_length, int index) {

	if (string[index] == ' ' || string[index] == '\0') {

		index++;

	}

	if (string[string_length - 1] == ' ' || string[string_length - 1] == '\0') {
		
		while (string[string_length - 1] == '\0' || string[string_length - 1] == ' ') {

			string_length--;

		}

	}

	if (string_length == 1) {
		
		return 1;

	}
	else if (string[index] == string[string_length - 1]) {
		
		index++;
		string_length--;
		return is_palindrome(string, string_length, index);

	}
	else {

		return 0;

	}

}

/*
Function: sum_prime()
Date Created: 4/22/2018
Date Last Modified: 4/22/2018
Description: Sum all the prime numbers from 2 to n
Input Parameters: unsigned int n
Returns: int
*/

int sum_primes(unsigned int n) {

	int num = 2, rem = n % num;

	if (n <= 1) {

		return 0;

	}

	while (num != n && rem != 0) {

		rem = n % num;
		num++;

	}

	if (n > 1 && num == n) {

		return n + sum_primes(n - 1);

	}
	else if (n > 1 && num != n) {

		return 0 + sum_primes(n - 1);

	}
	else {

		return 0;

	}

}

/*
Function: maximum_occurences()
Date Created: 4/23/2018
Date Last Modified: 4/25/2018
Description: Find the max occuring character in a string
Input Parameters: char* string, Occurences occurences[OCCURENCES_LENGTH], int* i, char* c
Returns: none
*/

void maximum_occurences(char* string, Occurences occurences[OCCURENCES_LENGTH], int* i, char* c) {

	int length = strlen(string);
	double max = 0;
	int valid = 0;

	while (isalnum(string[valid]) || string[valid] == ' ') valid++;

	if (valid == length) {

		for (int count = 0; count < length; count++) { // counter for string array

			for (int index = 0; index < OCCURENCES_LENGTH; index++) { // counter for occurences array

				if (index == (int)string[count]) {

					// *i = occurences[index]->num_occurences;
					occurences[index].num_occurences++;
					occurences[index].frequency = ((float) occurences[index].num_occurences) / (float) length;
					break;

				}

			}

		}

		for (int counter = 0; counter < OCCURENCES_LENGTH; counter++) {

			if (occurences[counter].frequency > max) {

				max = occurences[counter].frequency;
				*i = counter;

			}

		}

		*c = *i;
		int index = *i;
		*i = occurences[index].num_occurences;

		printf_s("The character %c has the most occurences in the string, occuring a total of %d times\n", *c, *i);

	}
	else {

		printf_s("The string is not alphanumeric so the function cannot be executed.\n");

	}

}

/*
Function: max_consecutive_integers()
Date Created: 4/25/2018
Date Last Modified: 4/25/2018
Description: Find the max occuring consecutive integer in a 2D array
Input Parameters: signed int arr[ROWS][COLS], int rows, int col
Output Parameters: int** address_ptr, int* num_ptr
Returns: none
*/

void max_consecutive_integers(signed int arr[][COLS], int rows, int col, int** address_ptr, int* num_ptr) {

	int counter = 0, consec_int = 0, index = 0, prev_consec_int = 0, checking_index = 0, j = 0, j_col = 0, rep_num = 0;

	Consec_occurences num_consec[10] = { { 0, NULL, 0 } };

	for (int i = 0; i < rows - 1; i++) {

		if (j == col) {
			j_col = 1;
			if (arr[i - 1][j] == arr[i][0]) {
				num_consec[index - 1].num_occurences++;
			}
		}

		for (j = 0; j < col - 1; j++) {

			if (j_col == 1) {
				j++;
			}

			if (j_col == 1 && arr[i][j] == arr[i][j - 1]) {
				index--;
				num_consec[index].num_occurences++;
			}
			
			if (arr[i][j] == arr[i][j + 1]) {

				num_consec[index].first_address = &arr[i][j];
				checking_index = j;

				while (arr[i][checking_index] == arr[i][checking_index + 1]) { // used the checking_index variable so while loop would break since I couldn't increment the loop counters

					checking_index++;
					counter++;
					consec_int = arr[i][j];

				}

				num_consec[index].number = consec_int;
				num_consec[index].num_occurences += counter;
				counter = 0;
				index++;

			}

			j_col = 0;

		}

	}

	int max_occurences = 0;

	for (int i = 0; i < 10; i++) {

		if (num_consec[i].num_occurences > max_occurences) {
			max_occurences = num_consec[i].num_occurences;
			address_ptr = &num_consec[i].first_address;
			num_ptr = &num_consec[i].num_occurences;
			rep_num = num_consec[i].number;
		}

	}

	printf_s("The most recurring consecutive number is %d\n", rep_num);
	printf_s("It has been repeated %d times and the address is %p\n", *num_ptr, (void *) *address_ptr);

}