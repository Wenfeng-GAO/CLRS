#include<stdio.h>

int binarySearch(int A[], int key, int low, int high) {
    int mid;
    while(low <= high) {
        mid = (low+high)/2;
        if(key == A[mid]) 
            return mid;
        else if(key < A[mid])
            high = mid-1;
        else 
            low = mid+1;
    }
    return -1;
}

int main() {
    int suite[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key, i;

    while(1) {
        printf("Entrez le nombre:\n");
        scanf("%d", &key);
        printf("%d\n",binarySearch(suite, key, 0, 9));
    }

    return 0;
}
