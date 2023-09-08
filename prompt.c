#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints a line from user to the screen
 * @ac: The number of items in av
 * @av: An array of strings
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;

	(void)ac; (void)av;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);

	free(lineptr);
}
