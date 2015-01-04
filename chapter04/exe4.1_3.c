/* This is the code for exercise 4.1-3
 *
 * To deal with an array of 1000000 integers(on my computer):
 * Force-brute method takes about 23 minutes(1395.370951s)
 * Divide-and-conquer method takes 0.109961s
 * Mixed method takes 0.106232s
 * Kadane liner mathod takes 0.005353s
 *
 * That's amazing!
 */

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CROSSOVER_POINT 37
#define LIST_LEN 1000000

// a struct to represent the tuple
typedef struct {
    int left;
    int right;
    int sum;
} max_subarray;

// The brute force approach
max_subarray find_maximum_subarray_brute(int A[], unsigned low, unsigned high) {
    max_subarray result = {-1, -1, 0};

    for (int i = low; i < high; i++) {
        int current_sum = 0;
        for (int j = i; j < high; j++) {
            current_sum += A[j];
            if (result.sum < current_sum) {
                result.left = i;
                result.right = j + 1;
                result.sum = current_sum;
            }
        }
    }

    return result;
}

// The divide-and-conquer solution
max_subarray find_max_crossing_subarray(int A[], int low, int mid, int high) {
    max_subarray result = {-1, -1, 0};
    int sum = 0,
        left_sum = INT_MIN,
        right_sum = INT_MIN;

    for (int i = mid - 1; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            result.left = i;
        }
        
    }

    sum = 0;

    for (int j = mid; j < high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            result.right = j + 1;
        }
    }

    result.sum = left_sum + right_sum;
    return result;
}

max_subarray find_maximum_subarray(int A[], int low, int high) {
    if (high == low + 1) {
        max_subarray result = {low, high, A[low]}; 
        return result;
    } else {
        int mid = (low + high) / 2;
        max_subarray left = find_maximum_subarray(A, low, mid);
        max_subarray right = find_maximum_subarray(A, mid, high);
        max_subarray cross = find_max_crossing_subarray(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross;
        }
    }
}

// The mixed algorithm
max_subarray find_maximum_subarray_mixed(int A[], int low, int high) {
    if (high - low < CROSSOVER_POINT) {
        return find_maximum_subarray_brute(A, low, high);
    } else {
        int mid = (low + high) / 2;
        max_subarray left = find_maximum_subarray_mixed(A, low, mid);
        max_subarray right = find_maximum_subarray_mixed(A, mid, high);
        max_subarray cross = find_max_crossing_subarray(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross;
        }
    }
}

// Kadane liner algorithm
max_subarray find_maximum_subarray_liner(int A[]) {
    max_subarray result = {-1, -1, 0};
    int max_sum = 0,
        latest_sum = 0,
        latest_left = -1,
        latest_right = -1,
        max_left = -1,
        max_right = -1;
    for (int i = 0; i < LIST_LEN; i++) {
        int s = latest_sum + A[i];
        if (s > 0 && latest_sum == 0) {
            latest_sum = s;
            latest_left = i;
            latest_right = latest_left + 1;
        } else if (s > 0 && latest_sum > 0) {
            latest_sum = s;
            latest_right++;
        } else {
            latest_sum = 0;
        }

        if (max_sum < latest_sum) {
            max_sum = latest_sum;
            max_left = latest_left;
            max_right = latest_right;
        }
    }

    result.left = max_left;
    result.right = max_right;
    result.sum = max_sum;

    return result;
}

// Generate an array
void generate_array(int A[]) {
    printf("List: [");
    for (int i = 0; i < LIST_LEN; i++) {
        A[i] = rand() % 40 - 20;
        printf("%d ", A[i]);
    }
    printf("]\n");
}

// Print the result
void show_result(max_subarray result) {
    printf("The maximum sum is %d, and the period is in [%d,%d)\n", result.sum, result.left, result.right);
}

int main() {
    //int A[LIST_LEN];
    clock_t begin, end;
    double time_spent;
    
    // generate_array(A);
    int A[LIST_LEN];
    generate_array(A);
    printf("\n");
    
    // Kadane liner
    begin = clock();
    show_result(find_maximum_subarray_liner(A));
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("*Kadane liner* takes time: %f\n", time_spent);
    printf("\n");

    // Divide-and-conquer
    begin = clock();
    show_result(find_maximum_subarray(A, 0, LIST_LEN));
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("*Divide-and-conquer* takes time: %f\n", time_spent);
    printf("\n");

    // Mixed
    begin = clock();
    show_result(find_maximum_subarray_mixed(A, 0, LIST_LEN));
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("*Mixed* takes time: %f\n", time_spent);
    printf("\n");

    // Brute
    begin = clock();
    show_result(find_maximum_subarray_brute(A, 0, LIST_LEN));
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("*Brute* takes time: %f\n", time_spent);
    printf("\n");

    return 0;
}
