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

    unsigned int greaterDigitIndex = numeralsIndex+2; //M

    unsigned int middleDigitIndex = numeralsIndex+1; //D

    unsigned int lesserDigitIndex = numeralsIndex; //C

    unsigned int quotient = arabicNumber / numerals.arabic[numeralsIndex];

    if(quotient > 0 && quotient < 4)
    {
        for (unsigned int i = 0; i < quotient; i++)
        {
            romanNumber[indexOfRomanNumber] = numerals.roman[lesserDigitIndex];
            indexOfRomanNumber += 1;
        }
    }
    else if(4 == quotient)
    {
        romanNumber[indexOfRomanNumber] = numerals.roman[lesserDigitIndex];
        indexOfRomanNumber += 1;
        romanNumber[indexOfRomanNumber] = numerals.roman[middleDigitIndex];
        indexOfRomanNumber += 1;
    }
    else if((5 <= quotient) && (9 > quotient))
    {
        romanNumber[indexOfRomanNumber] = numerals.roman[middleDigitIndex];
        indexOfRomanNumber += 1;
        for (unsigned int i = 5; i < quotient; i++)
        {
            romanNumber[indexOfRomanNumber] = numerals.roman[lesserDigitIndex];
            indexOfRomanNumber += 1;
        }
    }
    else if(9 == quotient)
    {
        romanNumber[indexOfRomanNumber] = numerals.roman[lesserDigitIndex];
        indexOfRomanNumber += 1;
        romanNumber[indexOfRomanNumber] = numerals.roman[greaterDigitIndex];
        indexOfRomanNumber += 1;
    }
    
    if(numeralsIndex > 1) //don't go past the bounds of the numerals array
    {
        unsigned int remainder = arabicNumber % numerals.arabic[numeralsIndex];
        if(remainder > 0)
        {  
            arabic_digit_to_roman_digits(romanNumber, remainder, indexOfRomanNumber, numeralsIndex-2);
        }
    }
    
}

char *to_roman_numeral(unsigned int number)
{

    char *romanNumeral = calloc(15, sizeof(char));
    arabic_digit_to_roman_digits(romanNumeral, number, 0, 6);

    return romanNumeral;
}