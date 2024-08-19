#include "Headers.h"
#include "Globals.h"

std::pair<double, double> insuranceCost()
{
	double total_cost{};
	double end_monthly{};

	bool first_year{ true };

	for (int year{ 0 }; year < loan_years; ++year)
	{
		if (first_year)
		{
			end_monthly = insurance_cost;
			total_cost = insurance_cost;

			first_year = false;
		}
		else
		{
			end_monthly = end_monthly + (end_monthly * annual_increase);
			total_cost = total_cost + end_monthly;
		}
	}
	return { end_monthly, total_cost };
}