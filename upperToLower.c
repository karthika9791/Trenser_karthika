#include "main.h"
void upperLower(char *input)
{
	int index = 0;
	while(input[index] != '\0')
	{
		if(input[index] >= 'A' && input[index] <= 'Z')
		{
			input[index] += 32;
		}
		index++;
	}
	printf("%s",input);
}
