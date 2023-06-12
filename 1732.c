#include <stdio.h>

inline int max(int e1, int e2);
int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}

int largestAltitude(int* gain, int gainSize) {
    int heightest = 0, last = 0;
    for (int i = 0; i < gainSize; i++) {
        last += gain[i];
        heightest = max(heightest, last);
    }
    return heightest;
}

int main() {
    int gain[] = {-5,1,5,0,-7};
    largestAltitude(gain, 5);
    return 0;
}