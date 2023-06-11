#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ifVowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int max(int e1, int e2) {
    return e1 > e2 ? e1 : e2;
}
//what if it is not continuous?
double maxVowels(char* s, int k) {
    int result = 0;
    int i = 0, total = 0;
    for (int i = 0; i < k; i++) {
        if (ifVowels(s[i]))
        total++;
    }
    result = total;
    while(i < strlen(s) - k) {
        if (ifVowels(s[i])) total--;
        if (ifVowels(s[i + k])) total++;
        if (!ifVowels(s[i]) && ifVowels(s[i + k]))
            result = max(total, result);
        i++;
    }
    return result;
}

int main() {
    char* s="tryhard";
    maxVowels(s, 4);
    return 0;
}