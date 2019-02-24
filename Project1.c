// Project 1: Chapter 7 - #20 Theater Seating
/* Write a program that can be used by a small theater to sell tickets for performances.
• When the program begins, it should ask the user to enter the seat prices for each row.
The prices can be stored in a separate array. (Alternatively, the prices may be read
from a file.)
• Once the prices are entered, the program should display a seating chart. The user may
enter the row and seat numbers for tickets being sold. Every time a ticket or group of
tickets is purchased, the program should display the total ticket prices and update the
seating chart.
• The program should keep a total of all ticket sales. The user should be given an
option of viewing this amount.
• The program should also give the user an option to see a list of how many seats
have been sold, how many seats are available in each row, and how many seats are
available in the entire auditorium.
Input Validation: When tickets are being sold, do not accept row or seat numbers that
do not exist. When someone requests a particular seat, the program should make sure
that seat is available before it is sold. */

#include <stdio.h>
#include <string.h>

void ticketSales();
void availableSeats();
void setSeat();
void takenSeats();
void printChart();
void quit();

char chart[15][30];
double prices[15];
int tickets,
	totalTickets;
double totalMoney = 0.0;

int main()
{
	for (int row = 0; row < 15; row++)
	{
		for (int seat = 0; seat < 30; seat++)
			chart[row][seat] = '#';
	}

	printf("Enter the price for a seat in\n");
	for (int i = 0; i < 15; i++)
		{
			printf("Row %d: ", (i + 1));
			fflush(stdout); // ECLIPSE BUG
			scanf("%lf", &prices[i]);
		}

	printChart();
	ticketSales();

	return 0;
}

void ticketSales()
{
	int row,
		seat;
	char viewMoney[18],
		 viewSeats[18];

	do
	{
		printf("\nEnter ticket purchase information: \n");
		printf("Number of tickets: ");
		fflush(stdout); // ECLIPSE BUG
		scanf("%d", &tickets);
		if (tickets == 0)
			quit();
		totalTickets += tickets;

		int positions[tickets][2];
		double purchaseTotal = 0.0;

		for (int i = 0; i < tickets; i++)
		{
			do
			{
				printf("Row: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &row);
				printf("Seat: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &seat);

				for (int n = 0; n < i; n++)
				{
					if ((row - 1) == positions[n][0] && (seat - 1) == positions[n][1])
					{
						do
						{
							printf("Seat is not available! Please choose another seat.\n");
							printf("Row: ");
							fflush(stdout); // ECLIPSE BUG
							scanf("%d", &row);
							printf("Seat: ");
							fflush(stdout); // ECLIPSE BUG
							scanf("%d", &seat);
						} while ((row - 1) == positions[n][0] && (seat - 1) == positions[n][1]);
					}
				}

				if (chart[row - 1][seat - 1] == '#')
				{
					purchaseTotal += prices[row - 1];
					positions[i][0] = (row - 1);
					positions[i][1] = (seat - 1);
				}
				else
					printf("Seat is not available! Please choose another seat.\n");
				if (row < 1 || row > 15 || seat < 1 || seat > 30)
					printf("Seat is not available! Please choose another seat.\n");
			} while (chart[row - 1][seat - 1] == '*' || row < 1 || row > 15 || seat < 1 || seat > 30);
		}
		totalMoney += purchaseTotal;

		printf("Total this purchase: $%.2lf\n", purchaseTotal);
		setSeat(positions, tickets);
		if (totalTickets < 450)
			printChart();

		printf("Would you like to view the current cumulative ticket sales?\n");
		fflush(stdout); // ECLIPSE BUG
		scanf("%s", viewMoney);
		if (strcmp(viewMoney, "yes") == 0 || strcmp(viewMoney, "YES") == 0 || strcmp(viewMoney, "Yes") == 0
			|| strcmp(viewMoney, "y") == 0 || strcmp(viewMoney, "Y") == 0)
			printf("\nTotal profits from ticket sales: $%.2lf\n", totalMoney);

		printf("Would you like to view seat availability in the theater?\n");
		fflush(stdout); // ECLIPSE BUG
		scanf("%s", viewSeats);
		if (strcmp(viewSeats, "yes") == 0 || strcmp(viewSeats, "YES") == 0 || strcmp(viewSeats, "Yes") == 0
			|| strcmp(viewSeats, "y") == 0 || strcmp(viewSeats, "Y") == 0)
			availableSeats();

	} while (totalTickets < 451);
}

void availableSeats()
{
	int taken,
		unavailable;

	printf("Open seats in each row: \n");
	unavailable = 0;
	for (int row = 0; row < 15; row++)
	{
		taken = 0;
		for (int seat = 0; seat < 30; seat++)
		{
			if (chart[row][seat] == '*')
				taken ++;
		}
		printf("Row %d: %d seats\n", (row + 1), (30 - taken));
		unavailable += taken;
	}
	printf("Total open seats in theater: %d\n", (450 - unavailable));
}

void setSeat(int positions[][2], int tickets)
{
	char newSaleChart[15][30];

	for (int row = 0; row < 15; row++)
	{
		for (int seat = 0; seat < 30; seat++)
		{
			newSaleChart[row][seat] = '#';
			for (int ticket = 0; ticket < tickets; ticket++)
				newSaleChart[positions[ticket][0]][positions[ticket][1]] = '*';
		}
	}
	takenSeats(newSaleChart);
}

void takenSeats(char newSaleChart[15][30])
{
	char toUpdate[15][30];

	for (int row = 0; row < 15; row++)
	{
		for (int seat = 0; seat < 30; seat++)
		{
			toUpdate[row][seat] = '#';
			if (toUpdate[row][seat] != newSaleChart[row][seat])
				chart[row][seat] = '*';
		}
	}
}

void printChart()
{
	printf("\nCurrent available seats for theater: \n");
	printf("(#) seats are available \n(*) seats are taken\n\t\tSeats\n       ");
	for (int i = 1; i < 4; i++)
	{
		for (int i = 1; i < 10; i++)
			printf("%d", i);
		printf("0");
	}
	printf("\n");
	for (int row = 0; row < 15; row++)
	{
		printf("Row %d", (row + 1));
		if (row < 9)
			printf(" ");
		printf(" ");
		for (int seat = 0; seat < 30; seat++)
			printf("%c", chart[row][seat]);
		printf("\n");
	}
}

void quit()
{
	printf("Thank you for using Theater Seating Logger!\n");
	totalTickets = 451;
}
