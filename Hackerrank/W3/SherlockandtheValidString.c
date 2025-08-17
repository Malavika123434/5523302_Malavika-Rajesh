#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readInput();

char* isValid(char* s) {
    int charCount[26] = {0}; 
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i] - 'a']++;
    }

    int freqArr[26];
    int freqLen = 0;

    for (int i = 0; i < 26; i++) {
        if (charCount[i] > 0) {
            freqArr[freqLen++] = charCount[i];
        }
    }

    if (freqLen == 0) {
        return "YES";
    }

    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < freqLen; i++) {
        if (freqArr[i] < minVal) minVal = freqArr[i];
        if (freqArr[i] > maxVal) maxVal = freqArr[i];
    }

    if (minVal == maxVal) {
        return "YES"; 
    }

    int minFreqCount = 0, maxFreqCount = 0;
    for (int i = 0; i < freqLen; i++) {
        if (freqArr[i] == minVal) minFreqCount++;
        else if (freqArr[i] == maxVal) maxFreqCount++;
    }

    
    if (minVal == 1 && minFreqCount == 1 && minFreqCount + maxFreqCount == freqLen) {
        return "YES";
    }

    if (maxVal == minVal + 1 && maxFreqCount == 1) {
        return "YES";
    }

    return "NO";
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readInput();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readInput() {
    size_t bufCap = 1024;
    size_t len = 0;

    char* buffer = malloc(bufCap);

    while (true) {
        char* cur = buffer + len;
        char* line = fgets(cur, bufCap - len, stdin);

        if (!line) {
            break;
        }

        len += strlen(cur);

        if (len < bufCap - 1 || buffer[len - 1] == '\n') {
            break;
        }

        bufCap <<= 1;
        buffer = realloc(buffer, bufCap);

        if (!buffer) {
            buffer = '\0';
            break;
        }
    }

    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';

        buffer = realloc(buffer, len);

        if (!buffer) {
            buffer = '\0';
        }
    } else {
        buffer = realloc(buffer, len + 1);

        if (!buffer) {
            buffer = '\0';
        } else {
            buffer[len] = '\0';
        }
    }

    return buffer;
}
