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

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

static char** blastGrid(char** board, int rows, int cols) {
    char** newBoard = malloc(rows * sizeof(char*));
    for (int r = 0; r < rows; r++) {
        newBoard[r] = malloc(cols + 1);
        memset(newBoard[r], 'O', cols);
        newBoard[r][cols] = '\0';
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 'O') {
                newBoard[r][c] = '.';
                if (r > 0) newBoard[r - 1][c] = '.';
                if (r < rows - 1) newBoard[r + 1][c] = '.';
                if (c > 0) newBoard[r][c - 1] = '.';
                if (c < cols - 1) newBoard[r][c + 1] = '.';
            }
        }
    }
    return newBoard;
}

char** bomberMan(int time, int rowCount, char** board, int* outCount) {
    *outCount = rowCount;
    int colCount = strlen(board[0]);

    char** fullBombs = malloc(rowCount * sizeof(char*));
    for (int r = 0; r < rowCount; r++) {
        fullBombs[r] = malloc(colCount + 1);
        memset(fullBombs[r], 'O', colCount);
        fullBombs[r][colCount] = '\0';
    }

    if (time == 1) {
        return board;
    }
    if (time % 2 == 0) {
        return fullBombs;
    }

    char** firstBlast = blastGrid(board, rowCount, colCount);
    char** secondBlast = blastGrid(firstBlast, rowCount, colCount);

    if ((time - 3) % 4 == 0) {
        return firstBlast;
    } else {
        return secondBlast;
    }
}

int main() {
    FILE* fOut = fopen(getenv("OUTPUT_PATH"), "w");

    char** firstInput = split_string(rtrim(readline()));

    int rows = parse_int(*(firstInput + 0));
    int cols = parse_int(*(firstInput + 1));
    int time = parse_int(*(firstInput + 2));

    char** board = malloc(rows * sizeof(char*));

    for (int r = 0; r < rows; r++) {
        char* rowStr = readline();
        *(board + r) = rowStr;
    }

    int resCount;
    char** result = bomberMan(time, rows, board, &resCount);

    for (int r = 0; r < resCount; r++) {
        fprintf(fOut, "%s", *(result + r));
        if (r != resCount - 1) {
            fprintf(fOut, "\n");
        }
    }

    fprintf(fOut, "\n");
    fclose(fOut);
    return 0;
}

char* readline() {
    size_t bufSize = 1024;
    size_t len = 0;
    char* data = malloc(bufSize);

    while (true) {
        char* ptr = data + len;
        char* line = fgets(ptr, bufSize - len, stdin);

        if (!line) break;
        len += strlen(ptr);
        if (len < bufSize - 1 || data[len - 1] == '\n') break;

        bufSize <<= 1;
        data = realloc(data, bufSize);
        if (!data) {
            data = '\0';
            break;
        }
    }

    if (data[len - 1] == '\n') {
        data[len - 1] = '\0';
        data = realloc(data, len);
        if (!data) data = '\0';
    } else {
        data = realloc(data, len + 1);
        if (!data) {
            data = '\0';
        } else {
            data[len] = '\0';
        }
    }
    return data;
}

char* ltrim(char* str) {
    if (!str) return '\0';
    if (!*str) return str;
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return '\0';
    if (!*str) return str;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** parts = NULL;
    char* token = strtok(str, " ");
    int count = 0;
    while (token) {
        parts = realloc(parts, sizeof(char*) * ++count);
        if (!parts) return parts;
        parts[count - 1] = token;
        token = strtok(NULL, " ");
    }
    return parts;
}

int parse_int(char* str) {
    char* endptr;
    int val = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return val;
}
