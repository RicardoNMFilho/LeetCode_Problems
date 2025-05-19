// Given an array of integers nums and an integer target, return 
// indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.
// You can return the answer in any order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare_int(const void * a, const void * b) {
    return (* (int *) a - *(int *) b);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* array = (malloc (2 * sizeof (int) ));
    int* copy = (malloc (numsSize * sizeof (int) ));
    int left = 0;
    int right = numsSize - 1;
    int find_left = 0;
    int find_right = 0;

    memcpy(copy, nums, numsSize * sizeof (int));

    qsort(copy, numsSize, sizeof(int), compare_int);

    while (left != right){
        if (copy[left] + copy[right] == target){
            break;
        }

        else if (copy[left] + copy[right] < target) {
            left = left + 1;
        }

        else {
            right = right - 1;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == copy[left] && find_left == 0){
            array[0] = i;
            find_left = 1;
        }

        else if (nums[i] == copy[right] && find_right == 0){
            array[1] = i;
            find_right = 1;
        }

        else if (find_left == 1 && find_right == 1) {
            break;
        }
    }

    free(copy);

    *returnSize = 2;
    return array;
}