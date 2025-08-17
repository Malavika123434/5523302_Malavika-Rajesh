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

int* getUniqueRanks(int* ranked, int ranked_count, int* unique_count) {
    if (ranked_count == 0) {
        *unique_count = 0;
        return NULL;
    }

    int* unique_ranked = malloc(sizeof(int) * ranked_count);
    int current_unique_index = 0;
    unique_ranked[current_unique_index++] = ranked[0];

    for (int i = 1; i < ranked_count; i++) {
        if (ranked[i] != ranked[i - 1]) {
            unique_ranked[current_unique_index++] = ranked[i];
        }
    }
    *unique_count = current_unique_index;
    return unique_ranked;
}

int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int unique_ranked_count;
    int* unique_ranked = getUniqueRanks(ranked, ranked_count, &unique_ranked_count);

    int* alice_ranks = malloc(sizeof(int) * player_count);
    *result_count = player_count;

    int current_rank_index = unique_ranked_count - 1;

    for (int i = 0; i < player_count; i++) {
        while (current_rank_index >= 0 && player[i] >= unique_ranked[current_rank_index]) {
            current_rank_index--;
        }
        alice_ranks[i] = current_rank_index + 2;
        if (current_rank_index < 0) {
            alice_ranks[i] = 1;
        }
    }
    free(unique_ranked);
    return alice_ranks;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int ranked_count = parse_int(ltrim(rtrim(readline())));
    char** ranked_temp = split_string(rtrim(readline()));
    int* ranked = malloc(ranked_count * sizeof(int));

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = parse_int(*(ranked_temp + i));
        *(ranked + i) = ranked_item;
    }

    int player_count = parse_int(ltrim(rtrim(readline())));
    char** player_temp = split_string(rtrim(readline()));
    int* player = malloc(player_count * sizeof(int));

    for (int i = 0; i < player_count; i++) {
        int player_item = parse_int(*(player_temp + i));
        *(player + i) = player_item;
    }

    int result_count;
    int* result = climbingLeaderboard(ranked_count, ranked, player_count, player, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));
        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");
    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024, data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;

        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) {
            data = '\0';
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data) data = '\0';
    } else {
        data = realloc(data, data_length + 1);
        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
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
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) return splits;
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
