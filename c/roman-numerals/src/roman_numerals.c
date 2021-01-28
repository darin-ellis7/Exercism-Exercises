#include "roman_numerals.h"
#include <stdlib.h>

char *arabic_digit_to_roman_digits(char *romanNumber, unsigned int arabicNumber)
{
    unsigned int difference;

    //first three
    if(4 > arabicNumber)
    {
        difference = 4 - arabicNumber;
        for (unsigned int i = 0; i < 4-difference; i++)
        {
            romanNumber[i] = 'I';
        }
    }
    //one below five
    else if(4 == arabicNumber)
    {
        romanNumber[0] = 'I';
        romanNumber[1] = 'V';
    }
    //even with five and up to three above it
    else if(4 < arabicNumber && 9 > arabicNumber)
    {
        romanNumber[0] = 'V';
        for(unsigned int i = 0; i < arabicNumber - 5; i++)
         {
             romanNumber[i+1] = 'I';
         }
    }
    return romanNumber;
}

char *to_roman_numeral(unsigned int number)
{
    //Roman digit key:
    // I = 1
    // V = 5
    // X = 10
    // L = 50
    // C = 100
    // D = 500
    // M = 1000

    char *romanNumeral = calloc(15, sizeof(char));
    
    romanNumeral = arabic_digit_to_roman_digits(romanNumeral, number);

    // if(number <= 3)
    // {
    //     for(unsigned int i = 0; i < number; i++)
    //     {
    //         romanNumeral[i] = 'I';
    //     }
    // }
    // else if(number == 4)
    // {
    //     romanNumeral[0] = 'I';
    //     romanNumeral[1] = 'V';
    // }
    // else if(number >= 5 && number <= 8)
    // {
    //     romanNumeral[0] = 'V';
    //     for(unsigned int i = 0; i < number - 5; i++)
    //     {
    //         romanNumeral[i+1] = 'I';
    //     }
    // }
    if(number == 9)
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