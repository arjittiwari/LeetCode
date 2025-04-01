/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int *returnArr = (int *)malloc(sizeof(int)*arrSize);
    *returnSize = arrSize;
    int i=arrSize-1;
    int max = arr[arrSize-1];
    while(i>=0) {
        returnArr[i]=max;
        if (max < arr[i]) {
            max = arr[i];
        }
        i--;
    }
    returnArr[arrSize-1] = -1;
    return(returnArr);
}