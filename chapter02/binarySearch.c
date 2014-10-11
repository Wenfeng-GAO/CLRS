#include<stdio.h>
int sortedSuite[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int binarySearch(int A[], int key, int low, int high) {
    int mid;

    if(low > high)
        return -1;
    mid = (low + high) / 2;
    if(key == A[mid])
        return mid;
    else if(key < A[mid])
        return binarySearch(A, key, low, mid-1);
    else
        return binarySearch(A, key, mid+1, high);
}


int main() {
    int i;

    while(1) {
        scanf("%d", &i);
        printf("%d\n", binarySearch(sortedSuite, i, 0, 9));
    }

    return 0;

}
