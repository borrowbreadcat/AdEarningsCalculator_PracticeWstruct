// 20181001AdvertisingIncome_learncppquiz4_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "io.h"

void splash()
{
	using std::cout;

	cout << "This program exists as a practice exercise as I learn C++. \n";
	cout << "It is a response to learncpp.com section 4.7 quiz exercise 1 \n";
	cout << "1) You are running a website, and you are trying to keep track of how much money you make per\n";
	cout << "day from advertising. Declare an advertising struct that keeps track of how many ads you’ve\n";
	cout << "shown to readers, what percentage of ads were clicked on by users, and how much you earned on \n";
	cout << "average from each ad that was clicked. Read in values for each of these fields from the user. Pass\n";
	cout << "the advertising struct to a function that prints each of the values, and then calculates how much \n";
	cout << "you made for that day(multiply all 3 fields together).\n";
	cout << "\n\tVERSION HISTORY\n";
	cout << "\tver20181005: fully functioning\n";
	cout << "\tver20181002: create struct\n";
	cout << "\tver20181001: creation\n\n";
}

struct Advertise
{
	int viewed{ 0 };
	double clickPercent{ 0 };
	double avgEarningPerClick{ 0 };
};

//ask the user to name the ad we will be working with
std::string whichAd()
{
	using std::string;

	string adName{ "default" };
	
	Response adIsNamed{ Response::INVALID };
	while (adIsNamed == Response::NO || adIsNamed == Response::INVALID)
	{
		std::cout << "Which advertisement would you like to audit?\n";
		std::cout << "Type in the name of the ad (really, just make it up. Humor me.)\n";
		std::getline(std::cin, adName);	//avoids issues cin otherwise takes with whitespace
		std::cout << "You want to audit the advertisement named " << adName << "? \n";
		std::string verificationQuestion{ "Is '" + adName + "' the name of the ad you want to audit?\n" };
		adIsNamed = userVerify(verificationQuestion);
	}
	
	return adName;
}


void printAdData(Advertise printme)
{
	using std::cout;
	cout << "Number of times the ad was viewed: \t " << printme.viewed << " \t\tviews \n";
	cout << "% of those views led to a click:   \t " << printme.clickPercent << "% \t\tviews clicked\n";
	cout << "average earnings per click:        \t $" << printme.avgEarningPerClick << " \t\tper click \n\n";
}


Advertise userInput(std::string adName)
{
	using std::cout;
	cout << "Great!  Now let's talk about the data for the " << adName << " ad...\n";
	Advertise currentAd;

	Response dataIsCorrect{ Response::INVALID };
	while (dataIsCorrect == Response::INVALID || dataIsCorrect == Response::NO)
	{
		cout << "How many times was the advertisement viewed by a person? \n";
		std::cin >> currentAd.viewed;
		cout << "\nWhat percentage of those ads were clicked?\n";
		std::cin >> currentAd.clickPercent;
		cout << "\nOn average, how much money did we earn per click?\n";
		std::cin >> currentAd.avgEarningPerClick;
		std::cin.ignore(32767, '\n');
		cout << "Here are the data you've provided: \n";
		printAdData(currentAd);
		cout << "Are these data correct? \n";
		dataIsCorrect = userVerify("Are these data correct?\n");
	}

	return currentAd;
}

double solveEarnings(Advertise ad)
{
	double earnings{ 0.0 };
	earnings = static_cast<double>(ad.viewed) * (ad.clickPercent)/100 * ad.avgEarningPerClick;
	return earnings;
}

int main()
{
	splash();

	Response repeat{ Response::NO };
	do
	{
		std::cout << "Average earnings for your ad were $" << solveEarnings(userInput(whichAd())) << "\n";
		std::cout << "Would you like to audit another advertisement? \n";
		repeat = userVerify("Do you want to audit another ad?");
	} while (repeat == Response::YES);

	std::cout << "Hope it was helpful!  See you soon!\n";
	return 0;
}

