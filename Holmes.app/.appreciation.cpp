#include "Globals.h"

double appreciation(double price, double years=30)
{
	double annual_appreciation{};
	double new_value{};

	bool first_year{ true }; // boolean to calculate first year appreciation values/taxes. Read in purchase price

	for (auto loan_year{ 0 }; loan_year < years; ++loan_year)
	{
		if (first_year)
		{
			// calculate first year appreciation of home
			annual_appreciation = price * appreciation_average;
			new_value = price + annual_appreciation;

			first_year = false;
		}
		else

			// calculate all years after first year up to end of loan appreciation of home
			annual_appreciation = new_value * appreciation_average;
			new_value += annual_appreciation;
	}
	return new_value;
}