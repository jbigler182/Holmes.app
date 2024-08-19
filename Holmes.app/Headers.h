#pragma once

// preprocessor directives
#include <iostream>
#include <string>
#include <iomanip>
#include "FirstTimeH_B.h"
#include <limits>
#include <utility>
#include <locale>
#include <vector>
#include "Base.h"

// forward declarations

FirstTimeH_B getFirstTimeH_B_Price();
void firstTime();
void homeOwner();
double minDown(FirstTimeH_B& client_dream);
std::pair<double, double> amortization(double loan_amount, double loan_interest_rate);
std::pair<double, double> propertyTax(FirstTimeH_B& market_value);
double appreciation(double price, double years);
std::pair<double, double> insuranceCost();
void biggerPicture(FirstTimeH_B& client, Base& minimums);

// classes

class comma : public std::numpunct<char>
{
protected:
	virtual char do_thousands_sep() const
	{
		return ',';
	}

	virtual std::string do_grouping() const
	{
		return "\03";
	}
};

// functions

#include <iostream>
#include <ios>
#include <limits>

inline void ignore()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}






