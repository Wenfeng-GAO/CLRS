#include<stdio.h>

void merge(int suite[], int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q;
    int L[n1], R[n2];
    int i, j, k;

    for(i = 0; i < n1; i++)
        L[i] = suite[p+i];
    for(i = 0; i < n2; i++)
        R[i] = suite[q+1+i];

    i = j = 0;
    for(k = p; k <= r; k++) {
        if(i < n1 && j < n2) {
            if(L[i] < R[j]) 
                suite[k] = L[i++];
            else 
                suite[k] = R[j++];
        }else {
            while(i < n1)  
                suite[k++] = L[i++];
            while(j < n2) 
                suite[k++] = R[j++];
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
    int suite[10] = {10, 9, 8, 1, 6, 19, 4, 3, 2, 1};
    int i;

    mergeSort(suite, 0, 9);

    for(i = 0; i < 10; i++)
        printf("%d ", suite[i]);
    printf("\n");

    return 0;
}

        
            
