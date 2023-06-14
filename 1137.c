#include <stdio.h>
#include <malloc.h>

int tribonacci(int n) {
    int T[3] = {0, 1, 1};
    int sum = 2, tmp = 0;
    if(n < 3) return T[n];
    for(int i = 3; i < n; i++) {
        tmp = sum;
        sum -= T[i % 3];
        T[i % 3] = tmp;
        sum += T[i % 3];
    }
    return sum;
}

int main() {
    tribonacci(23);
    return 0;
}