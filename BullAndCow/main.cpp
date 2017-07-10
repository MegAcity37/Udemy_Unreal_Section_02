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
Ftext GetValidGuess();
bool AskPlayAgain();
void PrintGameSummary();

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

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	//play the game

	int32 bMaxTries = BCGame.GetMaxTries();

	//loop for # of guesses while the game is not won and there are still tries remaining
	//TODO change from FOR to WHILE loop once we are validating tries

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= bMaxTries) 
	{
		Ftext Guess = GetValidGuess();   
		
		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	//TODO add a game summary
	return;
}


Ftext GetValidGuess()  //TODO loop until user gives a valid guess
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	Ftext Guess = "";

	do {//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << "\nEnter your guess: ";
		std::cout << std::endl;

		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.  (An isogram is a word with no repeating letters.)\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your word in lowercase. \n\n";
			break;
		default:
			return Guess; //assume guess is valid
		}
	} while (Status != EGuessStatus::OK); //keep looping until we get no error}
	return Guess;
}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "Congratulations!  You guessed the isogram! \n";
	}
	else 
	{
		std::cout << "Too bad, you didn't guess the isogram this time. \n";
	}
	
}

bool AskPlayAgain()

{
	std::cout << "Do you want to play again? y/n ";
	Ftext Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');

}