// Chapter 4 - #23 Geometry Calculator
/* If the user enters 1, the program should ask for the radius of the circle and then display
its area. Use the following formula:
area  p r 2 Use 3.14159 for p and the radius of the circle for r .
If the user enters 2, the program should ask for the length and width of the rectangle and then
display the rectangle’s area. Use the following formula: area = length * width
If the user enters 3 the program should ask for the length of the triangle’s base and its
height, and then display its area. Use the following formula: area = base * height * .5
If the user enters 4, the program should end.
Input Validation: Display an error message if the user enters a number outside the range
of 1 through 4 when selecting an item from the menu. Do not accept negative values
for the circle’s radius, the rectangle’s length or width, or the triangle’s base or height. */

#include <stdio.h>
#include <math.h>

int main()
{
	const double PI = 3.14159;
	int choice;
	int r, l, w, b, h;

	do
	{
		printf("Geometry Calculator\n");
		printf("1. Calculate the Area of a Circle\n");
		printf("2. Calculate the Area of a Rectangle\n");
		printf("3. Calculate the Area of a Triangle\n");
		printf("4. Quit\n");

		printf("Enter your choice (1-4): ");
    	fflush(stdout);
    	scanf("%d", &choice);

    	while (choice < 1 || choice > 4)
    	{
    		printf("Invalid choice! Enter your choice again: ");
    		fflush(stdout);
    		scanf("%d", &choice);
    	}

    	switch (choice)
    	{
			case 1:
				printf("enter radius of circle: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &r);
				while (r < 0)
				{
					printf("Invalid value! Enter r again: ");
					fflush(stdout);
					scanf("%d", &r);
				}
				double cArea = PI * pow(r,2);
				printf("area of circle is: %.2f\n\n", cArea);
				break;
			case 2:
				printf("enter length of rectangle: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &l);
				while (l < 0)
				{
					printf("Invalid value! Enter length again: ");
					fflush(stdout);
					scanf("%d", &l);
				}
				printf("enter width of rectangle: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &w);
				while (w < 0)
				{
					printf("Invalid value! Enter width again: ");
					fflush(stdout);
					scanf("%d", &w);
				}
				int rArea = l * w;
				printf("area of rectangle is: %d\n\n", rArea);
				break;
			case 3:
				printf("enter base of triangle: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &b);
				while (b < 0)
				{
					printf("Invalid value! Enter base again: ");
					fflush(stdout);
					scanf("%d", &b);
				}
				printf("enter height of triangle: ");
				fflush(stdout); // ECLIPSE BUG
				scanf("%d", &h);
				while (h < 0)
				{
					printf("Invalid value! Enter height again: ");
					fflush(stdout);
					scanf("%d", &h);
				}
				double tArea = b * h * 0.5;
				printf("area of triangle is: %.2f\n\n", tArea);
				break;
			case 4:
				printf("Thank you for using Geometry Calculator. \nProgram exiting.");
    	}
    } while (choice == 1 || choice == 2 || choice == 3);

	return 0;
}
