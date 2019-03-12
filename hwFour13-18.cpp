// HW FOUR: Chapter 13 Programming Challenge #18  A Game of 21 Pg 809
/* For this assignment, you will write a program that lets the user play against the computer
in a variation of the popular blackjack card game where two six-sided dice are used instead of cards.
The dice are rolled, and the player tries to beat the computer’s hidden total without going over 21. */


#include "stdafx.h"
#include "Die.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string again, hit;
	int pTotal = 0, cTotal = 0;	
	bool pLose = false;	


	cout << "Rolling dice...\n";
	Die Game21;

	/* At the beginning of each round, the program will ask the users whether they want
	to roll the dice to accumulate points. */
	cout << "Would you like to roll dice for points in a game of 21? ";
	cin >> again;
	cin.ignore();

	while (again == "y" || again == "Y" || again == "YES" || again == "yes" || again == "Yes")
	{
		/* During each round, the program simulates the rolling of two six - sided dice. It rolls
		the dice first for the computer, and then it asks the user if he or she wants to roll. */
		Game21.roll();
		cTotal += Game21.getValue();
		Game21.roll();
		cTotal += Game21.getValue();
		Game21.roll();
		cTotal += Game21.getValue();
		cout << "The computer has rolled. Would you like to roll the two dice? ";
		cin >> hit;
		cin.ignore();
		while (hit == "y" || hit == "Y" || hit == "YES" || hit == "yes" || hit == "Yes")
		{
			Game21.roll();
			pTotal += Game21.getValue();
			Game21.roll();
			pTotal += Game21.getValue();
			cout << "You currently have " << pTotal << " points. ";

			/* Each round of the game is performed as an iteration of a loop that repeats as long
			as the player agrees to roll the dice, and the player’s total does not exceed 21. */
			if (pTotal > 21)
			{
				cout << "\nYou are over 21, you lose\n";
				pLose = true;
				pTotal = 0;
				cTotal = 0;
				break;
			}
			cout << "Roll again? ";
			cin >> hit;
		}

		/* The loop keeps a running total of both the computer and the user’s points.
		The computer’s total should remain hidden until the loop has finished.
		After the loop has finished, the computer’s total is revealed, and the player with the
		most points without going over 21 wins. */
		if (!pLose && (pTotal > cTotal) && (cTotal <= 21) || (!pLose && (cTotal > 21)))
		{
			cout << "\tYou won!\n";
			cout << "The computer had: " << cTotal << " points\n";
			pTotal = 0;
			cTotal = 0;
		}
		else if ((cTotal <= 21) && (cTotal > pTotal) && !pLose)
		{
			cout << "\nYou lose\n";
			cout << "The computer had " << cTotal << " points\n";
			pTotal = 0;
			cTotal = 0;
		}
		else if (cTotal <= 21 && !pLose && cTotal == pTotal)
		{
			cout << "It's a tie!\n";
			cout << "The computer had: " << cTotal << " points\n";
			pTotal = 0;
			cTotal = 0;
		}

		cout << "Play again? ";
		cin >> again;
		cin.ignore();
	} 

	return 0;
}