// Chapter 9 - #10  Reverse Array
/* Write a function that accepts an int array and the array’s size as arguments. The function
should create a copy of the array, except that the element values should be reversed in the
copy. The function should return a pointer to the new array. Demonstrate the function in a
complete program. */

#include <stdio.h>

void reverse(int[], int);

int main()
{
	int arraySize;

	printf("enter a size for the array: ");
	fflush(stdout); // ECLIPSE BUG
	scanf("%d", &arraySize);

	int array[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		printf("enter data for array at index %d: ", (i + 1));
		fflush(stdout); // ECLIPSE BUG
		scanf("%d", &array[i]);
	}

	printf("Your array before reversed is: \n");
	for (int i = 0; i < arraySize; i++)
		printf("%d ", array[i]);

	reverse(array, arraySize);

	return 0;
}

void reverse(int array[], int size)
{
	int reverseArray[size];

	for (int i = 0; i < size; i++)
		reverseArray[i] = array[size - (i + 1)];

	printf("\nYour reversed array is: \n");
	for (int i = 0; i < size; i++)
		printf("%d ", reverseArray[i]);
}
