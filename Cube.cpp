/*
Nathan Melton
CISP II
Create cube class and access, set value in different ways.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int COL_WIDTH = 15;

class Cube
{
public:
	Cube(double edgeLength);
	Cube();
	void setEdgeLength(double edgeLength);
	double getEdgeLength();
	double getSurfaceArea();
	double getVolume();
	double getFaceDiagonal();
private:
	double edgeLength;
};

int main()
{
	// Create 3 cubes in different ways
	Cube cube1;

	Cube cube2;
	cube2.setEdgeLength(5);

	Cube cube3 = Cube(10);

	// Print cube data
	cout << left;
	cout << "Cube 1: Default constructor\n";
	cout << setw(COL_WIDTH) << "EdgeLength" << ": " << cube1.getEdgeLength() << '\n';
	cout << setw(COL_WIDTH) << "Surface Area" << ": " << cube1.getSurfaceArea() << '\n';
	cout << setw(COL_WIDTH) << "Volume" << ": " << cube1.getVolume() << '\n';
	cout << setw(COL_WIDTH) << "Face Diag" << ": " << cube1.getFaceDiagonal() << "\n\n";

	cout << "Cube 2: Default constructor/edgelength set via accessor\n";
	cout << setw(COL_WIDTH) << "EdgeLength" << ": " << cube2.getEdgeLength() << '\n';
	cout << setw(COL_WIDTH) << "Surface Area" << ": " << cube2.getSurfaceArea() << '\n';
	cout << setw(COL_WIDTH) << "Volume" << ": " << cube2.getVolume() << '\n';
	cout << setw(COL_WIDTH) << "Face Diag" << ": " << cube2.getFaceDiagonal() << "\n\n";

	cout << "Cube 3: Edgelength set via arg passed to constructor\n";
	cout << setw(COL_WIDTH) << "EdgeLength" << ": " << cube3.getEdgeLength() << '\n';
	cout << setw(COL_WIDTH) << "Surface Area" << ": " << cube3.getSurfaceArea() << '\n';
	cout << setw(COL_WIDTH) << "Volume" << ": " << cube3.getVolume() << '\n';
	cout << setw(COL_WIDTH) << "Face Diag" << ": " << cube3.getFaceDiagonal() << "\n\n";

	system("pause");
    return 0;
}

// Cube constructors
Cube::Cube(double edgeLength)
{
	Cube::edgeLength = edgeLength;
}

Cube::Cube()
{
	Cube::edgeLength = 0.0;
}

// Cube accessors
double Cube::getEdgeLength() {
	return edgeLength;
}

double Cube::getSurfaceArea() {
	return (6 * pow(edgeLength, 2));
}

double Cube::getVolume() {
	return (pow(edgeLength, 3));
}

double Cube::getFaceDiagonal() {
	return (sqrt(2) * edgeLength);
}

// Cube mutators
void Cube::setEdgeLength(double edgeLength) {
	Cube::edgeLength = edgeLength;
}
