//	userVerify.cpp asks the user to answer yes or no, providing boolean data to the program.
//	also filters out nonsense answers, asking again for 'yes' or 'no'.


#include "stdafx.h"
#include <iostream>
#include <string>

#include "io.h"



Response userVerify(std::string question = "Let's try this again...")
{
	using std::cout;
	std::string userInput;
//	bool isYes{ 0 };		//make this an enum class -- like a 3-position boolean! woo!
//	bool isInvalid{ 1 };	//replace w enum class

	Response userAnswer{ Response::INVALID };	//Response enumeration is our programmer-created data type
	while (userAnswer == Response::INVALID)		//INVALID is in namespace Response because of `enum class` code
	{
		cout << "Please answer 'yes' or 'no'. \n";
		std::getline(std::cin, userInput);
		if (userInput == "yes" || userInput == "y" || userInput == "Y" || userInput == "YES" || userInput == "Yes")
		{
			userAnswer = Response::YES;			
			cout << "Confirmed. \n";
		}
		else if (userInput == "no" || userInput == "n" || userInput == "N" || userInput == "NO" || userInput == "No")
		{
			userAnswer = Response::NO;
			cout << "No?\n";
		}
		else
		{
			userAnswer = Response::INVALID;
			cout << "Look. I'm just doing my best here. Work with me, okay?\n";
			cout << question << "\n";
		}
	}
	return userAnswer;
}
