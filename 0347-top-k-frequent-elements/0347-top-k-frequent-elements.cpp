class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto num: nums) {
            map[num]++;
        }

        vector<pair<int, int>> arr(map.begin(), map.end());
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < k && i < arr.size(); ++i) {
            result.push_back(arr[i].first);
        }
        return result;
    }
};