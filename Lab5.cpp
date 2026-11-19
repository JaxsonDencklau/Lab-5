/*
Jaxson Dencklau
Computer Science 
11/10/2026
Lab5 guessing game

This program is a guessing game where the user has to guess a random number between 1 and 100. 
The user can choose how many guesses they want to have, and the program will give them feedback on whether their guess is too high or too low.
The program keeps track of the number of wins and losses, and prompts the user to play again after each game.

*/
#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

int again; 
int guesstimes;
int guess;
int number;
int wins = 0;
int losses = 0;


//Precondition: None
//Postcondition: Displays the rules of the game to the user
void startgame();

//Precondition: the user has made a guess and the guess is higher than the random number
//Postcondition: Displays a message to the user that their guess was too high
void highguess(int guess);

//Precondition: the user has made a guess and the guess is lower than the random number
//Postcondition: Displays a message to the user that their guess was too low
void lowguess(int guess);

//Precondition: The user has won or lost the game, or is starting a new game
//Postcondition: Resets the random number and the amount of guesses the user has
void startgame();

//Precondition: The user has won or lost the game, or is starting a new game
//Postcondition: Resets the random number and the amount of guesses the user has
void reset();

//Precondition: The user has made a guess
//Postcondition: Displays a prompt to the user to enter a new guess
void newguess();

//Precondition: The user has won the game
//Postcondition: Displays a message to the user that they have won the game
void winner();

//Precondition: The user has lost the game
//Postcondition: Displays a message to the user that they have lost the game
void loser();

//Precondition: The user has exited the game
//Postcondition: Displays a message to the user that they have exited the game
void closing();

//Precondition: The user has won or lost the game
//Postcondition: Displays a message to the user that they have won or lost the game and prompts them to play again
void playagain();

int main()
{  
	// The random number generator
    srand(time(NULL));
	// Start the game
    startgame();
    do
    {
		// Reset the game after every win and loss, also the start of the game.
        reset();
        do
        {
			//Gives a prompt for each guess.
            newguess();
            if (guess < number && guess >= 1 && guess <= 100)
            {
                lowguess(guess);
            }
            else if (guess > number && guess <= 100 && guess >= 1)
            {
                highguess(guess);
            }
			else if (guess > 100 || guess < 1)
			{
				cout << "Please enter a number between 1 and 100." << endl;
			}
			else
			{
				winner();
			}
        } while (guess != number && guesstimes > 0);
        if (guesstimes == 0)
        {
            loser();
        }
        playagain();
    } while (again == 1);
	if (again == 0)
	{
        closing();
	}
    return 0;
}

void lowguess(int guess)
{
	//subtracts the amount of guesses
    guesstimes--;
    cout << guesstimes << " guesses left.\n" << endl;
    cout << "\n" <<  guess <<" is too low! ";
    return;
}


void highguess(int guess)
{
	//subtracts the amount of guesses you have left
	guesstimes--;
	cout << guesstimes << " guesses left.\n" << endl;
	cout << "\n" << guess << " is too high! ";
    return;
}
//displays the rules of the game to the user
void startgame()
{
	cout << "You have 20 attempts to guess the number between 1 and 100." << endl;
	cout << "If you guess the number correctly, you win!" << endl;
	cout << "If you run out of guesses, you lose!" << endl;
}

void reset()
{
	//resets the random number from 1-100 after a win/loss
	number = rand() % 100 + 1;
	//gives a prompt and lets you enter amunt of guesses
	cout << "How many guesses would you like to have? (1-20): ";
	cin >> guesstimes;
	//if the number isn't between 1 and 20 the message will dispplay
	while (guesstimes < 1 || guesstimes > 20)
	{
		cout << "Please enter a number between 1 and 20." << endl;
		cin >> guesstimes;
	}
}

void newguess()
{
	//ask what the new guess is after every attempt
	cout << "What is your guess? ";
	cin >> guess;
}

