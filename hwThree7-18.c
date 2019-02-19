// Chapter 7 - #18  Tic-Tac-Toe Game
/* Write a program that allows two players to play a game of tic-tac-toe. Use a two-dimensional
char array with three rows and three columns as the game board. Each element of the array
should be initialized with an asterisk (*). The program should run a loop that
• Displays the contents of the board array
• Allows player 1 to select a location on the board for an X. The program should ask
the user to enter the row and column number.
• Allows player 2 to select a location on the board for an O. The program should ask
the user to enter the row and column number.
• Determines whether a player has won, or a tie has occurred. If a player has won,
the program should declare that player the winner and end. If a tie has occurred, the
program should say so and end. */

#include <stdio.h>
#include <stdbool.h>

void determineWinner();

int main()
{
	char board[3][3] = {'*', '*', '*',
						'*', '*', '*',
						'*', '*', '*'};
	int turns = 3,
		row,
		col;

	printf("Playing Tic-Tac-Toe Game \nHere is the current board: \n");
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
			printf("%c ", board[row][col]);
		printf("\n");
	}
	while (((turns % 2) == 1) && (turns < 11))
	{
		printf("Player 1, enter a row number and column number: ");
		fflush(stdout); // ECLIPSE BUG
		scanf("%d %d", &row, &col);
		board[row - 1][col - 1] = 'X';
		turns++;

		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
				printf("%c ", board[row][col]);
			printf("\n");
		}
		determineWinner(board, turns);

		while ((turns % 2) == 0)
		{
			printf("Player 2, enter a row number and column number: ");
			fflush(stdout); // ECLIPSE BUG
			scanf("%d %d", &row, &col);
			board[row - 1][col - 1] = 'O';
			turns++;

			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
					printf("%c ", board[row][col]);
				printf("\n");
			}
			determineWinner(board, turns);
		}
	}
	printf("Player 1, enter a row number and column number: ");
	fflush(stdout); // ECLIPSE BUG
	scanf("%d %d", &row, &col);
	board[row - 1][col - 1] = 'X';

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		printf("%c ", board[row][col]);
		printf("\n");
		determineWinner(board, turns);
	}
	determineWinner(board, turns);

	return 0;
}

void determineWinner(char board[3][3], int turn)
{
	bool winner = false;
	char player;

	for (int row = 0; row < 3; row++)
	{
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2]
			&& board[row][0] != '*')
		{
			winner = true;
			player = board[row][0];
		}
	}
	for (int col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] && board[1][col] == board[2][col]
			&& board[0][col] != '*')
		{
			winner = true;
			player = board[0][col];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != '*')
	{
		winner = true;
		player = board[0][0];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2]
		&& board[2][0] != '*')
	{
		winner = true;
		player = board[2][0];
	}
	if (winner == true)
	{
		if (player == 'X')
			printf("Player 1 is the winner!");
		else
			printf("Player 2 is the winner!");
	}
	if (winner == false && turn == 12)
		printf("The game has ended in a tie! \nThere are no winners.");
}
