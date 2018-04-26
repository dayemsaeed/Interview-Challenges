#pragma once
#ifndef PA8_H
#define PA8_H

#include <stdio.h>
#include <cstdbool>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct occurences {

	int num_occurences;
	double frequency;

} Occurences;

typedef struct consec_occurences {

	int num_occurences;
	int* first_address;
	int number;

} Consec_occurences;

#define OCCURENCES_LENGTH 127
#define ROWS 4
#define COLS 5

char* my_str_n_cat(char* dest, const char* src, int size);
int binary_search(int values[], int target, int size);
void bubble_sort(char* strings_ptr[], int string_number);
int is_palindrome(char* string, int string_length, int index);
int sum_primes(unsigned int n);
void maximum_occurences(char* string, Occurences occurences[OCCURENCES_LENGTH], int* i, char* c);
void max_consecutive_integers(signed int arr[][COLS], int rows, int col, int** address_ptr, int* num_ptr);

#endif // PA8_H
