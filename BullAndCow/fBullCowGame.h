#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

class FBullCowGame 
{
public:

	FBullCowGame(); //constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool CheckGuessValidity(FString) const;
	bool IsGameWon() const;


	void Reset(); 

	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;  
	int32 MyMaxTries;
	FString MyHiddenWord;
	// provide a method for counting bulls and cows, and incrementing turn #
};