#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

struct numeralmap
{
    char roman[7];
    unsigned int arabic[7];
};

char *to_roman_numeral(unsigned int number);
char *arabic_digit_to_roman_digits(char *romanNumber, unsigned int arabicNumber, char greaterRomanDigit, char lesserRomanDigit, unsigned int greaterArabicDigit, unsigned int lesserArabicDigit, unsigned int startingIndexOfRomanNumber);


#endif
