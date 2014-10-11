#include<stdio.h>

void insert(int suite[], int n) {
    int j = n-1;
    int key = suite[n-1];

    while(j > 0 && key < suite[j-1]) {
        suite[j] = suite[j-1];
        j--;
    }
    suite[j] = key;
}

void insertionSort(int suite[], int n) {
    if(n > 1) {
        insertionSort(suite, n-1);
        insert(suite, n);
    }
}

int main() {
    int suite[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;

    insertionSort(suite, 10);

    for(int i = 0; i < 10; i++)
        printf("%d ", suite[i]);
    printf("\n");

    return 0;
}
