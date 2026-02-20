#include "main.h"
void lowerUpper(char *input)
{
	int index = 0;
	while(input[index] != '\0')
	{
		if(input[index] >= 'a' && input[index] <= 'z')
		{
			input[index] -= 32;
		}
		index++;
		
	}
	puts(input);
}
