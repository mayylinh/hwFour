//	Chapter 6 - #16 Population
/* In a population, the birth rate is the percentage increase of the population due to births,
and the death rate is the percentage decrease of the population due to deaths. Write a
program that displays the size of a population for any number of years. The program
should ask for the following data:
• The starting size of a population
• The annual birth rate
• The annual death rate
• The number of years to display
Write a function that calculates the size of the population for a year. The formula is
N = P + BP - DP
Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
negative numbers for birth rate or death rate. Do not accept numbers less than 1 for
the number of years. */

#include <stdio.h>

void populationSize(int, int, int, int);

int main()
{
	int initialPop,
		birthRate,
		deathRate,
		years;

	printf("enter the starting size of the population: ");
	fflush(stdout); // ECLIPSE BUG
	scanf("%d", &initialPop);
	while (initialPop < 2)
	{
		printf("Invalid population size! \nEnter size greater than 2: ");
		fflush(stdout); // ECLIPSE BUG
		scanf("%d", &initialPop);
	}

	printf("enter the annual birth rate of the population: ");
	fflush(stdout); // ECLIPSE BUG
	scanf("%d", &birthRate);
	while (birthRate < 0)
	{
		printf("Invalid annual birth rate! \nEnter again: ");
		fflush(stdout); // ECLIPSE BUG
		scanf("%d", &birthRate);
	}

	printf("enter the annual death rate of the population: ");
	fflush(stdout); // ECLIPSE BUG
	scanf("%d", &deathRate);
	while (deathRate < 0)
	{
		printf("Invalid annual death rate! \nEnter again: ");
		fflush(stdout); // ECLIPSE BUG
		scanf("%d", &deathRate);
	}

	printf("enter the number of years to display: ");
	fflush(stdout); // ECLIPSE BUG
	scanf("%d", &years);
	while (years < 1)
	{
		printf("Invalid number of years! \nEnter amount greater than 0: ");
		fflush(stdout); // ECLIPSE BUG
		scanf("%d", &years);

	}

	populationSize(initialPop, birthRate, deathRate, years);

	return 0;
}

void populationSize(int P, int B, int D, int Y)
{
	for (int i = 1; i <= Y; i++)
	{
		int newPop = P + (B * P) - (D * P);
		printf("After %d years: The size of this population will be %d\n", i, newPop);
		P = newPop;
	}
}
