// Chapter 5 - #23 Pattern Displays

#include <stdio.h>

int main()
{
    printf("Pattern A:\n");
    for (int i = 1; i <+ 10; i++)
    {
    	for (int j = 0; j < i; j++)
    	{
    		printf("+");
    	}
        printf("\n");
    }

    printf("\nPattern B:\n");
    for (int i = 10; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("+");
        }
        printf("\n");
    }
    return 0;
}
