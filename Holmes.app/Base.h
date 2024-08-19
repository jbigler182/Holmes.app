#pragma once

#include "Headers.h"

class Base
{

private:

	double m_min_down{};
	double m_monthly_mortgage{};
	double m_monthly_tax{};
	double m_monthly_insurance{};
	double m_monthly_pmi{};
	double m_total_monthly_cost{};

public:

	Base(double min_down, double monthly_mortgage, double monthly_tax, double monthly_insurance, double monthly_pmi, double total_monthly_cost)
		: m_min_down{ min_down }
		, m_monthly_mortgage{ monthly_mortgage }
		, m_monthly_tax{ monthly_tax }
		, m_monthly_insurance{ monthly_insurance }
		, m_monthly_pmi{ monthly_pmi }
		, m_total_monthly_cost{ total_monthly_cost }
	{
	}

	// getters 
	double getMinDown() { return m_min_down; }
	double getMonthlyMortgage() { return m_monthly_mortgage; }
	double getMonthlyTax() { return m_monthly_tax; }
	double getMonthlyInsurance() { return m_monthly_insurance; }
	double getMonthlyPMI() { return m_monthly_pmi; }
	double getTotalMonthlyCost() { return m_total_monthly_cost; }

	// setters 
	//void setMinDown(double min_down) { m_min_down = min_down; }
	//void setMonthlyMortgage(double monthly_mortgage) { m_monthly_mortgage = monthly_mortgage; }
	//void setMonthlyTax(double monthly_tax) { m_monthly_tax = monthly_tax; }
	//void setMonthlyInsurance(double monthly_insurance) { m_monthly_insurance = monthly_insurance; }
	//void setMonthlyPMI(double monthly_pmi) { m_monthly_pmi = monthly_pmi; }
	//void setTotalMonthlyCost(double total_monthly_cost) { m_total_monthly_cost = total_monthly_cost; }
};



