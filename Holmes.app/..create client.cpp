#include "Headers.h"

FirstTimeH_B getFirstTimeH_B_Price()
{		
	// get client desired home price
	std::cout << '\n' << "PRICE : ";
	double home_price{};
	std::cin >> home_price;
	if (!std::cin) { ignore(); }

	// get client income
	std::cout << '\n' << "GROSS MONTHLY INCOME : ";
	double monthly_income{};
	std::cin >> monthly_income;
	if (!std::cin) { ignore(); }

	// get client rent
	std::cout << '\n' << "MONTHLY RENT : ";
	double rent{};
	std::cin >> rent;
	if (!std::cin) { ignore(); }


	return FirstTimeH_B{ home_price, monthly_income, rent };
}