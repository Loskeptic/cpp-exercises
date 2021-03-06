/*
Nathan Melton
CISP II
Create object to represent movie. Make a constructor for it and print data to console.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int COL_WIDTH = 15;

// Prototypes
void displayMovieData(struct Movie movie1, struct Movie movie2);

struct Movie {
	string title;
	string director;
	int releaseYear;
	int runningTime;

	// Constructor
	Movie(string title, string director, int releaseYear, int runningTime) {
		Movie::title = title;
		Movie::director = director;
		Movie::releaseYear = releaseYear;
		Movie::runningTime = runningTime;
	}
};

int main()
{
	// Create movie objects
	Movie mov1 = Movie("Spiderman: Into the Spider-verse", "Peter Ramsey", 2018, 116);
	Movie mov2 = Movie("Spider-man", "Sam Raimi", 2002, 121);
	
	// Print movie data
	displayMovieData(mov1, mov2);

	system("pause");
    return 0;
}

// Prints all members of each movie argument
void displayMovieData(struct Movie movie1, struct Movie movie2) {
	cout << "**Movie 1**\n";
	cout << left << setw(COL_WIDTH) << "Title" << ": " << movie1.title << '\n';
	cout << left << setw(COL_WIDTH) << "Director" << ": " << movie1.director << '\n';
	cout << left << setw(COL_WIDTH) << "Release Year" << ": " << movie1.releaseYear << '\n';
	cout << left << setw(COL_WIDTH) << "Runtime" << ": " << movie1.runningTime << "\n\n";

	cout << "**Movie 2**\n";
	cout << left << setw(COL_WIDTH) << "Title" << ": " << movie2.title << '\n';
	cout << left << setw(COL_WIDTH) << "Director" << ": " << movie2.director << '\n';
	cout << left << setw(COL_WIDTH) << "Release Year" << ": " << movie2.releaseYear << '\n';
	cout << left << setw(COL_WIDTH) << "Runtime" << ": " << movie2.runningTime << "\n\n";
}
