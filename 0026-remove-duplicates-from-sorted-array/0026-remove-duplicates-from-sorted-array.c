// int binarySearch(int arr[], int l, int r, int x)
// {
//     while (l <= r) {
//         int m = l + (r - l) / 2;
//         if (arr[m] == x) {
//             return m;
//         }
//         if (arr[m] < x) {
//             l = m + 1;
//         } else {
//             r = m - 1;
//         }
//     }
//     return -1;
// }

// int removeDuplicates(int* nums, int numsSize) {
//     int size = numsSize - 1;
//     for (int i = 0; i < numsSize; i++) {
//         int duplicate = binarySearch(nums, i + 1, numsSize - 1, nums[i]);
//         printf("%d ", duplicate);
//         if (duplicate != -1) {
//             numsSize --;
//             for (int j = duplicate; j < numsSize; j++) {
//                 int temp = nums[j + 1];
//                 nums[j + 1] = nums[j];
//                 nums[j] = temp;
//             }
//             i --;
//         }
//     }
//     return numsSize;
// }

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int k = 1; // Initialize the count of unique elements to 1
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i]; // Overwrite the next unique element
            k++;
        }
    }

    return k;
}