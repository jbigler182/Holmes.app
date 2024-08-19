#include "Headers.h"
#include "Globals.h"
#include "Base.h"

// stepTwo : determine options
void stepTwo(FirstTimeH_B& client, Base minimums)
{
	// calculate max monthly payment client can afford
	double dti{ 0.57 }; // max dti for FHA loan (others set their limits closer to 40%)
	double client_afford{ FirstTimeH_B::getClientMonthlyIncome(client) * dti };

	// print what client can afford at current average interest rate
	std::cout
		<< '\n' << '\n' << std::setprecision(2) << std::fixed << '\n'
		<< "At today's average interest rate (" << loan_interest_rate << "%) you can afford a maximum mortgage payment of (DTI of .57) $" << client_afford << '\n'
		<< "The approximate total mortgage (P/I + Taxes + Insurance + PMI) for a $" << FirstTimeH_B::getClientPrice(client) << " home (with lender minimum of 3% ($" << minimums.getMinDown() << ") down payment) is $" << minimums.getTotalMonthlyCost() << '\n' << '\n';

	// quick glance at options to close the gap
	if (client_afford < minimums.getTotalMonthlyCost())
	{
		std::cout
			<< "\nSo, you cannot afford this home just yet. Let's first look at how we can close 'the gap' and get you into your own home\n";

		//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

		// calculate what loan amount client can afford with current monthly income

		double cent{ 0.01 };

		// calculate client loan
		double affordable_loan{ FirstTimeH_B::getClientPrice(client) - minimums.getMinDown() };

		double monthly_cost{ minimums.getTotalMonthlyCost() };
		double new_monthly_payment{};

		// subtract one cent each loop from desired home amount until total monthly payment is less then what client can afford
		for (; client_afford < monthly_cost; affordable_loan -= cent)
		{
			new_monthly_payment = amortization(affordable_loan, loan_interest_rate).first;
			monthly_cost = new_monthly_payment + minimums.getMonthlyInsurance() + minimums.getMonthlyPMI() + minimums.getMonthlyTax();
		}

		// print second option
		std::cout << '\n' << '\n' << "Option 1: Buy less house : " << '\n'
			<< "With your current monthly income, at the current average interest rate, " << loan_interest_rate <<"% you can afford a loan of $" << affordable_loan;

		//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

		// calculate how much more down payment client will need with current monthly income

		double down_payment{ minimums.getMinDown() };
		double new_down_payment{ minimums.getMinDown() };

		double monthly_monthly_costs{ minimums.getTotalMonthlyCost() };
		double new_new_loan_total{ client.getClientPrice(client) - down_payment };

		// increases the down payment by one penny until monthly cost for loan is equal to .57 of client gross income
		for (; client_afford < monthly_monthly_costs; new_down_payment += cent)
		{
			new_new_loan_total = amortization(client.getClientPrice(client) - new_down_payment, loan_interest_rate).first;
			monthly_monthly_costs = minimums.getMonthlyInsurance() + minimums.getMonthlyPMI() + minimums.getMonthlyTax() + new_new_loan_total;
		}

		// calculate new down payment percentage
		double new_percentage_down{ (new_down_payment / client.getClientPrice(client)) * 100 };

		std::cout << '\n' << '\n'
			<< "Option 2: Increase down payment : " << '\n'
			<< "From minimum (3%) : $" << down_payment << " to (" << new_percentage_down << "%) $" << new_down_payment << '\n';

		//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
		
		// calculate / print difference between loan monthly minimums and client gross monthly income

		std::cout 
			<< "\nOption 3: Increase your monthly income (ex. Take that promotion, add co-signer to loan (significant other, parent, etc.) : \n"
			<< "You need $" << minimums.getTotalMonthlyCost() - client_afford << " more a month to afford this home\n\n";

		//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

		// calculate interest rate gap

		double new_interest_rate{ loan_interest_rate };

		double mortgage_total_monthly{ minimums.getTotalMonthlyCost() };
		double new_loan_total{ client.getClientPrice(client) - down_payment };
		double n_down_payment{ minimums.getMinDown() };

		// increases the down payment by one penny until monthly cost for loan is equal to .57 of client gross income
		for (; client_afford < mortgage_total_monthly; new_down_payment += cent, new_interest_rate -= cent)
		{
			new_loan_total = amortization(client.getClientPrice(client) - n_down_payment, new_interest_rate).first;
			mortgage_total_monthly = minimums.getMonthlyInsurance() + minimums.getMonthlyPMI() + minimums.getMonthlyTax() + new_loan_total;
		}

		if (new_interest_rate < 0)
		{
		}
		else
			std::cout
			<< "Option 4: Get a lower interest rate of : "
			<< "\nThe rate would have to drop to : " << new_interest_rate << "%";
	}
	else
	{
		std::cout 
			<< "\nGood news. With a " << minimums.getMinDown() << " down payment, you can afford this home. Go buy it!";
		return;
	}
}

double minDown(FirstTimeH_B& client)
{
	// get client dream home price
	double price{ FirstTimeH_B::getClientPrice(client) };

	// minimum down on a 30 year conventional loan is 3%
	double min_down_conventional{ 0.03 };

	// calculate minimum down payment
	double min{ price * min_down_conventional };

	return { min };
}

// step One : create Types (get client info / calculate monthly costs)
std::pair<FirstTimeH_B, Base> stepOne()
{
	// get client home information (three data points)
	FirstTimeH_B client{ getFirstTimeH_B_Price() };

	// calculate min down payment
	static double min_down{ minDown(client) };

	//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

	// calculate monthly mortgage
	double monthly_mortgage{ amortization(FirstTimeH_B::getClientPrice(client) - min_down, loan_interest_rate).first };

	// calculate monthly property taxes
	double monthly_tax{ propertyTax(client).first / months };

	// calculate monthly home owner insurance cost
	double monthly_insurance{ insurance_cost / months };

	// calculate monthly pmi payment	pmi monthly = (pmi percentage * loan amount) / months
	static double monthly_pmi{ (pmi_rate * (FirstTimeH_B::getClientPrice(client) - min_down)) / months };

	// calculate total monthly cost of home
	double total_monthly_cost{ monthly_mortgage + monthly_tax + monthly_insurance + monthly_pmi };

	// set Base class
	static Base minimums{ min_down, monthly_mortgage, monthly_tax, monthly_insurance, monthly_pmi, total_monthly_cost };

	//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

	return { client, minimums };
}

void firstTime()
{
	std::pair client_minimums{ stepOne() }; // client inputs and purchase minimums (FirstTimeH_B / Base Types)

	stepTwo(client_minimums.first, client_minimums.second); // what can they afford

	biggerPicture(client_minimums.first, client_minimums.second);
}