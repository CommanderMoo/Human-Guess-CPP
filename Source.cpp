
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	//sets grid to be 8x8
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	//set to search between 1 & 64
	int actualTargetLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	//system attempt counter
	int tries = 0;
	//system target start point
	int attemptToLocateTarget = 0;
	//title
	cout << "\t Welcome to Guess My Number \n\n";
	do
	{
		//target location
		cout << "\n The real target location is at " << actualTargetLocation << endl;
		//systems guessing system
		cout << "\n The AI guesses target is at location " << attemptToLocateTarget << endl;
			attemptToLocateTarget = (searchGridHighNumber - searchGridLowNumber) / 2 + searchGridLowNumber;
		++tries;
		//if guess is too high
		if (attemptToLocateTarget > actualTargetLocation)
		{
			cout << "The AI target prediction was Too high! \n\n";
			searchGridHighNumber = attemptToLocateTarget - 1;
		}
		//if guess is too low
		else if (attemptToLocateTarget < actualTargetLocation)
		{
			cout << "The AI target prediction was Too low! \n\n";
			searchGridLowNumber = attemptToLocateTarget + 1;
		}
		//if guess is correct
		else
		{
			cout << "\n That's it! You got it in " << tries << " guesses! \n";
		}
	//if correct move on
	} while (attemptToLocateTarget != actualTargetLocation);
	//return display
	return 0;
}