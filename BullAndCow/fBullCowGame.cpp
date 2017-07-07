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
	const FString HIDDEN_WORD = "ant";

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//receives a valid guess, increments try number, and returns count
	MyCurrentTry++;

	//set up a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	


	//loop through all letters in the guess
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			//compare letters against hidden word
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;  //increment bulls if they're in the same place
				}
				else
				{
					BullCowCount.Cows++;  //increment cows if not
				}

			}
		}

	}
	
	return BullCowCount;
	
}


