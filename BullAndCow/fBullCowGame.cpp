#include "fBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


	
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) 	//TODO  if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
			
	else if (!IsLowercase(Guess))//TODO if guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
		
	else if (Guess.length() != GetHiddenWordLength()) 
	{
			return EGuessStatus::Wrong_Length;
		}
		
	else
	{
		return EGuessStatus::OK;
	}

}



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	

	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();//assuming same length as guess

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			//compare letters against guess			
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar) //if they match then
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
	if (BullCowCount.Bulls == HiddenWordLength) {
		bGameIsWon = true;
		
	}
	else
	{
		bGameIsWon = false;
		
	}

	return BullCowCount;
	
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;  //set up map

	for (auto Letter : Word)  //for all letters of the word
	{
		Letter = tolower(Letter); //handle mixed case

		if (LetterSeen[Letter]) { return false; }

		else {LetterSeen[Letter] = true; }
				  			
	}
	//otherwise
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word.length() < 1) {return true;}

	TMap <char, bool> LowercaseLetter; //set up map

	for (auto Letter : Word)
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}


