#include <stdio.h>
#include <math.h>

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int turns_front = p / 2;
    int turns_back;

    if (n % 2 == 0)
        turns_back = (n - p + 1) / 2;
    else
        turns_back = (n - p) / 2;

    if (turns_front < turns_back)
        printf("%d\n", turns_front);
    else
        printf("%d\n", turns_back);

    return 0;
}
