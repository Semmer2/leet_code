#include <stdio.h>

void moveZeroes(int *nums, int numSize) {
    int former = numSize - 2, latter = numSize - 1, end = numSize - 1, gap;
    //return directly for one element
    if(numSize <= 1) return;

    while (former >= 0) {
	//former is zero and the next is not zero or former is the last number
        if (!nums[former] && (former == 0 || nums[former - 1])) {
	    //update number
	    gap = latter - former;
	    for(int i = former; i <= end; i++) {
	        nums[i] = i + gap <= end ? nums[i + gap] : 0;
	    }
	    latter = former - 1;
	    end    = end - gap;
	    former = former - 2;
		if (former < 0) break;
	}
	//
	if (nums[former]) {
	    latter = former;
	    former--;
	} else if (!nums[former] && former >= 1 && !nums[former - 1]) {
		former--;
    }
	}
}

int main() {
    int nums[5] = {0, 1, 0, 3, 12};
    moveZeroes(nums, 5);
    for (int i = 0; i < 5; i ++)
        printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
