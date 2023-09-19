double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = 0;
    int j = 0;  
    int k = 0;
    int arr[nums1Size + nums2Size];
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            arr[k] = nums1[i];
            i++;
        }
        else {
            arr[k] = nums2[j];
            j++;
        }
        k++;
    }

    while (i < nums1Size) {
        arr[k] = nums1[i];
        i++;
        k++;
    }
 
    while (j < nums2Size) {
        arr[k] = nums2[j];
        j++;
        k++;
    }

    if ((nums1Size + nums2Size) % 2 != 0) {
        return arr[(nums1Size + nums2Size) / 2];
    }
    
    return (double)(arr[(nums1Size + nums2Size) / 2 - 1] + arr[(nums1Size + nums2Size) / 2]) / 2;
}