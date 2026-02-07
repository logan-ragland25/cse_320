#include "bin2oct.h"
#include <stdio.h>

/**
 * Convert a binary representation of a 
 * number to an unsigned octal. 
 * 
 * For this function, the values Y and N represent 
 * true (1) and false (0) respectfully. So, the string:
 * 
 * YYNY is equal to 1101 binary, which is equal to 15.
 *
 * Unexpected characters are ignored. Only Y's and N's are
 * considered to be valid. Stop converting when you get
 * to a space character or the end of the string. The 
 * representation is case-sensitive (only Y/N are valid 
 * true and false values).
 *
 * 'aYNcY YY' should convert to 5
 * 'NYNYny' should convert to 5
 *
 * @param binary Binary number as a string of 'Y's and 'N's
 * and other characters.
 * @returns unsigned int result
 */
unsigned int bin2oct(const char *binary)
{
	unsigned int value = 0;
   
    // convert from binary to decimal
    for( ; *binary; binary++)
    {
        if (*binary == ' ') {
            break;
        }
        if(*binary == 'Y') {
            value = value * 2 + 1;   
        }
        if(*binary == 'N') {
            value = value * 2;   
        }
    }
    
    // convert from decimal to octal
    unsigned int quotient = value;
    unsigned int octalVal = 0;
    unsigned int digit = 1;

    while (quotient > 0) {
        octalVal += (quotient % 8) * digit;
        quotient /= 8;
        digit *= 10;
    }
    return octalVal;
}
