#include "decoder.h"
#include <string.h>
#include <stdio.h>

/**
 * Decode an encoded string into a character stream.
 * @param encoded The input string we are decoding
 * @param decoded The output string we produce
 * @param maxLen The maximum size for decoded
 */


void pushDecoded(char *decoded, int *bytePos, int *bitPos, int value, int maxLen) {
    // Make sure not out of bounds
    if (*bytePos >= maxLen) {
        return;
    }

    // If bit must be enabled
    // 
    if (value == 1) {
        // Get position of bit in byte
        int positionInByte = 7 - *bitPos;

        // Shift the byte positionInByte Amount and merge
        decoded[*bytePos] |= (1 << positionInByte);
    }

    // Increment bit
    (*bitPos)++;
    if (*bitPos > 7) {
        *bytePos += 1;
        *bitPos = 0;
    }
}

void decoder(const char *encoded, char *decoded, int maxLen)
{
    for (unsigned int i = 0; i < maxLen; i++)
    {
        decoded[i] = 0;
    }

    int bytePos = 0;
    int bitPos = 0;

    int i = 0;
    while (encoded[i] != '\0' && bytePos < maxLen) {
        if (encoded[i] == 't') {
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
        } else if (encoded[i] == 'c') {
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
        } else if (encoded[i] == 'x') {
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
        } else if (encoded[i] == 'w') {
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
        } else if (encoded[i] == '&') {
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
        } else if (encoded[i] == 'D') {
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
        } else if (encoded[i] == 'k') {
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
        } else if (encoded[i] == 'P') {
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
        } else if (encoded[i] == 'S') {
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
        } else if (encoded[i] == '+') {
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
        } else if (encoded[i] == 'T') {
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 0, maxLen);
        } else if (encoded[i] == '9') {
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
            pushDecoded(decoded, &bytePos, &bitPos, 1, maxLen);
        }

        i++;
    }
}

// Unused
void addToIt(int *num)
{
    (*num)++;
}