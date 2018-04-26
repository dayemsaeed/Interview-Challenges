#include "PA8.h"

int main() {

	printf_s("Welcome to PA8!\n");
	system("pause");
	system("cls");

	printf_s("Running String Concatenation Program\n");
	system("pause");
	system("cls");

	// Test for String concatenation

	char destination[100] = "Hello";
	char* source = " World!";

	my_str_n_cat(destination, source, 5);
	printf_s(destination);
	printf_s("\n");
	
	// End String Concatenation test

	system("pause");
	system("cls");
	printf_s("Running Binary Search Program\n");
	system("pause");
	system("cls");

	// Test for binary search

	int sorted_array[7] = { 0, 1, 5, 8, 10, 20, 50 };

	int found_item = binary_search(sorted_array, 1, 7);

	printf_s("%d\n", found_item);

	// End Binary Search test

	system("pause");
	system("cls");
	printf_s("Running Bubble Sort Program\n");
	system("pause");
	system("cls");

	// Test for Bubble sort 

	char* str_ptr[5] = {
	
		"hello",
		"world",
		"he",
		"swordfish",
		"pokemon"
	
	};
	int num = 0;

	bubble_sort(str_ptr, 5);

	for (int i = 0; i < 5; i++) {

		printf_s("String: %10s\n", str_ptr[i]);

	}

	// End Bubble Sort Test

	system("pause");
	system("cls");
	printf_s("Running Palindrome Program\n");
	system("pause");
	system("cls");

	// Test for Palindrome

	char string[50] = "race car";

	int result = is_palindrome(string, 50, 0);

	if (result == 1) {

		printf_s("The string is a palindrome\n");

	}
	else {

		printf_s("The string is not a palindrome\n");

	}

	// End Palindrome Test

	system("pause");
	system("cls");
	printf_s("Running Prime Sum Program\n");
	system("pause");
	system("cls");

	// Test for Prime Sum

	int sum = sum_primes(13);
	printf_s("Sum of prime numbers till n: %d\n", sum);

	// End Prime Sum Test

	system("pause");
	system("cls");
	printf_s("Running Max Occurences Program\n");
	system("pause");
	system("cls");

	// Test for Max Occurences

	char str[20] = "Test String";
	Occurences occurences[OCCURENCES_LENGTH] = { { 0, 0 } };
	int i = 0;
	char c = '\0';

	maximum_occurences(str, occurences, &i, &c);

	// End Max Occurences Test

	system("pause");
	system("cls");
	printf_s("Running Max Consecutive Integers Bonus Program\n");
	system("pause");
	system("cls");

	// Test for Max Consecutive Integers

	signed int consec_arr[ROWS][COLS] = { 
		{ -5, 6, 0, 2, 2 },
		{ 2, 2, 2, 9, 3 },
		{ 3, 3, 2, 1, -8 },
		{ 7, -2, 6, 0, 4 }
	};

	int** address_ptr = NULL;
	int* num_ptr = NULL;

	max_consecutive_integers(consec_arr, ROWS, COLS, address_ptr, num_ptr);

	// End Max Consecutive Integer Test

	system("pause");

	return 0;

}
