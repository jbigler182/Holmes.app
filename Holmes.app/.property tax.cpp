#include "Headers.h"
#include "Globals.h"

std::pair<double, double> propertyTax(FirstTimeH_B& market_value)
{
	double home_value{ FirstTimeH_B::getClientPrice(market_value) };

	double annual_taxes{};
	double new_annual_taxes{};
	double total_taxes_paid{};

	bool first_year { true }; // boolean to calculate first year appreciation values/taxes. Read in purchase price

	for (auto loan_year { 0 }; loan_year < loan_years; ++loan_year)
	{
		if (first_year)
		{
			// calculate taxes for first year (does not account for tax increases yet)
			annual_taxes = home_value * tax_rate;
			new_annual_taxes = annual_taxes;
			total_taxes_paid = annual_taxes;

			first_year = false;
		}
		else
		{
			home_value += home_value * tax_annual_rate_increase;
			new_annual_taxes = home_value * tax_rate;
			total_taxes_paid += new_annual_taxes;
		}
	}
	return { new_annual_taxes, total_taxes_paid };
}
