#include<stdio.h>
int suite[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void sort(int suite[], int l) {
    int i,j,k,min;

    for(i = 0; i < l-1; i++) {
        k = i;
        min = suite[i];
        for(j = i+1; j < l; j++) {
            if(suite[j] < min) {
                min = suite[j];
                k = j;
            }
        }
        suite[k] = suite[i];
        suite[i] = min;
    }
}

int main() {
    int i;

    sort(suite, 10);

    for(i = 0; i < 10; i++) 
        printf("%d ", suite[i]);
    printf("\n");

    return 0;
}
