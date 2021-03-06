/*
Nathan Melton
CISP II
Dynamically allocate and sort an array of test grades.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
void ascendingSort(int *testScores, int size);
double averageScores(int *testScores, int size);
void printScores(int *testScorse, int size);

int main()
{
	// Ask user for test score count
	int testCount = 0;
	cout << "Input number of test scores\n:";
	cin >> testCount;

	while (testCount < 1) {
		cout << "Test count must be at least 1. Try again\n:";
		cin >> testCount;
	}

	// Allocate array with size according to user input
	int *testScores = new int[testCount];

	// Ask user for each test score, storing in array
	for (int i = 0; i < testCount; i++) {
		cout << "Input test score " << i + 1 << "\n:";
		cin >> *(testScores + i);

		while (*(testScores + i) < 0) {
			cout << "Test score must be positive. Try again.\n:";
			cin >> *(testScores + i);
		}
	}

	// Sort the array
	ascendingSort(testScores, testCount);

	// Print the array
	printScores(testScores, testCount);

	system("pause");
    return 0;
}

// Bubble sorts the given array in ascending order
void ascendingSort(int *testScores, int size) {
	bool swap = true;
	while (swap) {
		swap = false;
		for (int i = 0; i < size - 1; i++) {
			if (*(testScores + i) > *(testScores + i + 1)) {
				int tmp = *(testScores + i);
				*(testScores + i) = *(testScores + i + 1);
				*(testScores + i + 1) = tmp;
				swap = true;
			}
		}
	}
}

// Average and return the values of the given array
double averageScores(int *testScores, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(testScores + i);
	}
	return sum / static_cast<int>(size);
}

// Print each element of array as well as average
void printScores(int *testScores, int size) {
	cout << "\nScore average: " << setprecision(2) << fixed << averageScores(testScores, size) << "\n\n";
	cout << "Scores:\n";

	for (int i = 0; i < size; i++) {
		cout << *(testScores + i) << '\n';
	}

	cout << '\n';
}
