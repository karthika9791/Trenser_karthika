#include "main.h"
int main()
{
	char input[100];
	int option;
	printf("Enter string\n");
	scanf("%99[^\n]",input);
	printf("1. Uppercase-Lowercase\n2. Lowercase-Uppercase\n3. Concatenate\n");
	scanf("%d ",&option);
	switch(option)
	{
		case 1:
			upperLower(input);
			break;
		case 2:
			lowerUpper(input);
			break;
		case 3:
			conCatenate(input);
			break;
		default:
			printf("Invalid input\n");
			break;
	}
	puts(input);
}
