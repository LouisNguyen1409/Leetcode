class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time complexity: O(n)
        vector<int> result;
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        // O(n)
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // O(n)
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        // O(n)
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(prefix[i] * suffix[i]);
        }

        return result;
    }
};