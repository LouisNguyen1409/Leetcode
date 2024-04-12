class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (map.find(num) != map.end()) {
                return true;
            }
            map[num] = i;
        }
        return false;
    }
};