/**
 * @file get_sum.c
 * 
 * @brief 371. Sum of Two Integers
 * Calculate the sum of two integers a and b, but you are not allowed to use the
 * operator + and -.
 *
 * Example:
 * Given a = 1 and b = 2, return 3.
 *
 */
#include <stdio.h>

int getSum(int a, int b) {
        char fa, fb, ff, fr, r;

        ff = r = 0;
        while (a || b) {
                fa = a & 1;
                fb = b & 1;
                
                if (!(fa | fb | ff))
                        fr = ff = 0;
                else if (fa & fb & ff) 
                        fr = ff = 1;
                else if (fa ^ fb ^ ff) {
                        fr = 1;
                        ff = 0;
                } else if (!(fa ^ fb ^ ff)) {
                        fr = 0;
                        ff = 1;
                }

                r = r << 1 | fr;
                a >>= 1;
                b >>= 1;
        }
        return r;
}

int main(void) {
        int a, b;

        while(scanf("%d %d", &a, &b)) {
                printf("%d\n", getSum(a, b));
        }

        return 0;
}
