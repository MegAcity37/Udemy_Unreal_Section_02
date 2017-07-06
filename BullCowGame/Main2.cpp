#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskPlayAgain();

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
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << endl;
	return;
}

void PlayGame()
{
	//play the game

	//loop for # of turns asking for guesses
	constexpr int NUMBER_TRIES = 5;
	for (int count = 1; count <= NUMBER_TRIES; count++)
	{
		GetGuess();
	}
}


string GetGuess()
{
	//get a guess from the player

	std::cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	std::cout << "Your guess was: " << Guess;
	std::cout << endl;
	
	return Guess;
}

bool AskPlayAgain()

{
	std::cout << "Do you want to play again? y/n";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}