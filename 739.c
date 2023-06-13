#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define INT_MIN (1 << 31)
#define INT_MAX (1 << 32 - 1)

typedef struct Stack {
    struct Stack *next;
    int value;
}Stack;

//pop value out of stack, will return false if the pop failed
bool popStack(Stack** s, int* value) {
    Stack* p;
    if((*s)) {
        p = (*s)->next;
        (*value) = (*s)->value;
        free(*s);
        (*s) = p;
    } else {
        //(*s) is NULL
        return false;
    }
    return true;
}

//push value in stack
void pushStack(Stack** s, int *value) {
    Stack* p = (Stack*)malloc(sizeof(Stack));
    if(!p)return;
    p->value = (*value);
    //it works well even if (*s) is NULL;
    p->next  = (*s);
    (*s)     = p;
    return;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    Stack* s = NULL;
    int currValue = 0;
    int* ret = (int*)malloc(temperaturesSize * sizeof(int));
    for(int i = 0; i < temperaturesSize; i++) {
        ret[i] = 0;
        while((s) && temperatures[i] > temperatures[s->value]) {
            popStack(&s, &currValue);
            ret[currValue] = i - currValue;
        }
        pushStack(&s, &i);
    }
    *returnSize = temperaturesSize;
    return ret;
}


int main() {
    int tmp;
    int temperatures[] = {30,40,50,60};
    dailyTemperatures(temperatures, 4, &tmp);
    return 0;
}