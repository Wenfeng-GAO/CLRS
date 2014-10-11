#include<stdio.h>
#define SENS 1000
int suite[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void merge(int suite[], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    int L[n1+1], R[n2+1];

    for(i = 0; i < n1; i++)
        L[i] = suite[p+i];
    for(i = 0; i < n2; i++) 
        R[i] = suite[q+1+i];
    L[n1] = R[n2] = SENS;

    i = j = 0;
    for(k = p; k <= r; k++) {
        if(L[i] < R[j]) {
            suite[k] = L[i];
            i++;
        }else {
            suite[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int suite[], int p, int r) {
    int q = (p+r)/2;

    if(p < r) {
        mergeSort(suite, p, q);
        mergeSort(suite, q+1, r);
        merge(suite, p, q, r);
    }

}

int main() {
    int i;

    mergeSort(suite, 0, 9);

    for(i = 0; i < 10; i++)
        printf("%d ", suite[i]);
    printf("\n");

    return 0;
}
