/*
Nathan Melton
CISP 1010
Read customer data from file, print finance charge and ending balance, output finance charge and ending balance to file.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main()
{
	// Width of table columns
	const int COL_WIDTH = 15;
	// Finance charge rate set by credit card company
	const double FINANCE_CHARGE_RATE = 0.01;
	// Input and ouput file paths
	const std::string INPUT_FILE_PATH = "BeginningBalance.txt";
	const std::string OUTPUT_FILE_PATH = "NewBalance.txt";

	// Open input file
	std::ifstream inputFile;
	inputFile.open(INPUT_FILE_PATH);

	// Holds ids and endingbalances for output to file later
	int customerIds[2];
	double customerEndingBalances[2];

	// Keeps running total of each customer attribute
	const int TSIZE = 5;
	double totals[TSIZE] = {};

	// If file was opened correctly
	if (inputFile) {

		// Print table header
		std::cout << std::left << std::setw(COL_WIDTH) << "Cust No" << std::setw(COL_WIDTH) << "Beg. Bal." << std::setw(COL_WIDTH) << "Finance Charge" <<
			std::setw(COL_WIDTH) << "Purchases" << std::setw(COL_WIDTH) << "Payments" << std::setw(COL_WIDTH) << "Ending Bal." << std::endl;

		// Loop once per customer
		for (int i = 0; i < 2; i++) {
			// Input variables
			int id = 0;
			double beginningBalance = 0, purchases = 0, payments = 0;

			// Calculated variables
			double financeCharge = 0, endingBalance = 0;

			// Get variables from inputfile
			inputFile >> id >> beginningBalance >> purchases >> payments;

			// Calculate financeCharge and endingBalance
			financeCharge = beginningBalance * FINANCE_CHARGE_RATE;
			endingBalance = beginningBalance + financeCharge + purchases - payments;

			// Update totals
			totals[0] += beginningBalance;
			totals[1] += financeCharge;
			totals[2] += purchases;
			totals[3] += payments;
			totals[4] += endingBalance;

			// Print id, beginningBalance, financeCharge, purchases, payments, and endingBalance
			std::cout << std::setw(COL_WIDTH) << id << std::fixed << std::setprecision(2) << std::setw(COL_WIDTH) << beginningBalance <<
				std::setw(COL_WIDTH) << financeCharge << std::setw(COL_WIDTH) << purchases << std::setw(COL_WIDTH) << payments <<
				std::setw(COL_WIDTH) << endingBalance << std::endl;

			// Store id and ending balance for output to file
			customerIds[i] = id;
			customerEndingBalances[i] = endingBalance;
		}

		// Print totals row
		std::cout << std::endl << std::setw(COL_WIDTH) << "Totals";
		for (int i = 0; i < TSIZE; i++) {
			std::cout << std::setw(COL_WIDTH) << totals[i];
		}

		std::cout << std::endl;

		// Close the input file
		inputFile.close();
	}
	// If file was not opened correctly
	else {
		std::cout << "Error reading input file." << std::endl;
	}

	// Open ouput file
	std::ofstream outputFile;
	outputFile.open(OUTPUT_FILE_PATH);

	// If file was opened correctly
	if (outputFile) {
		// Loop once for each customer
		for (int i = 0; i < 2; i++) {
			// Ouput id and endingBalance to ouput file
			outputFile << std::fixed << std::setprecision(2) << customerIds[i] << "\n" << customerEndingBalances[i] << "\n";
		}

		// Close the ouput file
		outputFile.close();
	}
	// If file was not opened correctly
	else {
		std::cout << "Error writing output file." << std::endl;
	}

	// Prevent console window from closing
	system("pause");

	// Return 0 if no errors
    return 0;
}

