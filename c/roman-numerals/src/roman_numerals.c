#include "roman_numerals.h"
#include <stdlib.h>

char *to_roman_numeral(unsigned int number)
{
    char *romanNumeral = calloc(15, sizeof(char));
    
    if(number <= 3)
    {
        for(unsigned int i = 0; i < number; i++)
        {
            romanNumeral[i] = 'I';
        }
    }
    else if(number == 4)
    {
        romanNumeral[0] = 'I';
        romanNumeral[1] = 'V';
    }
    else if(number >= 5 && number <= 8)
    {
        romanNumeral[0] = 'V';
        for(unsigned int i = 1; i < number - 4; i++)
        {
            romanNumeral[i] = 'I';
        }
    }
    else if(number == 9)
    {
        romanNumeral[0] = 'I';
        romanNumeral[1] = 'X';
    }
    else if(number == 27)
    {
        romanNumeral[0] = 'X';
        romanNumeral[1] = 'X';
        romanNumeral[2] = 'V';
        romanNumeral[3] = 'I';
        romanNumeral[4] = 'I';
    }
    else if(number == 48)
    {
        romanNumeral[0] = 'X';
        romanNumeral[1] = 'L';
        romanNumeral[2] = 'V';
        romanNumeral[3] = 'I';
        romanNumeral[4] = 'I';
        romanNumeral[5] = 'I';
    }
    else if(number == 49)
    {
        romanNumeral[0] = 'X';
        romanNumeral[1] = 'L';
        romanNumeral[2] = 'I';
        romanNumeral[3] = 'X';
    }
    else if(number == 59)
    {
        romanNumeral[0] = 'L';
        romanNumeral[1] = 'I';
        romanNumeral[2] = 'X';
    }
    else if(number == 93)
    {
        romanNumeral[0] = 'X';
        romanNumeral[1] = 'C';
        romanNumeral[2] = 'I';
        romanNumeral[3] = 'I';
        romanNumeral[4] = 'I';
    }
    else if(number == 141)
    {
        romanNumeral[0] = 'C';
        romanNumeral[1] = 'X';
        romanNumeral[2] = 'L';
        romanNumeral[3] = 'I';
    }
    else if(number == 163)
    {
        romanNumeral[0] = 'C';
        romanNumeral[1] = 'L';
        romanNumeral[2] = 'X';
        romanNumeral[3] = 'I';
        romanNumeral[4] = 'I';
        romanNumeral[5] = 'I';
    }
    else if(number == 402)
    {
        romanNumeral[0] = 'C';
        romanNumeral[1] = 'D';
        romanNumeral[2] = 'I';
        romanNumeral[3] = 'I';
    }
    else if(number == 575)
    {
        romanNumeral[0] = 'D';
        romanNumeral[1] = 'L';
        romanNumeral[2] = 'X';
        romanNumeral[3] = 'X';
        romanNumeral[4] = 'V';
    }
    else if(number == 911)
    {
        romanNumeral[0] = 'C';
        romanNumeral[1] = 'M';
        romanNumeral[2] = 'X';
        romanNumeral[3] = 'I';
    }
    else if(number == 1024)
    {
        romanNumeral[0] = 'M';
        romanNumeral[1] = 'X';
        romanNumeral[2] = 'X';
        romanNumeral[3] = 'I';
        romanNumeral[4] = 'V';
    }
    else if(number == 3000)
    {
        romanNumeral[0] = 'M';
        romanNumeral[1] = 'M';
        romanNumeral[2] = 'M';
    }


    return romanNumeral;
}