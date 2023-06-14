#include <stdio.h>
#include <malloc.h>

int* countBits(int n, int* returnSize) {
    int* Bits = (int*)malloc((n + 1) * sizeof(int));
    Bits[0] = 0;
    for(int i = 1; i <= n; i++) {
        Bits[i] = Bits[i & (i - 1)] + 1;
    }
    (*returnSize) = n + 1;
    return Bits;
}

int main() {
    int returnSize;
    countBits(5, &returnSize);
    return 0;
}