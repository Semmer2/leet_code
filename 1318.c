#include <stdio.h>

int numOnes(int n) {
    int count = 0;
    while(n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int minFlips(int a, int b, int c) {
    int count = 0;
    int tmp = a & b;
    count += numOnes( a & b & ~c);
    count += numOnes((a | b) & ~c);
    count += numOnes((~(a | b)) & c);
    return count;
}

int main() {
    minFlips(2, 6, 5);
    return 0;
}