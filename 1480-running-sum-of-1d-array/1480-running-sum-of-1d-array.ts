function runningSum(nums: number[]): number[] {
    let ans: number[] = [];
    const length = nums.length;
    for (let i = 0; i < length; i++) {
        if (i === 0) {
            ans[i] = nums[i];
        } else {
            ans[i] = nums[i] + ans[i-1];
        }
        
    }
    return ans;
};