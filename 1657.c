#include <stdio.h>
#include <stdbool.h>

bool closeStrings(char* word1, char* word2) {
    unsigned int wordFreq1[26] = {0};
    unsigned int wordFreq2[26] = {0};
    int it = 0;

    //calculate frequence
    do {
        wordFreq1[word1[it] - 'a']++;
        it++;
    } while (word1[it] != '\0');
    it = 0;
    do {
        wordFreq2[word2[it] - 'a']++;
        it++;
    } while (word2[it] != '\0');

    for(int i = 0; i < 26; i++) {
        if((bool)wordFreq1[i] ^ (bool)wordFreq2[i]) return false;
    }

    //check frequency
    for(int i = 0; i < 26; i++) {
        if(wordFreq1[i]) {
            for(int j = 0; j < 26; j++) {
                //found substitude characters
                if(wordFreq2[j] && wordFreq1[i] == wordFreq2[j]) {
                    wordFreq1[i] = 0;
                    wordFreq2[j] = 0;
                    break;
                }
            }
        }
        if(wordFreq1[i]) return false;
    }
    return true;
}

int main() {
    char* word1 = "cabbba",* word2 = "abbccc";
    closeStrings(word1, word2);
    return 0;
}