//displays a message from one of the options and adds a win to the counter
void winner()
{
	switch (rand() % 10 + 1)
	{
	case 1:
		cout << "You did it! You guessed the number!" << endl;
		break;
	case 2:
		cout << "Great job! You guessed the number!" << endl;
		break;
	case 3:
		cout << "Congratulations! You guessed the number!" << endl;
		break;
	case 4:
		cout << "Awesome! You guessed the number!" << endl;
		break;
	case 5:
		cout << "Fantastic! You guessed the number!" << endl;
		break;
	case 6:
		cout << "You are a genius! You guessed the number!" << endl;
		break;
	case 7:
		cout << "Wow! You guessed the number!" << endl;
		break;
	case 8:
		cout << "Incredible! You guessed the number!" << endl;
		break;
	case 9:
		cout << "Amazing! You guessed the number!" << endl;
		break;
	case 10:
		cout << "You are a master! You guessed the number!" << endl;
		break;
	}
	wins++;
}

//displays a message from one of the options and adds a loss to the counter
void loser()
{
	switch (rand() % 10 + 1)
	{
	case 1:
		cout << "You ran out of guesses! The number was " << number << "." << endl;
		break;
	case 2:
		cout << "Better luck nect time! The number was " << number << "." << endl;	
		break;
	case 3:
		cout << "No more guesses. The number was " << number << "." << endl;		
		break;
	case 4:
		cout << "You lose. The number was " << number << "." << endl;
		break;
	case 5:
		cout << "Maybe next time. The number was " << number << "." << endl;
		break;
	case 6:
		cout << "Unfortunate. The number was " << number << "." << endl;
		break;
	case 7:
		cout << "Your guesses are gone. The number was " << number << "." << endl;
		break;
	case 8:
		cout << "Loser. The number was " << number << "." << endl;
		break;
	case 9:
		cout << "Not even close. The number was " << number << "." << endl;
		break;
	case 10:
		cout << "Yikes. The number was " << number << "." << endl;
		break;
	}
	losses++;
}
//displays a message from one of the options and displays the total wins and losses
void closing()
{
	switch(rand() % 10 + 1)
    {
	case 1:
		cout << "Goodbye!" << endl;
		break;
	case 2:
		cout << "See you next time!" << endl;
		break;
	case 3:
		cout << "Have a great day!" << endl;
        break;
    case 4:
		cout << "Come back soon!" << endl;
		break;
	case 5:
		cout << "Hope you had fun!" << endl;
		break;
	case 6:
		cout << "Until next time!" << endl;
		break;
	case 7:
		cout << "Take care!" << endl;
		break;
	case 8:
		cout << "See you later!" << endl;
		break;
	case 9:
		cout << "Have a good one!" << endl;
		break;
	case 10:
		cout << "Thanks for playing!" << endl;
		break;
    }
    cout << "Total wins: " << wins << endl;
    cout << "Total losses: " << losses << endl;
}
// Displays a message from one of the options and prompts the user to play again
// If the user enters a number other than 1 or 0, it will prompt them to enter a valid number for playing again
void playagain()
{
	switch (rand() % 10 + 1)
	{
	case 1:
		cout << "Would you like to play again?" << endl;
		break;
	case 2:
		cout << "Do you want to try again?" << endl;
		break;
	case 3:
		cout << "Would you like to play another round?" << endl;
		break;
	case 4:
		cout << "Do you want to test your luck again?" << endl;
		break;
	case 5:
		cout << "You just got lucky. How about you try again?" << endl;
		break;
	case 6:
		cout << "Do you want to play another round?" << endl;
		break;
	case 7:
		cout << "How about giving it another shot?" << endl;
		break;
	case 8:
		cout << "Do you dare to try again?" << endl;
		break;
	case 9:
		cout << "Do you think you can keep going?" << endl;
		break;
	case 10:
		cout << "Will you play agin?" << endl;
		break;
	}
	cout << "(1 for yes, 0 for no)" << endl;
	cin >> again;
	if (again != 1 && again != 0)
	{
		do
		{
			cout << "Please enter 1 for yes or 0 for no." << endl;
			cin >> again;
		} while (again != 1 && again != 0);
	}
}   