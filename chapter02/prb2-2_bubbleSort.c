/* Just bubble sort.
 * T = Θ(n^2)
 */

#include<stdio.h>

// Sort A[n]
void bubbleSort(int A[], int n) {
    int i, j, t;

    for(i = 0; i < n-1; i++) {
        for(j = n-1; j > i; j--) {
            if(A[j] < A[j-1]) {
                t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
            }
        }
    }
}

// Test
int main() {
    int A[10] = {3, 5, 2, 7, 1, 4, 9, 10, 6, 8};
    int i;

    bubbleSort(A, 10);
    
    for(i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
