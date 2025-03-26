#include <limits.h>
int maxSubArray(int* nums, int numsSize) {
    int maxSum = INT_MIN, i =0, sum = 0;
    while (i < numsSize) {
        sum = nums[i] + sum;
        if (maxSum < sum) {
            maxSum = sum;
        }
        if (0 >= sum) {
            sum = 0;
        }
        i++;
    }
    return (maxSum);
}