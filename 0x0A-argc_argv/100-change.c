#include <stdio.h>
#include <stdlib.h>

/**
 * main - change
 * @argc: args count
 * @argv: args
 * Return: integer
 */

int main(int argc, char *argv[])
{
	int coins, cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	coins = 0;
	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
	}
	coins = coins + cents / 25;
	cents = cents % 25;

	coins = coins + cents / 10;
	cents = cents % 10;

	coins = coins + cents / 5;
	cents = cents % 5;

	coins = coins + cents / 2;
	cents = cents % 2;

	coins = coins + cents;

	printf("%d\n", coins);

	return (0);
}
