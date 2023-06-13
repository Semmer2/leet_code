#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

/* first version, 68/76 passed
void dfs(bool** connectionGrid, int cityNum, bool* cityConnectionStatus, int currentCity,
         int* changeCount) {
    for(int i = 0; i < cityNum; i++) {
        if(connectionGrid[i][currentCity] && !cityConnectionStatus[i]) {
            cityConnectionStatus[i] = true;
            dfs(connectionGrid, cityNum, cityConnectionStatus, i, changeCount);
        }
    }
    for(int i = 0; i < cityNum; i++) {
        if(connectionGrid[currentCity][i] &&  !cityConnectionStatus[i]) {
            cityConnectionStatus[i] = true;
            (*changeCount)++;
            dfs(connectionGrid, cityNum, cityConnectionStatus, i, changeCount);
        }
    }
}*/

/* second version, 69/76 passed
void dfs(bool** connectionGrid, int cityNum, bool* cityConnectionStatus, int currentCity,
         int* changeCount) {
    for(int i = 0; i < cityNum; i++) {
        if(!cityConnectionStatus[i]) {
            if(connectionGrid[i][currentCity]) {
                cityConnectionStatus[i] = true;
                dfs(connectionGrid, cityNum, cityConnectionStatus, i, changeCount);
            } else if(connectionGrid[currentCity][i]) {
                cityConnectionStatus[i] = true;
                (*changeCount)++;
                dfs(connectionGrid, cityNum, cityConnectionStatus, i, changeCount);
            }
        }
    }
}
*/

/*
third version, use double linked list to pass the question
*/

typedef struct DoubleLinkedList {
    int cityNum;
    int NextNodeNum;
    struct DoubleLinkedList** Next;
    int PrevNodeNum;
    struct DoubleLinkedList** Prev;
} DoubleLinkedList;

void dfs(DoubleLinkedList* prevCity, DoubleLinkedList* currentCity, int* changeCount) {
    while(currentCity->PrevNodeNum) {
        if(currentCity->Prev[currentCity->PrevNodeNum - 1] != prevCity) {
            dfs(currentCity, currentCity->Prev[currentCity->PrevNodeNum - 1], changeCount);
        }
        currentCity->PrevNodeNum--;
    }
    while(currentCity->NextNodeNum) {
        if(currentCity->Next[currentCity->NextNodeNum - 1] != prevCity) {
            (*changeCount)++;
            dfs(currentCity, currentCity->Next[currentCity->NextNodeNum - 1], changeCount);
        }
        currentCity->NextNodeNum--;
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int changeCount = 0;
    int cityNum = n;
    DoubleLinkedList city[n];
    DoubleLinkedList* currentCity = &city[0];
    for (int i = 0; i < n; i++) {
        city[i].cityNum = i;
        city[i].NextNodeNum = 0;
        city[i].Next = NULL;
        city[i].PrevNodeNum = 0;
        city[i].Prev = NULL;
    }
    //build link
    for(int i = 0; i < connectionsSize; i++) {
        city[connections[i][0]].NextNodeNum++;
        city[connections[i][0]].Next = (DoubleLinkedList**)realloc(city[connections[i][0]].Next,
                                                                   city[connections[i][0]].NextNodeNum *
                                                                   sizeof(DoubleLinkedList*));
        city[connections[i][0]].Next[city[connections[i][0]].NextNodeNum - 1] = &(city[connections[i][1]]);

        city[connections[i][1]].PrevNodeNum++;
        city[connections[i][1]].Prev = (DoubleLinkedList**)realloc(city[connections[i][1]].Prev,
                                                                   city[connections[i][1]].PrevNodeNum *
                                                                   sizeof(DoubleLinkedList*));
        city[connections[i][1]].Prev[city[connections[i][1]].PrevNodeNum - 1] = &(city[connections[i][0]]);
    }

    dfs(NULL, currentCity, &changeCount);
    return changeCount;
}

int main() {
    int* connections[5];
    int c0[] = {0,1};
    int c1[] = {1,3};
    int c2[] = {2,3};
    int c3[] = {4,0};
    int c4[] = {4,5};
    connections[0] = c0;
    connections[1] = c1;
    connections[2] = c2;
    connections[3] = c3;
    connections[4] = c4;
    minReorder(6, connections, 5, NULL);
    return 0;
}