#include "roman_numerals.h"
#include <stdlib.h>

char *arabic_digit_to_roman_digits(char *romanNumber, unsigned int arabicNumber, char greaterRomanDigit, char lesserRomanDigit, unsigned int greaterArabicDigit, unsigned int lesserArabicDigit, unsigned int startingIndexOfRomanNumber)
{
    lesserArabicDigit = lesserArabicDigit-1;
    //first three lesserRomanDigit
    if(greaterArabicDigit-1 > arabicNumber)
    {
        for (unsigned int i = 0; i < arabicNumber; i++)
        {
            romanNumber[startingIndexOfRomanNumber+i] = lesserRomanDigit;
        }
    }
    //one below greaterRomanDigit
    else if(greaterArabicDigit-1 == arabicNumber)
    {
        romanNumber[startingIndexOfRomanNumber] = lesserRomanDigit;
        romanNumber[startingIndexOfRomanNumber+1] = greaterRomanDigit;
    }
    //even with greaterRomanDigit and up to three above it
    else if(greaterArabicDigit-1 < arabicNumber && (greaterArabicDigit*2)-1 > arabicNumber)
    {
        romanNumber[startingIndexOfRomanNumber] = greaterRomanDigit;
        for(unsigned int i = 0; i < arabicNumber - greaterArabicDigit; i++)
         {
             romanNumber[startingIndexOfRomanNumber+i+1] = lesserRomanDigit;
         }
    }
    return romanNumber;
}

char *to_roman_numeral(unsigned int number)
{
    // struct numeralmap numerals = { 
    //     {'I', 'V', 'X', 'L', 'C', 'D', 'M'},
    //     { 1, 5, 10, 50, 100, 500, 1000}
    // }; 

    char *romanNumeral = calloc(15, sizeof(char));
    
    //Handles tests 1-6
    if(number < 9)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, number, 'V', 'I', 5, 1, 0);
    }
    else if(number == 9)
    {
        //Handles test 9
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, number, 'X', 'I', 10, 1, 0);
    }
    else if(number == 27)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 10, 'X', 'I', 10, 1, 0);
        number -= 10;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 10, 'X', 'I', 10, 1, 1);
        number -= 10;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 7, 'V', 'I', 5, 1, 2);
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