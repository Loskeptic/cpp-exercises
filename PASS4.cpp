/*
Nathan Melton
CISP 1010
User inputs number of each type of meal they ordered, outputs
subtotals, discounts, taxes, and totals for user's order.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Table formatting
	const int COL_WIDTH = 15;

	// Sales TAX
	const double TAX = 0.1;

	// Price of each meal type per unit
	const double BREAKFAST_PRICE = 5.5;
	const double LUNCH_PRICE = 9.5;
	const double DINNER_PRICE = 16.5;

	// Discounts for each meal type to be applied if threshold is exceeded
	const double BREAKFAST_DISCOUNT = 0.10;
	const double LUNCH_DISCOUNT = 0.15;
	const double DINNER_DISCOUNT = 0.12;

	// Amounts required to be purchased to recieve discount on respective meal type
	const int BREAKFAST_THRESH = 10;
	const int LUNCH_THRESH = 15;
	const int DINNER_THRESH = 8;

	int breakfastCount, lunchCount, dinnerCount;

	// Take in input from user
	cout << "Enter the number of Breakfast ordered: ";
	cin >> breakfastCount;
	// Ignore anything past int
	cin.ignore(9999, '\n');

	// Error check
	if (breakfastCount < 0) {
		cout << endl << "**Breakfast number must be int greater than 0**" << endl << endl;
		system("pause");
		return 1;
	}

	cout << "Enter the number of Lunch ordered: ";
	cin >> lunchCount;
	// Ignore anything past int
	cin.ignore(9999, '\n');

	// Error check
	if (lunchCount < 0) {
		cout << endl << "**Lunch number must be int greater than 0**" << endl << endl;
		system("pause");
		return 2;
	}

	cout << "Enter the number of Dinner ordered: ";
	cin >> dinnerCount;
	// Ignore anything past int
	cin.ignore(9999, '\n');

	// Error check
	if (dinnerCount < 0) {
		cout << endl << "**Dinner number must be greater than 0**" << endl << endl;
		system("pause");
		return 3;
	}

	// Start table on new line
	cout << endl;

	// cout settings
	cout << fixed << setprecision(2) << left;

	cout << "Catering Service Receipt:" << endl << endl;

	// Output table headers
	cout << setw(COL_WIDTH) << "Meal" << setw(COL_WIDTH) << "Quantity" << setw(COL_WIDTH) << "Cost" << setw(COL_WIDTH) << "Discount" << setw(COL_WIDTH) << "Cost After Discount" << endl;

	// Output breakfast row ------------------------------------------
	// Output title and number of breakfasts purchased
	cout << setw(COL_WIDTH) << "Breakfast" << setw(COL_WIDTH) << breakfastCount;

	// Calculate and output breakfast total before discount
	double breakfastTotal = breakfastCount * BREAKFAST_PRICE;
	cout << '$' << setw(COL_WIDTH - 1) << breakfastTotal;

	// Calculate and output discount and total cost after discount
	double discount = 0;
	if (breakfastCount > BREAKFAST_THRESH) {
		discount = breakfastTotal * BREAKFAST_DISCOUNT;
		breakfastTotal = breakfastTotal - discount;
	}
	else {
		discount = 0;
	}

	cout << '$' << setw(COL_WIDTH - 1) << discount << '$' << breakfastTotal << endl;


	// Output lunch row ------------------------------------------
	// Output title and number of lunches purchased
	cout << setw(COL_WIDTH) << "Lunch" << setw(COL_WIDTH) << lunchCount;

	// Calculate and output breakfast total before discount
	double lunchTotal = lunchCount * LUNCH_PRICE;
	cout << '$' << setw(COL_WIDTH - 1) << lunchTotal;

	// Calculate and output discount and total cost after discount
	if (lunchCount > LUNCH_THRESH) {
		discount = lunchTotal * LUNCH_DISCOUNT;
		lunchTotal = lunchTotal - discount;
	}
	else {
		discount = 0;
	}

	cout << '$' << setw(COL_WIDTH - 1) << discount << '$' << lunchTotal << endl;


	// Output dinner row ------------------------------------------
	// Output title and number of dinners purchased
	cout << setw(COL_WIDTH) << "Dinner" << setw(COL_WIDTH) << dinnerCount;

	// Calculate and output breakfast total before discount
	double dinnerTotal = dinnerCount * DINNER_PRICE;
	cout << '$' << setw(COL_WIDTH - 1) << dinnerTotal;

	// Calculate and output discount and total cost after discount
	if (dinnerCount > DINNER_THRESH) {
		discount = dinnerTotal * DINNER_DISCOUNT;
		dinnerTotal = dinnerTotal - discount;
	}
	else {
		discount = 0;
	}

	cout << '$' << setw(COL_WIDTH - 1) << discount << '$' << dinnerTotal << endl;

	// Divider between food type totals and total
	cout << endl << "*******************************************************************************" << endl << endl;

	double total = breakfastTotal + lunchTotal + dinnerTotal;
	double tax = total * TAX;

	// Ouput total, tax, and total w/ tax
	cout << setw(COL_WIDTH * 4) << "Total:" << '$' << total << endl;
	cout << setw(COL_WIDTH * 4) << "Sales Tax:" << '$' << tax << endl;
	cout << setw(COL_WIDTH * 4) << "Total Due:" << '$' << (total + tax) << "\n\n" << endl;

	// Prevent console window from closing
	system("pause");

	// Return 0 if no errors
    return 0;
}
