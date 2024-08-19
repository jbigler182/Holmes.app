#include "Headers.h"
#include "Globals.h"
#include "Base.h"

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

// calculate/return annual rent price in 30 years and calculate total rent client will pay over 30 years
std::pair <double, double> rentIncrease(double rent)
{
	double new_rent{ rent };
	double total_rent{};

	// if client is not currently paying rent use national rent average for example
	if (rent == 0)
		new_rent = average_rent;

	bool first_year{ true };

	for (int years{ 0 }; years < loan_years; ++years)
	{
		if (first_year)
		{
			new_rent += (rent * average_rent_increase);
			total_rent = rent * months;
			first_year = false;
		}
		else
			new_rent += (new_rent * average_rent_increase);
		total_rent += (new_rent * months);
	}
	return { new_rent, total_rent };
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

// calculate total cost of PMI
double totalPMI(FirstTimeH_B& client, double monthly_mortgage, double monthly_pmi, double min_down)
{
	// get/calculate loan price
	double home_price{ FirstTimeH_B::getClientPrice(client) }; 

	// calculate loan price
	double loan_price{ home_price - min_down };

	// variable to manipulate remaining loan balance
	double loan_remaining{ loan_price };

	// calculate monthly interest (loan amount * Interest rate / months in a year)
	double monthly_interest_paid{ loan_remaining * (loan_interest_rate * rate_modifier) / months };

	// calculate principle each month
	double monthly_principle_paid{ monthly_mortgage - monthly_interest_paid };

	// variable container for storing monthly principle payments in loop below
	std::vector<double> principle_payments{}; // this is not effectient at all. gotta use a container that I don't need to know the size before hand

	// loop through as many months as it would take to go from original loan value to 80% of original loan value (does not account for home appreciation)
	for (int indices{ 0 }; loan_price > (home_price * 0.8); ++indices)
	{
		// decrease loan amount by principle paid that month
		loan_remaining -= monthly_principle_paid;

		// recalculate monthly interest with new loan amount
		monthly_interest_paid = loan_remaining * (loan_interest_rate * rate_modifier) / months;

		// use monthly interest to calculate new monthly principle paid
		monthly_principle_paid = monthly_mortgage - monthly_interest_paid;

		// push principle payment into std::vector principle_payments
		principle_payments.push_back(monthly_principle_paid);

		// every 12 months increase home property value by annual appreciation_average (currently set at 0.03 percent but will eventually vary)
		if (indices % months == 0)
		{
			home_price += (home_price * appreciation_average);
		}
	}

	// reset home_price to original value so we can add to it again for next loop
	home_price = FirstTimeH_B::getClientPrice(client);

	// calculate total pmi cost

	double pmi_total_cost{};

	// loop through principle_payments container. When loan_price is less then 80% of home_price, return pmi_total_cost
	for(std::size_t x{0}; loan_price > (home_price * 0.8); loan_price -= principle_payments[x], ++x)
	{
		// calculate total pmi cost
		pmi_total_cost += monthly_pmi;
		// every 12 months increase home property value by annual appreciation_average (currently set at 0.03 percent but will eventually vary)
		if (x % months == 0)
		{
			home_price += (home_price * appreciation_average);
		}
	}
	return pmi_total_cost;
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void biggerPicture(FirstTimeH_B& client, Base& minimums) 
{
	// get client rent
	double client_rent{ FirstTimeH_B::getClientRent(client) };

	// calculate rent increase over 30 years
	std::pair rent_increase { rentIncrease(client_rent) }; // .first monthly rent cost in 30 years // .second total rent paid over 30 years with 3% annual increase

	//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

	// calculate total cost of home loan (P&I) with 30 year loan
	double total_loan { amortization(FirstTimeH_B::getClientPrice(client), loan_interest_rate).second - minimums.getMinDown() };

	// calculate property tax at end of life of loan
	[[maybe_unused]] double annual_tax_end_loan { propertyTax(client).first };
	// calculate total cost of taxes paid over 30 years
	double total_tax{ propertyTax(client).second };

	// calculate cost of home owners insurance at end of loan
	[[maybe_unused]] double insurance_end_loan{ insuranceCost().first};
	// calculate total cost of home owners insurance over 30 years
	double total_insurance{ insuranceCost().second};

	// calculate pmi cost
	double total_pmi{ totalPMI(client , minimums.getMonthlyMortgage(), minimums.getMonthlyPMI(), minimums.getMinDown()) };

	// calculate total cost of home over 30 years
	double total_cost_home{ total_loan + total_tax + total_insurance + total_pmi };

	//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

	// calculate home appreciation
	double end_loan_home_value{ appreciation(FirstTimeH_B::getClientPrice(client), 30) };

	//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

	// print results

	std::cout
		<< std::setprecision(2) << std::fixed << '\n' << '\n' << '\n' << '\n'
		<< "BIGGER PICTURE : WHY SHOULD YOU BUY THIS HOME?\n\n"
		<< "Rent for the next 30 years and you'll spend a total of $" << rent_increase.second << " on rent and have nothing, $0.00, to show for it\n"
		<< "Buy, and spend a total of $" << total_cost_home << " over 30 years and have $" << end_loan_home_value - (total_cost_home - rent_increase.second) << " to show for it!\n\n"
		<< "Spend $" << total_cost_home - rent_increase.second << " more to make $" << end_loan_home_value - (total_cost_home - rent_increase.second) << " more"
		<< "\nSo, the BIGGER PICTURE is really a question, do you want to make $0.00 to live in your residence, or make " << end_loan_home_value - (total_cost_home - rent_increase.second) << " to live in your residence?"



		<< '\n' << '\n' << '\n' << '\n' << '\n'

		<< "MORE BORING INFORMATION YOU MIGHT BE INTERESTED TO KNOW : " << '\n' << '\n'

		<< "RENT (with 3% annual increase) : \n\n"
		<< "Client current rent : $" << client_rent << '\n'
		<< "Clients monthly rent price in 30 years : $" << rent_increase.first << '\n'
		<< "Rent client will pay over next 30 years : $" << rent_increase.second << '\n' << '\n'

		<< "MORTGAGE (P/I) : \n\n"
		<< "Total cost of loan : $" << total_loan << '\n' << '\n'

		<< "HOME VALUE In... : \n"
		<< "5 years : " << appreciation(client.getClientPrice(client), 5) << '\n'
		<< "10 years : " << appreciation(client.getClientPrice(client), 10) << '\n'
		<< "15 years : " << appreciation(client.getClientPrice(client), 15) << '\n'
		<< "20 years : " << appreciation(client.getClientPrice(client), 20) << '\n'
		<< "30 years (end of loan) : " << appreciation(client.getClientPrice(client), 30) << '\n' << '\n'

		<< "TAXES (1% rate with annual property increase of 2%) : \n\n" 
		<< "Client annual property tax bill at end of loan : $" << annual_tax_end_loan << '\n'
		<< "Total taxes paid over life of 30 year loan : $" << total_tax << '\n' 
		<< "How property taxes are calculated vary by location\n\n" 

		<< "INSURANCE (2.5% annual increase) : \n\n" 
		<< "What insurance will cost at end of loan : $" << insurance_end_loan << '\n'
		<< "Total cost of home owners insurance over 30 years : $" << total_insurance << '\n' << '\n'

		<< "PMI (0.9% rate : 680 - 700 credit score) : \n\n" 
		<< "Monthly pmi cost : $" << minimums.getMonthlyPMI() << '\n'
		<< "Total pmi cost : $" << total_pmi << '\n' << '\n' << '\n'

		<< "TOTAL COSTS : \n\n" 
		<< "Total cost of home over 30 years (P/I + taxes + insurance + PMI) : $" << total_cost_home << '\n'
		<< "In 30 years your properties value will be (3% annual increase) : " << end_loan_home_value << '\n';
}

