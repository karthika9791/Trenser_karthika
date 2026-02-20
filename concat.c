#include "main.h"
void conCatenate(char *input)
{
	char concat_str[100];
	int index1= 0,index2=0;
	
	printf("Enter string to be added\n");
	scanf("%99[^\n]",concat_str);

	while(input[index1] != '\0')
		index1++;
	while(concat_str[index2] != '\0')
	{
		input[index1] = concat_str[index2];
		index1++;
		index2++;
	}
	input[index1] = '\0';
	
}
