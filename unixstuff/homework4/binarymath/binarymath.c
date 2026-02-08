#include <stdlib.h>
#include <string.h>
#include "binarymath.h"
#include <stdio.h>


/**
 * Negate a BINARY_SIZE binary number expressed as 
 * a character string
 * @param number The number we are passed
 * @returns negated version of the number
 */
char *negate(const char *number)
{
    char *temp = calloc(BINARY_SIZE + 1, sizeof(char));
    
    for (size_t i = 0; i < BINARY_SIZE; i++) {
        if (number[i] == 'F') {
            temp[i] = 'T';
        } else {
            temp[i] = 'F';
        }
    }

    temp[BINARY_SIZE] = '\0';
    
    for (int i = BINARY_SIZE - 1; i >= 0; i--) {
        if (temp[i] == 'T') {
            temp[i] = 'F';
        } else {
            temp[i] = 'T';
            break;
        }
    }

    return temp;
    
}

/**
 * Add two BINARY_SIZE binary numbers expressed as
 * a character string. 
 * @param a First number to add
 * @param b Second number to add
 * @return a + b
 */
char *add(const char *a, const char *b)
{
    char * temp = calloc(BINARY_SIZE + 1, sizeof(char));

    int carry = 0;
    for (int i = BINARY_SIZE - 1; i >= 0; i--) {
        int sum = carry;
        if (a[i] == 'T') { sum++; }
        if (b[i] == 'T') { sum++; }

        if (sum == 0) {
            temp[i] = 'F';
            carry = 0;
        } else if (sum == 1) {
            temp[i] = 'T';
            carry = 0;
        } else if (sum == 2) {
            temp[i] = 'F';
            carry = 1;
        } else {
            temp[i] = 'T';
            carry = 1;
        }
    }
    temp[BINARY_SIZE] = '\0';
    return temp;
}

/**
 * Subtract two BINARY_SIZE binary numbers expressed as
 * a character string.
 * @param a First number
 * @param b Second number 
 * @return a - b
 */
char *sub(const char *a, const char *b)
{
    char * temp = calloc(BINARY_SIZE + 1, sizeof(char));
    char * bNegated = negate(b);
    char * sub = add(a, bNegated);
    sub[BINARY_SIZE] = '\0';
    
    free(temp);
    free(bNegated);
    return sub;
}

