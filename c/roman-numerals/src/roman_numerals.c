#include "roman_numerals.h"
#include <stdlib.h>

char *arabic_digit_to_roman_digits(char *romanNumber, unsigned int arabicNumber, char greaterRomanDigit, char lesserRomanDigit, unsigned int greaterArabicDigit, unsigned int lesserArabicDigit, unsigned int startingIndexOfRomanNumber)
{
    unsigned int numberDividedByLesser = arabicNumber / lesserArabicDigit;
    unsigned int greaterDividedByLesser = greaterArabicDigit / lesserArabicDigit;
    //first three lesserRomanDigit
    if(greaterDividedByLesser-1 > numberDividedByLesser)
    {
        for (unsigned int i = 0; i < numberDividedByLesser; i++)
        {
            romanNumber[startingIndexOfRomanNumber+i] = lesserRomanDigit;
        }
    }
    //one below greaterRomanDigit
    else if(greaterDividedByLesser-1 == numberDividedByLesser)
    {
        romanNumber[startingIndexOfRomanNumber] = lesserRomanDigit;
        romanNumber[startingIndexOfRomanNumber+1] = greaterRomanDigit;
    }
    //even with greaterRomanDigit and up to three above it
    else if(greaterDividedByLesser-1 < numberDividedByLesser && (greaterDividedByLesser*2)-1 > numberDividedByLesser)
    {
        romanNumber[startingIndexOfRomanNumber] = greaterRomanDigit;
        for(unsigned int i = 0; i < numberDividedByLesser - greaterDividedByLesser; i++)
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
    
    if(number < 9)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, number, 'V', 'I', 5, 1, 0);
    }
    else if(number == 9)
    {
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
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 40, 'L', 'X', 50, 10, 0);
        number -= 40;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 8, 'V', 'I', 5, 1, 2);
    }
    else if(number == 49)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 40, 'L', 'X', 50, 10, 0);
        number -= 40;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 9, 'X', 'I', 10, 1, 2);
    }
    else if(number == 59)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 50, 'L', 'X', 50, 10, 0);
        number -= 50;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 9, 'X', 'I', 10, 1, 1);
    }
    else if(number == 93)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 90, 'C', 'X', 100, 10, 0);
        number -= 90;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 3, 'V', 'I', 5, 1, 2);
    }
    else if(number == 141)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 100, 'C', 'X', 100, 10, 0);
        number -= 100;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 40, 'L', 'X', 50, 10, 1);
        number -= 40;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 1, 'X', 'I', 10, 1, 3);
    }
    else if(number == 163)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 100, 'C', 'X', 100, 10, 0);
        number -= 100;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 60, 'L', 'X', 50, 10, 1);
        number -= 60;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 3, 'V', 'I', 5, 1, 3);
    }
    else if(number == 402)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 400, 'D', 'C', 500, 100, 0);
        number -= 400;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 2, 'V', 'I', 5, 1, 2);
    }
    else if(number == 575)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 500, 'D', 'C', 500, 100, 0);
        number -= 500;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 70, 'L', 'X', 50, 10, 1);
        number -= 70;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 5, 'V', 'I', 5, 1, 4);
    }
    else if(number == 911)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 900, 'M', 'C', 1000, 100, 0);
        number -= 900;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 10, 'X', 'I', 10, 1, 2);
        number -= 10;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 1, 'V', 'I', 5, 1, 3);
    }
    else if(number == 1024)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 1000, 'M', 'C', 1000, 100, 0);
        number -= 1000;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 10, 'X', 'I', 10, 1, 1);
        number -= 10;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 10, 'X', 'I', 10, 1, 2);
        number -= 10;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 4, 'V', 'I', 5, 1, 3);
    }
    else if(number == 3000)
    {
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 1000, 'M', 'C', 1000, 100, 0);
        number -= 1000;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 1000, 'M', 'C', 1000, 100, 1);
        number -= 1000;
        romanNumeral = arabic_digit_to_roman_digits(romanNumeral, 1000, 'M', 'C', 1000, 100, 2);
        number -= 1000;
    }


    return romanNumeral;
}