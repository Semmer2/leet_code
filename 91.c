#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUMOFFSET(a) ((a) - ('0'))

bool validationCaps(char* s, bool ifDouble) {
    char c = 0;
    if(ifDouble) {
        c += (NUMOFFSET((*(s - 1)))) * 10;
        if(c == 0) return false;
    }
    c += NUMOFFSET((*s));
    c = c + 'A' - 1;
    if (c >= 'A' && c <= 'Z') return true;
    return false;
}

int numDecodings(char* s) {
    int count[101] = {0}, it = 1;
    int len = strlen(s);
    count[0] = validationCaps(s, false) ? 1 : 0;
    if(len == 1) return count[0];
    s++;
    count[1] += validationCaps(s, false) ? count[0] : 0;
    count[1] += validationCaps(s, true)  ? 1        : 0;
    if(len == 2) return count[1];
    s++;
    while ((*s) != '\0')
    {
        it++;
        count[it] += validationCaps(s, false) ? count[it - 1] : 0;
        count[it] += validationCaps(s, true)  ? count[it - 2] : 0;
        s++;
    }
    return count[it];
}

int main() {
    char s[] = "11106";
    numDecodings(s);
    return 0;
}