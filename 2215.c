#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX_LEN 1000
#define HASH_LEN 2001

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    bool* table1 = (bool*)malloc(HASH_LEN * sizeof(bool));
    bool* table2 = (bool*)malloc(HASH_LEN * sizeof(bool));
    int count1 = 0, count2 = 0;
    int* ret1 = NULL,* ret2 = NULL,** ret;
    //calloc?
    for (int i = 0; i < HASH_LEN; i++)
    {
        table1[i] = false;
        table2[i] = false;
    }
    //reset table pointer to the middle
    table1 = table1 + MAX_LEN;
    table2 = table2 + MAX_LEN;

    //update tables
    for(int i = 0; i < nums1Size; i++) {
        table1[nums1[i]] = true;
    }
    for(int i = 0; i < nums2Size; i++) {
        if(!table1[nums2[i]]) {
            table1[nums2[i]] = true;
            ret2 = (int*)realloc(ret2, (count2 + 1) * sizeof(int));
            ret2[count2] = nums2[i];
            count2++;
        }
        table2[nums2[i]] = true;
    }

    for (int i = 0; i < nums1Size; i++)
    {
        if(!table2[nums1[i]]) {
            table2[nums1[i]] = true;
            ret1 = (int*)realloc(ret1, (count1 + 1) * sizeof(int));
            ret1[count1] = nums1[i];
            count1++;
        }
    }

    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = count1;
    (*returnColumnSizes)[1] = count2;
    ret = (int**)malloc(2 * sizeof(int*));
    ret[0] = ret1;
    ret[1] = ret2;
    //free mem
    table1 = table1 - MAX_LEN;
    table2 = table2 - MAX_LEN;
    free(table1);
    free(table2);

    return ret;
}
int main() {
    int nums1[] = {1,2,3};
    int nums2[] = {2,4,6};
    int returnSize;
    int* returnColumnSize;
    findDifference(nums1, 3, nums2, 3, &returnSize, &returnColumnSize);
    return 0;
}