#include "fBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

bool FBullCowGame::IsGameWon() const { return false;}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 5;

	return;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//receives a valid guess, increments try number, and returns count
	MyCurrentTry++;
	
	//set up a return variable
	BullCowCount BullCowCount;
	
	//loop through all letters in the guess
		//compare letters against hidden word
	return BullCowCount;  
}


