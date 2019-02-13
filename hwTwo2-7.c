// Chapter 2 - #7 Ocean Levels
/* Assuming the ocean’s level is currently rising at about 1.5 millimeters per year, write
a program that displays the number of millimeters higher than the current level that the ocean’s level will be
in 5 years, 7 years, and 10 years. */

#include <stdio.h>

int main()
{
	const double CURRENT = 0.0;
	const double RISE_RATE = 1.5;

	printf("In 5 years, the ocean level will be higher by %.2f mm\n", (CURRENT + (RISE_RATE * 5)));
	printf("In 7 years, the ocean level will be higher by %.2f mm\n", (CURRENT + (RISE_RATE * 7)));
	printf("In 10 years, the ocean level will be higher by %.2f mm\n", (CURRENT + (RISE_RATE * 10)));

	return 0;
}
