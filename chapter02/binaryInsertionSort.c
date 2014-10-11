/* Exercise 2.3-6
 * I use the recursive method to sort,
 * and use binary search algorithm to find the insertion position.
 * But we cannot improve the time to Θ(nlgn), 
 * because we have to move all the elements after the position each
 * time we insert, just like the insertion sort algorithm does.
 */

#include<stdio.h>

// Search the value 'key' in the array 'A' whose range is [low, high]
int binarySearch(int A[], int key, int low, int high) {
    int mid;

    if(low < high) {
        mid = (low+high)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return binarySearch(A, key, low, mid-1);
        else
            return binarySearch(A, key, mid+1, high);
    }else {
        if(key <= A[low])
            return low;
        else
            return low+1;
    }
}

// Insert the value 'A[n]' at position 'position' in the
// array 'A', which has already 'n' sorted elements
void insert(int A[], int position, int n) {
    int key = A[n];
    while(n > position) { 
        A[n] = A[n-1];
        n--;
    }
    A[position] = key;
}

void insertionSort(int A[], int n) {
    if(n > 1) {
        insertionSort(A, n-1);
        insert(A, binarySearch(A, A[n-1], 0, n-2), n-1);
    }
}

int main() {
    // a test A
    int A[10] = {1, 3, 2, 10, 7, 6, 5, 8, 9, 4};
    int i;

    insertionSort(A, 10);

    for(i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
