#include<stdio.h>
int suite[10] = {10,9,8,7,6,5,4,3,2,1};

void sort(int suite[], int l) {
    int i, j, key;

    for(i = 1; i < l; i++) {
        key = suite[i];
        j = i - 1;
        while(j >= 0 && key > suite[j]) {
            suite[j+1] = suite[j];
            j--;
        }
        suite[j+1] = key;
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
