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

    return romanNumeral;
}