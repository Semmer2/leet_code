#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    if(!strlen(s)) return true;
    int s_it = 0, t_it = 0;
    while(s[s_it] != '\0' && t[t_it] != '\0') {
        if(s[s_it] == t[t_it]) {
            s_it++;
            t_it++;
        } else {
            t_it++;
        }
    }
    if(s[s_it] == '\0') return true;
    else return false;
}

int main() {
    char* s="abc";
    char* t="ahbgdc";
    isSubsequence(s, t);
    return 0;
}