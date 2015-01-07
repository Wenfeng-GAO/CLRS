/* 
 * This is the code of exercise 4.1.5
 * The Kanane liner method could be found in exe4.1_3, this is 
 * another point of view. But the core ideals are the same.
 */

#include <stdio.h>

typedef struct {
    unsigned left;
    unsigned right;
    int sum;
} max_subarray;

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high) {
    max_subarray suffixes[high - low];

    suffixes[0].left = low;
    suffixes[0].right = low + 1;
    suffixes[0].sum = A[low];

    for (int i = low + 1; i < high; i++) {
        if (suffixes[i-1].sum < 0) {
            suffixes[i].left = i;
            suffixes[i].right = i + 1;
            suffixes[i].sum = A[i];
        } else {
            max_subarray *previous = &suffixes[i-1];
            suffixes[i].left = previous -> left;
            suffixes[i].right = i + 1;
            suffixes[i].sum = previous -> sum + A[i];
        }
    }

    max_subarray *max = &suffixes[0];

    for (int i = low + 1; i < high; i++) {
        if (max -> sum < suffixes[i].sum) {
            max = &suffixes[i];
        }
    }

    return *max;
}

// Test
int main() {
    int A[] = {1, 2, -3, 4, 2, -4, 1, 1};

    max_subarray result = find_maximum_subarray(A, 0, 8);

    printf("The maximum subarray is [%d, %d), sum is %d\n", result.left, result.right, result.sum);

    return 0;
}




