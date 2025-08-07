#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* strings_xor(const char* s, const char* t) {
    int len = strlen(s);
    char* result = malloc(len + 1);
    if (!result) return NULL;
    
    for (int i = 0; i < len; i++) {
        result[i] = (s[i] == t[i]) ? '0' : '1';
    }
    result[len] = '\0';
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[100001], t[100001];
    
    scanf("%s", s);
    scanf("%s", t);
    
    char* xor_result = strings_xor(s, t);
    if (xor_result) {
        printf("%s\n", xor_result);
        free(xor_result);
    }
    return 0;
}