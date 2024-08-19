#pragma once

class FirstTimeH_B
{

private:

	double m_home_price{};
	double m_gross_monthly_income{};
	double m_monthly_rent{};

public:

	FirstTimeH_B(double home_price, double gross_monthly_income, double client_rent)
		: m_home_price{ home_price }
		, m_gross_monthly_income{ gross_monthly_income }
		, m_monthly_rent{ client_rent }
	{
	}

	// getters 
	static double getClientPrice(FirstTimeH_B& client) { return client.m_home_price; }
	static double getClientMonthlyIncome(FirstTimeH_B& client) { return client.m_gross_monthly_income; }
	static double getClientRent(FirstTimeH_B& client) { return client.m_monthly_rent; }

	// setters 
	void setClientRent(double rent) { m_monthly_rent = rent; }
};