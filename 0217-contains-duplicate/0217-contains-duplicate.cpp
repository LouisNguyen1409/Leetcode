class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // O(n)
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); ++i) {
            if (set.count(nums[i])) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;

        // O(n)
        /*
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (map.find(num) != map.end()) {
                return true;
            }
            map[num] = i;
        }
        return false;
        */
    }
};