#include "stdio.h"
#include "malloc.h"

#define MAX_LEN 101

char *mergeAlternately(char *word1, char *word2) {
    char *retWord = (char *)malloc(sizeof(char) * MAX_LEN * 2);
    int loop1 = 0, loop2 = 0, fi = 0;
    for(int i = 0; i < MAX_LEN; i++) {
        if (word1[loop1] == '\0' && word2[loop2] == '\0' ) {
	    retWord[fi] = '\0';
	    break;
	}
	if (word1[loop1] == '\0');
	else {
	    retWord[fi] = word1[loop1];
	    loop1 = i + 1;
	    fi++;
	}
	if (word2[loop2] == '\0');
	else {
	    retWord[fi] = word2[loop2];
	    loop2 = i + 1;
	    fi++;
	}
    }
    return retWord;
}

int main() {
    char word1[MAX_LEN], word2[MAX_LEN];
    char *result;
    printf("Please enter two words with lower letters:\n");
    scanf("%s %s", word1, word2);
    result = mergeAlternately(word1, word2);
    printf("%s\n", result);
    free(result);
    return 0;
}
