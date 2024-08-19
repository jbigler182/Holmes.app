// how is Holmes different?
// Holmes offers SIMPLE SOLUTIONS (HOW TO MAKE IT HAPPEN) and the BIGGER PICTURE (WHY MAKE IT HAPPEN). 
// HOLMES NEVER SAYS NO!!! If it takes 10 life times HOLMES will make it happen!!!

// HOW to make it happen and WHY make it happen!!! That's what we are programming 

// HOW and WHY... HOW and WHY... HOW and WHY!!!

// write a program specific to Los Angeles County California to start


// Step 1: Client enters : (1) home price, (2) current rent, (3) gross monthly income

// Step 2: Holmes calculates : 
// (1) what it takes to afford the home they want, 
// (2) what they can afford, 
// (3) the gap, 
// (4) how to close the gap, 
// (5) why close the gap

#include "Headers.h"

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void firstTimeIntro()
{
	using namespace std;

	cout << '\n'
		<< "Holmes will require three pieces of information : \n\n" 
		<< "(1) PRICE (What is the asking price of the home you want to buy), \n" 
		<< "(2) GROSS INCOME (total monthly income before all deduction (taxes, health insurance, etc.), and \n" 
		<< "(3) RENT (how much are you currently payment) \n\n" 
		<< "Select Enter to continue : ";

	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

	string temp{};  // use a string variable here because it can be empty. A char cannot
	getline(std::cin, temp); // getline() reads characters from an input stream
	if (temp == "X")
		exit(0);
	else
		firstTime();
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void client_selection()
{
	std::cout << '\n'
		<< "First time home buyer, select 1 : \n"
		<< "Current home owner, select 2 : \n\n" 
		<< "Selection: ";

	bool first_branch{ true };

	while (first_branch)
	{
		int selection{};
		std::cin >> selection;
		if (!std::cin) { ignore(); }

		switch (selection)
		{
		case 1:
			firstTimeIntro();
			selection = false;
			break;
		case 2:
			homeOwner();
			selection = false;
			break;
		default:
			std::cout << "That is not a valid entry. Please select 1 or 2 : ";
		}

		if (!std::cin.eof() && std::cin.peek()) // treats erroneous input as error 
		{
			ignore(); // remove extraneous input
			continue;
		}
	}
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void introduction()
{
	using namespace std;

	cout
		<< "Bigger Picture Products Inc.\n\n"
		<< "Welcome to HOLMES\n\n"
		<< "HOLMES is a dynamic real estate calculator that codes real estate impossibilities, into reality\n"
		<< "Holmes will turn your home ownership dreams into a boring a** reality!\n\n" 
		<< "Selection Enter to Continue : "; // and X to leave 

	string temp{};  // use a string variable here because it can be empty. A char cannot
	getline(std::cin, temp); // getline() reads characters from an input stream
	if (temp == "X")
		exit(0);
	else
		return;
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

int main()
{
	std::locale comma_locale(std::locale(), new comma());
	// tell cout to use our new locale.
	std::cout.imbue(comma_locale);

	introduction();
	client_selection();

	return 0;
}
