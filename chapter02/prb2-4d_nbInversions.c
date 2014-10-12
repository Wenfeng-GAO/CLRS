/* The question is to calculate the number of inversions
 * in an array with a Θ(nlgn) algorithm.
 * I modified the merge sort to get the number 'n'.
 */

#include<stdio.h>
int mergeAndCal(int A[], int p, int q, int r);

int nbInversions(int A[], int p, int r) {
    int q = (p+r)/2;
    int n = 0;

    if(p < r) {
        n += nbInversions(A, p, q);
        n += nbInversions(A, q+1, r);
        n += mergeAndCal(A, p, q, r);
    }

    return n;
}

int mergeAndCal(int A[], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q;
    int L[n1], R[n2];
    int i, j, k, n = 0;
    
    for(i = 0; i < n1; i++)
        L[i] = A[i+p];
    for(j = 0; j < n2; j++)
        R[j] = A[j+q+1];

    i = j = 0;
    for(k = p; k <= r; k++) {
        if(R[j] < L[i]) {
            A[k] = R[j++];
            n += n1-i; // Because if R[j] < L[i] then R[j] < L[i+1...n1-1]
        }
        else
            A[k] = L[i++];

        while(i == n1 && j < n2)
            A[++k] = R[j++];
        while(j == n2 && i < n1)
            A[++k] = L[i++];
    }

    return n;
}

// Test
int main() {
    int A[5] = {2, 3, 8, 6, 1};

    printf("%d\n", nbInversions(A, 0, 4));

    return 0;
}
