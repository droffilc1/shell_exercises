#include <stdio.h>

/**
 * main - prints all arguments
 * @ac: The number of items in av
 * @av: A NULL terminated array of strings
 *
 * Return: Always 0
 */
 int main(int ac, char **av)
{
	while (*av != NULL)
		printf("%s", *av++);

	return (0);
}
