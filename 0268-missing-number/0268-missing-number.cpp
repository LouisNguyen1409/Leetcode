class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // O(n)
        int n = nums.size();
        int sum = n*(n+1)/2;
        return sum - accumulate(nums.begin(), nums.end(), 0);
        
        /*
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] + 1 != nums[i+1]) {
                return nums[i] + 1;
            }
        }
        // O(n log n)
        return nums[0] != 0 ? 0 : nums[nums.size() - 1] + 1;
        */
    }
};