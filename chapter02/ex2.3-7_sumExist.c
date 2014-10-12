/* This is the answer to exercise 2.3-7,
 * which to determine whether or not there exist 2 integers in the
 * array A, so that their sum is the given integer x.
 * The question demands a time complexity of Θ(nlgn).
 */

#include<stdio.h>

void mergeSort(int A[], int p, int r);
int binarySearch(int A[], int key, int low, int high);

// First sort A with mergeSort
// Then for every a in A[0, n-1], use binarySearch to find x-a
// If there exists x-a, return 1, else return 0
int sumExist(int A[], int n, int x) {
    int i;

    mergeSort(A, 0, n-1);
    for(i = 0; i < n-1; i++) {
        if(binarySearch(A, x-A[i], i+1, n-1)) 
            return 1;
    }
    return 0;
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int L[n1], R[n2];
    int i, j, k;

    for(i = 0; i < n1; i++) 
        L[i] = A[i+p];
    for(j = 0; j < n2; j++)
        R[j] = A[j+q+1];

    i = j = 0;
    for(k = p; k <= r; k++) {
        if(L[i] < R[j])  
            A[k] = L[i++];
        else 
            A[k] = R[j++];
        while(i == n1 && j < n2)
            A[++k] = R[j++];
        while(j == n2 && i < n1)
            A[++k] = L[i++];
    }
}

void mergeSort(int A[], int p, int r) {
    int q = (p+r)/2;

    if(p < r) {
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int binarySearch(int A[], int key, int low, int high) {
    int mid;

    if(low > high)
        return 0;
    mid = (low+high)/2;
    if(key == A[mid]) 
        return 1;
    else if(key < A[mid])
        return binarySearch(A, key, low, mid-1);
    else
        return binarySearch(A, key, mid+1, high);
}

// Test the result
int main() {
    int A[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};
    int x;
    int i;

    while(1) {
        printf("Enter a integer: ");
        scanf("%d", &x);
        if(sumExist(A, 10, x))
            printf("Exist!\n");
        else
            printf("NOT Exist!\n");
    }

    return 0;
}
