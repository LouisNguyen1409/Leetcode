class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        // O(n)
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int complete = target - num;
            auto finding = map.find(complete);
            if (finding != map.end()) {
                return {finding->second, i};
            }
            map[num] = i;
        }
        return {};
        /*
        vector<pair<int, int>> sort_array;

        // O(n)
        for (int i = 0; i < nums.size(); ++i) {
            sort_array.push_back(make_pair(nums[i], i));
        }

        // O(n logn)
        sort(sort_array.begin(), sort_array.end());

        // O(n)
        int i = 0;
        for (int j = sort_array.size() - 1; j >= 0; --j) {
            while (i < sort_array.size()) {
                if (sort_array[i].first + sort_array[j].first == target) {
                    return {sort_array[i].second, sort_array[j].second}
                } else if (sort_array[i].first + sort_array[j].first < target) { 
                    i++;
                } else {
                    break;
                }
            }
        }

        // Total time complexity is O(n logn)
        return {};
        */
    }
};