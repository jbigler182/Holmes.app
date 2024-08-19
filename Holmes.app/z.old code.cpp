//
//std::cout
//<< std::setprecision(2) << std::fixed << '\n'
//<< "The BIGGER PICTURE" << '\n' << '\n'
//<< "First: " << '\n'
//<< "When this home is paid off in 30 years it will be worth a minimum of $" << end_loan_home_value << '\n'
//<< "Second: " << '\n'
//<< "You will pay $" << rent_increase_and_total.second << " in rent over the next 30 years if you don't buy a home" << '\n'
//<< "Third: " << '\n'
//<< "The total cost of the home over 30 years is $" << total_cost_home << " (Principle/Interest + Taxes + PMI + Insurance)" << '\n'
//<< "Fourth: " << '\n'
//<< "That means you will pay a total of $" << difference << " (positive number here = more / negative number here = less) over the next 30 years for a home this price. That's " << "$" << annual_difference << " a year and $" << monthly_difference << " more a month." << '\n' << '\n'
//<< "So why do it! It costs more!!! Because..." << '\n'
//<< "First: " << '\n'
//<< "In 30 years you will have made $" << end_loan_home_value - difference << " on your home!" << '\n'
//<< "Second: " << '\n'
//<< "You will only have to pay Property Taxes and Insurance to live in your own home from then on which will be $" << (insuranceCost().first + propertyTax(client).first) / months << " a month"
//<< " while monthly rent in 30 years will be : $" << rent_increase_and_total.first;
//// next show how much you actually make. pay more to make more. Then write a function to show the 10 years after home is paid off!!


// PMI and credit score
//Your credit score
//
//Annual average premium as a percentage of original loan amount
//
//620 - 639
//
//1.50 % .
//
//640 - 659
//
//1.31 % .
//
//660 - 679
//
//1.23 % .
//
//680 - 699
//
//0.98 % .
//
//700 - 719
//
//0.79 % .
//
//720 - 739
//
//0.70 % .
//
//740 - 759
//
//0.58 % .
//
//760 and above
//
//0.46 % .

//double totalPMI(FirstTimeH_B& client, double monthly_mortgage, double pmi, double min_down)
//{
//	// get/calculate loan price
//	double home_price{ FirstTimeH_B::getClientPrice(client) }; // at 3% to this price every 12 times through the loop
//	//double down_payment{ home_price * .03 };
//	double twenty_percent{ home_price * .2 };
//	double pmi_end{ home_price - twenty_percent };
//	//double pmi_start{ home_price - down_payment };*/
//
//	double loan_price{ FirstTimeH_B::getClientPrice(client) - min_down };
//
//	double loan_remaining{ loan_price };
//	double monthly_interest_paid{ loan_remaining * (loan_interest_rate * rate_modifier) / months }; // then devide by months
//	double monthly_principle_paid{ monthly_mortgage - monthly_interest_paid };
//
//	std::cout << std::setprecision(2) << std::fixed << '\n'
//		<< "loan price " << loan_remaining << '\n'
//		<< "monthly mortgage " << monthly_mortgage << '\n'
//		<< "interest paid the first month " << monthly_interest_paid << '\n'
//		<< "Monthly principle paid " << monthly_principle_paid << '\n' << '\n';
//
//	double principle_payments[300]{}; // this is not effectient at all. gotta make it vector or something...
//
//	for (int indicies{ 0 }; loan_remaining > pmi_end; ++indicies)
//	{
//		loan_remaining = loan_remaining - monthly_principle_paid;
//		monthly_interest_paid = loan_remaining * (loan_interest_rate * rate_modifier) / months;
//		monthly_principle_paid = monthly_mortgage - monthly_interest_paid;
//		principle_payments[indicies] = monthly_principle_paid;
//		std::cout << indicies << ' ';
//	}
//
//
//	//for (every 12 times through (12 months) the below function add 3 % to home_price) 
//	// my pmi calculation isn't weighted again total cost of home at the moment... its based of loan value dumb dumb...
//
//
//	double pmi_total_cost{};
//	// this can be a statement that is when paid off is 20% of home_price
//	for (std::size_t x{ 0 }; loan_price > (home_price * 0.8); loan_price -= principle_payments[x], ++x)
//		//for (std::size_t x{ 0 }; pmi_end < pmi_start; pmi_start -= principle_payments[x], ++x) // this will have to come from our container made above and change each loop
//	{
//		pmi_total_cost += pmi;
//		if (x % 12 == 0)
//		{
//			home_price = home_price + (home_price * 0.03);
//			// test
//			std::cout << '\n' << '\n' << home_price << '\n' << '\n';
//		}
//	}
//
//	return pmi_total_cost;
//}

//
//void setFirstTimeH_B_Rent(FirstTimeH_B& client)
//{
//
//	std::cout << '\n'
//		<< "How much are you paying for rent : " << '\n'
//		<< "(If you are not currently paying rent select 0 and we will " << '\n'
//		<< "use the national average of $1,800.00 for preliminary calculation)" << '\n' << '\n'
//		<< "Current Rent: ";
//
//	// get client rent
//	double rent{};
//	std::cin >> rent;
//	if (!std::cin) { ignore(); }
//
//	// set client rent
//	client.setClientRent(rent);
//}


	// increases the down payment by one penny until monthly cost for loan is equal to .57 of client gross income
//for (; client_afford < monthly_cost; new_down_payment += penny)
//{
//	new_loan_total = amortization(client.getClientPrice(client) - new_down_payment).first;
//	monthly_cost = minimums.getMonthlyInsurance() + minimums.getMonthlyPMI() + minimums.getMonthlyTax() + new_loan_total;
//
//
//
//}