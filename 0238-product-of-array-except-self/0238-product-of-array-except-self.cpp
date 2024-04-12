class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time complexity: O(n)
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefix(n);
        prefix[0] = 1;
        vector<int> suffix(n);
        suffix[n-1] = 1;

        // O(n)
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // O(n)
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        // O(n)
        for (int i = 0; i < n; ++i) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};