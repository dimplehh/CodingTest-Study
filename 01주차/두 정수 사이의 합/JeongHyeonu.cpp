#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long sum = 0;
    if (a < b) {
        for (int i = a; i <= b; i++) sum += i;
    }
    else if (a > b) {
        for (int i = b; i <= a; i++) sum += i;
    }
    else return a;
    return sum;
}