#include <stdio.h>
#include <math.h>

int isPow2(unsigned long long num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

unsigned long long getLowerPow2(unsigned long long num) {
    unsigned long long power = 1ULL << ((unsigned long long)log2(num));
    if (power == num) power >>= 1;
    return power;
}

int main() {
    int testCount;
    scanf("%d", &testCount);
    while (testCount--) {
        unsigned long long currentNum;
        scanf("%llu", &currentNum);
        int turnCount = 0;

        while (currentNum != 1) {
            if (isPow2(currentNum)) {
                currentNum >>= 1;
            } else {
                currentNum -= getLowerPow2(currentNum);
            }
            turnCount++;
        }

        if (turnCount % 2 == 1)
            printf("Louise\n");
        else
            printf("Richard\n");
    }
    return 0;
}
