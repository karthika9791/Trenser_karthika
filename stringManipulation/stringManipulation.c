//**************************** String Manipulation ***************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File    : string_manipulation.c
// Summary : File which contains string manipualtion functions
// Note    : None
// Author  : Karthika V T
// Date    : 20-02-2026
// 
//******************************************************************************

//******************************* Include Files ********************************
#include "stringManipulation.h"

//******************************* Local Types **********************************
typedef enum{
	OPTION_UPPER_TO_LOWER = 1,
	OPTION_LOWER_TO_UPPER,
	OPTION_CONCAT,
	OPTION_EXIT
}OPTION_TYPE;

//***************************** Local Constants ********************************
#define STRMAIP_MAX_STR_SIZE     (100)
#define STRMAIP_MIN_UPPER_CASE   ('A')
#define STRMAIP_MAX_UPPER_CASE   ('Z')
#define STRMAIP_MIN_LOW_CASE     ('a')
#define STRMAIP_MAX_LOW_CASE     ('z')
#define STRMAIP_UPPER_LOWER_DIFF (32)

static OPTION_TYPE unInpOption = 0;
static uint16_t unStrIndex = 0;
static uint8_t pucInpStr[STRMAIP_MAX_STR_SIZE] = {0};
static uint8_t pucCatStr[STRMAIP_MAX_STR_SIZE] = {0};
static uint16_t unCatStrIndex = 0;

//****************************** Local Functions *******************************
static bool strManipUpperLower(char *);
static bool strManipLowerUpper(char *);
static bool strManipConcatenate(char *, char *);
static bool strManipDisplay(char *);

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : This function takes the option for particular string function, stri-
//          ng input and calls the respective function 
//Inputs  : None
//Outputs : corresponding function is called for string manipulation 
//Return  : returns true on succesfull execution
//Notes   : None
//****************************************************************************** 
bool strManipUserInterface(void)
{
    do
    {
        printf("Enter the operation to be performed\n");
        printf("1. Uppercase-Lowercase\n2. Lowercase-Uppercase\n");
        printf("3. Concatenate\n4. Exit\n");
        scanf("%d",&unInpOption);
        switch(unInpOption)
	    {
		    case OPTION_UPPER_TO_LOWER:
                printf("Enter the string\n");
                scanf(" %[^\n]",pucInpStr);
			    strManipUpperLower(pucInpStr);
			    break;
		    case OPTION_LOWER_TO_UPPER:
                printf("Enter the string\n");
                scanf(" %[^\n]",pucInpStr);
			    strManipLowerUpper(pucInpStr);
			    break;
		    case OPTION_CONCAT:
                printf("Enter the strings to be concatenated:\n");
                scanf(" %[^\n]",pucInpStr);
	            scanf(" %[^\n]",pucCatStr);
			    strManipConcatenate(pucInpStr,pucCatStr);
                break;
            case OPTION_EXIT:
                printf("Program exits\n");
                break;
		    default:
			    printf("Invalid input\n");
			    break;
	    }

    }
    while(unInpOption != OPTION_EXIT);
    if (OPTION_EXIT == unInpOption) {
        return true; 
    } else{
        return false;
    }
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : This function converts upperccase characters in the string to lower-
//          case
//Inputs  : User input string 
//Outputs : user input string is converted to lowercase 
//Return  : returns true on succesfull execution
//Notes   : checks if the char in the string is uppercase then it is added to 
//          get the corresponding lowercase char
//******************************************************************************
static bool strManipUpperLower(char *pucInpStr)
{   
    if (NULL != pucInpStr) {
        unStrIndex = 0;
        while('\0' !=  pucInpStr[unStrIndex])
        {
		    if(pucInpStr[unStrIndex] >= STRMAIP_MIN_UPPER_CASE && 
                pucInpStr[unStrIndex] <= STRMAIP_MAX_UPPER_CASE)
		    {
			    pucInpStr[unStrIndex] += STRMAIP_UPPER_LOWER_DIFF;
		    }
		unStrIndex++;
	    }
	    strManipDisplay(pucInpStr); 
        return true;
        
    }
    else
    {
        return false;
    }
    
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : This function converts lowercase characters in the string to upper-
//          case
//Inputs  : user input string
//Outputs : user input string is converted to uppercase
//Return  : returns true
//Notes   : checks if the char in the string is lowercase then it is subtracted
//          to get the corresponding uppercase char
//******************************************************************************
static bool strManipLowerUpper(char *pucInpStr)
{
    if (NULL != pucInpStr) {
        unStrIndex = 0;
	    while('\0' != pucInpStr[unStrIndex])
	    {
		    if(pucInpStr[unStrIndex] >= STRMAIP_MIN_LOW_CASE && 
                pucInpStr[unStrIndex] <= STRMAIP_MAX_LOW_CASE)
		    {
			    pucInpStr[unStrIndex] -= STRMAIP_UPPER_LOWER_DIFF;
		    }
		    unStrIndex++;
	    }
	    strManipDisplay(pucInpStr);
        return true; 
        
    }
    else
        return false;
      
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : The function concatanates two strings that is inputted by the user
//Inputs  : User input strings
//Outputs : user input strings are concatenated
//Return  : returns true 
//Notes   : Finds the end of the first and the second string added from the last
//          index for the first string
//******************************************************************************
static bool strManipConcatenate(char *pucInpStr, char *pucCatStr)
{
    if (NULL != pucInpStr) {
        unCatStrIndex = 0, unStrIndex = 0;
	    while('\0' != pucInpStr[unStrIndex])
		    unStrIndex++;
	    while('\0' != pucCatStr[unCatStrIndex])
	    {
		    pucInpStr[unStrIndex] = pucCatStr[unCatStrIndex];
		    unStrIndex++;
		    unCatStrIndex++;
	    }
	    pucInpStr[unStrIndex] = '\0';
        strManipDisplay(pucInpStr);
        return true;
    }
    else
        return false;
	
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : The function is used to display the string that is passed to the fu-
//          nction
//Inputs  : Input string to be displayed
//Outputs : string get printed in the console
//Return  : returns on displaying
//Notes   : Use puts library function to display
//******************************************************************************
static bool strManipDisplay(char *pucInpStr)
{
    if (NULL != pucInpStr) {
        puts(pucInpStr);
        return true;
    }
    else
        return false
    
}
// EOF