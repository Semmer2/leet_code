#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

void dive(int** rooms, int roomNum, int* roomsColSize, bool** roomFlag) {
    for(int i = 0; i < roomsColSize[roomNum]; i++) {
        if((*roomFlag)[rooms[roomNum][i]]) {
            continue;
        } else {
            (*roomFlag)[rooms[roomNum][i]] = true;
            dive(rooms, rooms[roomNum][i], roomsColSize, roomFlag);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool flag = true;
    bool* roomFlag = (bool*)malloc(roomsSize * sizeof(bool));
    memset(roomFlag, 0, roomsSize * sizeof(bool));
    roomFlag[0] = true;
    dive(rooms, 0, roomsColSize, &roomFlag);
    for(int i = 0; i < roomsSize; i++) {
        flag = flag & roomFlag[i];
    }
    free(roomFlag);
    return flag;
}

int main() {
    int room1[] = {1,3};
    int room2[] = {3,0,1};
    int room3[] = {2};
    int room4[] = {0};
    int* rooms[] = {room1, room2, room3, room4};
    int roomsColSize[] = {2, 3, 2, 1};
    canVisitAllRooms(rooms, 4, roomsColSize);
    return 0;
}