#include "Headers.h"
#include "Globals.h"


// function returns monthly payment and total cost of loan
std::pair<double, double> amortization(double loan_amount, double loan_interest)
{
	// calculate clients monthly payment
	double monthly_interest_rate{ loan_interest * rate_modifier / months };

	// M = P [ I(1 + I)N ] / [ (1 + I)N ? 1]
	int total_number_of_loan_months{ loan_years * months };
	double periodic_interest_rate{ 1 + monthly_interest_rate };
	double equation_part_one{ (pow(periodic_interest_rate , total_number_of_loan_months) - 1) };
	double equation_part_two{ monthly_interest_rate * pow(periodic_interest_rate, total_number_of_loan_months) };
	double equation_part_three{ equation_part_one / equation_part_two };

	double monthly_payment{ loan_amount / equation_part_three };

	// calculate total cost of loan
	double total_cost_loan{ monthly_payment * (loan_years * months) };

	return { monthly_payment, total_cost_loan };
}