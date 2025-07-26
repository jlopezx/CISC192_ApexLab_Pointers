/* File: apex_code.cpp
 * Project: Apex Lab 7 - Pointers
 * Class: CISC 192 - C++
 * Professor: Alex Chow
 * Written by: Joshua Lopez
 * Description: This file defines a member function from Cup struct and 3 standalone functions.
 *
 * double Cup::capacityInMls() const:
 * -Cup member function calculates the volume of a truncated cone using constants and member variables.
 *
 * bool addFluid(Cup* cup, double mls):
 * -Standalone function that adds fluid to a cup's fluid amount. Function takes two arguments.
 *  A Cup object's memory address and the amount of fluid to be added. It returns false if there's an
 *  overflow or there isn't enough fluid to be removed, else it will update cup's amountOfFluid variable
 *  and return true indicating a fill was successful.
 *
 * double howFull(const Cup& cup):
 * -This function returns percentage based on a fluid to capacity ratio. It takes the cup's amountOfFluid
 *  value and divides it by the total capacity the cup can hold.
 *
 * bool mlPerDollar(const Cup& cup, double pricePerDrink, double& output):
 * -This function checks if pricePerDrink is negative if it is, it returns false, else it will assign
 *  output with the capacity divided by the price amount in ml and returns true. Output is passed by
 *  reference and holds the amount of drinks in milliliters that can be purhcase per dollar.
 *
 * */
#include "apex_code.h"

// Cup member function calculates the volume of a truncated cone using constants and member variables
double Cup::capacityInMls() const {
	// Breaking down the formula into easier to read sections for better code readability, and so I
	// didn't have to return a longer formula.

	// PI = 3.1415...
	double π = M_PI;
	// r²: top radius squared
	double topSquare = pow(topRadiusCms ,SQUARE);
	// R²: bottom radius squared
	double bottomSquare =  pow(bottomRadiusCms, SQUARE);
	// r * R: the average cross-sectional area of the cone between the two circular bases.
	double crossSectArea = topRadiusCms * bottomRadiusCms;

	// Formula below calculates the volume of a truncated cone.
	// V = (1/3) * π * h * (r² + r * R + R²)
	return ONE_THIRD_FACTOR * π * heightCms * (topSquare + crossSectArea + bottomSquare);
}

// Standalone function that adds fluid to a cup's fluid amount.
// Function takes two arguments. A Cup object's memory address and the amount of fluid to be added
bool addFluid(Cup* cup, double mls) {

	// Stores the amount of fluid in the amount to currentFluid for easier code reading.
	double currentFluid = cup->amountOfFluid;
	// If mls is negative, it checks if the required fluid that is currently in our cup can be removed.
	// Basically, we cannot remove what isn't there.
	if (currentFluid + mls < 0) { return false; }

	// Calculates the space leftover in the cup and stores it to a local variable for easier code reading.
	// Assignment is down here to not waste any operations on allocating space for a variable it may not use.
	double spaceRemaining = cup->capacityInMls() - cup->amountOfFluid;
	// Checks if we will get an overflow by checking if the amount of mls being added to the space
	// remaining exceeds it. If our mls is greater than our space remaining, we will get a negative number
	// indicating an overflow.
	if (spaceRemaining - mls < 0) { return false; }

	// If the program reaches this point, it passed our error checking pattern and adds the desired
	// fluid amount to the Cup's amountOfFluid variable.
	cup->amountOfFluid += mls;

	return true;
}

// This function returns a percentage based on a fluid to capacity ratio. It takes the cup's amountOfFluid
// value and divides it by the total capacity the cup can hold.
double howFull(const Cup& cup) {
	return cup.amountOfFluid / cup.capacityInMls();
}

// Checks if pricePerDrink is negative, if it is, it returns false, else it will assign output with
// the capacity divided by the price amount in ml and returns true. Variable output is passed by
// reference and holds the amount of drinks in milliliters that can be purhcase per dollar.
bool mlPerDollar(const Cup& cup, double pricePerDrink, double& output) {
	// A ternary operator is used to check if pricePerdrink is not negative. If not negative, it assigns
	// output with capacity / pricePerDrink, else it returns false if it is negative.
	return pricePerDrink > 0 ? output = cup.capacityInMls() / pricePerDrink, true : false;
}
