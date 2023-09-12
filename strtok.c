#include <stdio.h>
#include <string.h>

/**
 * main - splits a string
 *
 * Return: An array of each word of the string
 */
int main(void)
{
	char *token;
	char str[] = "Hello world from C";
	char *delim = " ";

	token = strtok(str, delim);

	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
