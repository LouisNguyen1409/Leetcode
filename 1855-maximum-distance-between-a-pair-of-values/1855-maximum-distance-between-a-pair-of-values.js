function maxDistance (nums1, nums2) {
    const l1 = nums1.length;
    const l2 = nums2.length;
    let max = 0;
    let j = 0;
    for (let i = 0; i < l1; i++) {
        while (j < l2 && nums1[i] <= nums2[j]) {
            j++;
        }
        max = Math.max(max, j - i - 1);
    }
    return max;
}