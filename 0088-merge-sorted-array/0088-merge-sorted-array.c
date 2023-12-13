void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *temp = malloc(m * sizeof(int)); 
    for (int i = 0; i < m; i++) {
        temp[i] = nums1[i];
    }
    int j = 0;
    int i = 0;
    int l = 0;
    while (i < m && j < n) {
        if (temp[i] <= nums2[j]) {
            nums1[l] = temp[i];
            i++;
        } else if (temp[i] > nums2[j]) {
            nums1[l] = nums2[j];
            j++;
        }
        l++;
    }

    while (i < m) { 
        nums1[l] = temp[i]; 
        i++; 
        l++; 
    } 
    while (j < n) { 
        nums1[l] = nums2[j]; 
        j++; 
        l++; 
    } 
}