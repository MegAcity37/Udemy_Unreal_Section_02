/*  This is the console executable which makes use of the BullCow class.  This acts as the view in a MVC pattern,
and is responsible for all user interaction.  For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "fBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetGuess();
bool AskPlayAgain();

FBullCowGame BCGame; //instantiate a new game



//the entry point for our application

int main()
{

	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskPlayAgain();
	} while (bPlayAgain);

	return 0; //exit the application
}

void PrintIntro()
{
	//introduce the game
	constexpr int32 WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	//play the game
	
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for # of turns asking for guesses
	//TODO change from FOR to WHILE loop once we are validating tries
	
	for (int32 count = 1; count <= MaxTries; count++)
	{
		Ftext Guess = GetGuess();   //TODO make loop checking valid

		//submit valid guess to the game
		 //print number of bulls and cows
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;

	}
	//TODO add a game summary
}


Ftext GetGuess()
{
	//get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	Ftext Guess = "";

	std::cout << "Enter your guess: ";
	
	std::getline(std::cin, Guess);
	std::cout << "Try " << CurrentTry;
	std::cout << std::endl;

	return Guess;
}

bool AskPlayAgain()

{
	std::cout << "Do you want to play again? y/n ";
	Ftext Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');

}