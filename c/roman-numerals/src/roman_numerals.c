#include "roman_numerals.h"
#include <stdlib.h>

void arabic_digit_to_roman_digits(
    char *romanNumber, 
    unsigned int arabicNumber, 
    unsigned int startingIndexOfRomanNumber,
    unsigned int startingNumeralsMapIndex
    )
{
    struct numeralmap numerals = { 
         {'I', 'V', 'X', 'L', 'C', 'D', 'M'},
         { 1, 5, 10, 50, 100, 500, 1000}
    }; 
    
    unsigned int numeralsIndex = startingNumeralsMapIndex;

    unsigned int indexOfRomanNumber = startingIndexOfRomanNumber;

    unsigned int quotient = arabicNumber / numerals.arabic[numeralsIndex];
    if(quotient > 0 && quotient < 4)
    {
        for (unsigned int i = 0; i < quotient; i++)
        {
            romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex];
            indexOfRomanNumber += 1;
        }
    }
    else if(4 == quotient)
    {
        romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex];
        indexOfRomanNumber += 1;
        romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex+1];
        indexOfRomanNumber += 1;
    }
    // else if(quotient > 4)
    // {
    //     romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex];
    //     indexOfRomanNumber += 1;
    //     for (unsigned int i = 0; i < quotient; i++)
    //     {
    //          romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex-1];
    //          indexOfRomanNumber += 1;
    //     }
    // }

    unsigned int remainder = arabicNumber % numerals.arabic[numeralsIndex];
    if(numeralsIndex >= 2)
    {
        if((remainder / 9) == numerals.arabic[numeralsIndex-2])
        {
            romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex-2];
            indexOfRomanNumber += 1;
            romanNumber[indexOfRomanNumber] = numerals.roman[numeralsIndex];
            indexOfRomanNumber += 1;
            numeralsIndex -= 1;
        }
    }

    if(remainder > 0)
    {  
            arabic_digit_to_roman_digits(romanNumber, remainder, indexOfRomanNumber, numeralsIndex-1);
    }
    // else if(remainder > 0)
    // {
    //     arabic_digit_to_roman_digits(romanNumber, remainder, indexOfRomanNumber, numeralsIndex-1);
    // }
}

char *to_roman_numeral(unsigned int number)
{

    char *romanNumeral = calloc(15, sizeof(char));
    arabic_digit_to_roman_digits(romanNumeral, number, 0, 6);

    return romanNumeral;
}