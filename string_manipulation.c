//*********************** PROJECT String Manipulation ************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File    : string_manipulation.c
// Summary : File which contains string manipualtion functions
// Note    : Nil
// Author  : Karthika V T
// Date    : 20-02-2026
// 
//******************************************************************************

//******************************* Include Files ********************************
#include "main.h"

//***************************** Local Constants ********************************
#define MAX_STR_SIZE     (100)
#define MIN_UPPER_CASE   ('A')
#define MAX_UPPER_CASE   ('Z')
#define MIN_LOW_CASE     ('a')
#define MAX_LOW_CASE     ('z')
#define UPPER_LOWER_DIFF (32)
typedef enum{
	UPPER_TO_LOWER = 1,
	LOWER_TO_UPPER,
	CONCAT,
	EXIT
}Option;

//***************************** Local Variables ********************************
//static uint16_t unInpOption = 0;
Option unInpOption;
static uint16_t unStrIndex = 0;
static uint8_t ucInpStr[MAX_STR_SIZE];
static uint8_t ucCatStr[MAX_STR_SIZE];
static uint16_t unCatStrIndex = 0;


//****************************** Local Functions *******************************
static bool strMnpUpperLower();
static bool strMnpLowerUpper();
static bool strMnpConcatenate();

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : Contains fucntions for string manipulation
//Inputs  : Nil
//Outputs : Nil
//Return  : returns 0 
//Notes   : Nil
//****************************************************************************** 
bool strMnpCaller()
{

    do
    {
        printf("Enter the operation to be performed\n");
        printf("1. Uppercase-Lowercase\n2. Lowercase-Uppercase\n");
        printf("3. Concatenate\n4. Exit\n");
        scanf("%d",&unInpOption);

        switch(unInpOption)
	    {
		    case UPPER_TO_LOWER:
			    strMnpUpperLower();
			    break;
		    case LOWER_TO_UPPER:
			    strMnpLowerUpper();
			    break;
		    case CONCAT:
			    strMnpConcatenate();
			    break;
            case EXIT:
                printf("Program exits\n");
                break;
		    default:
			    printf("Invalid input\n");
			    break;
	    }

    }
    while(unInpOption != EXIT);

	return true;
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : converts uppercase charachters to lowercase
//Inputs  : Nil
//Outputs : user input string is converted to lowercase 
//Return  : returns true 
//Notes   : checks if the char in the string is uppercase then it is added to 
//          get the corresponding lowercase char
//******************************************************************************
static bool strMnpUpperLower()
{
    printf("Enter the string\n");
    scanf(" %[^\n]",ucInpStr);
    unStrIndex = 0;
	while(ucInpStr[unStrIndex] != '\0')
	{
		if(ucInpStr[unStrIndex] >= MIN_UPPER_CASE && 
            ucInpStr[unStrIndex] <= MAX_UPPER_CASE)
		{
			ucInpStr[unStrIndex] += UPPER_LOWER_DIFF;
		}
		unStrIndex++;
	}
	puts(ucInpStr);
    return true;
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : converts lowercase characters to uppercase
//Inputs  : Nil
//Outputs : user input string is converted to uppercase
//Return  : returns true 
//Notes   : checks if the char in the string is lowercase then it is subtracted
//          to get the corresponding uppercase char
//******************************************************************************
static bool strMnpLowerUpper()
{
    printf("Enter the string\n");
    scanf(" %[^\n]",ucInpStr);
    unStrIndex = 0;
	while(ucInpStr[unStrIndex] != '\0')
	{
		if(ucInpStr[unStrIndex] >= MIN_LOW_CASE && 
            ucInpStr[unStrIndex] <= MAX_LOW_CASE)
		{
			ucInpStr[unStrIndex] -= UPPER_LOWER_DIFF;
		}
		unStrIndex++;
	}
	puts(ucInpStr);
    return true;   
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : Function concatanates two strings
//Inputs  : Nil
//Outputs : user input strings are concatenated
//Return  : returns true 
//Notes   : Finds the end of the first and the second string added from the last
//          index for the first string
//******************************************************************************
static bool strMnpConcatenate()
{
    unCatStrIndex = 0, unStrIndex = 0;
    printf("Enter the strings to be concatenated:\n");
    scanf(" %[^\n]",ucInpStr);
	scanf(" %[^\n]",ucCatStr);

	while(ucInpStr[unStrIndex] != '\0')
		unStrIndex++;
	while(ucCatStr[unCatStrIndex] != '\0')
	{
		ucInpStr[unStrIndex] = ucCatStr[unCatStrIndex];
		unStrIndex++;
		unCatStrIndex++;
	}
	ucInpStr[unStrIndex] = '\0';
    puts(ucInpStr);
    return true;
	
}
// EOF