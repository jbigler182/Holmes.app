#ifndef GLOBALS_H
#define GLOBALS_H


// global variables

// used in : amortization.cpp
inline extern int months{ 12 };

// used in : amortization.cpp -- appreciation.cpp -- insurance.cpp -- property tax.cpp 
inline extern int loan_years{ 30 }; // most common loan term

// used in amortization.cpp
inline extern double rate_modifier{ 0.01 };

// used in : amortization.cpp
inline extern double loan_interest_rate{ 7.6 };

// used in : appreciation.cpp
inline extern double appreciation_average{ 0.03 };  // home annual appreciation varies depending on location. this rate is usa national average according to Forbes 2 - 3%

// used in : insurance.cpp -- 2a.first time home buyer.cpp
inline extern double insurance_cost{ 2153 }; // this is a u.s. average but prices vary depending on a variety of factors

// used in : insurance.cpp
inline extern double annual_increase{ 0.025 }; // i made this up for now i don't know how much it increases each year

// used in property tax.cpp
inline extern double tax_rate{ 0.01 };
inline extern double tax_annual_rate_increase{ 0.02 };

// used in 2a.first time.cpp
inline extern double pmi_rate{ 0.0098 }; // this is a rate for a fairly good (680 - 700) credit score

// used in 3a.bigger picture.cpp function -- std::pair <double, double> rentIncrease(double rent)
inline extern double average_rent_increase{ .03 }; // a rent increase equal to average home value appreciation 
inline extern double average_rent{ 1800 }; // current average national rent price


#endif // !GLOBALS_H
