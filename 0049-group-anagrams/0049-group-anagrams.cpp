class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_arr;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); ++i) {
            auto word = strs[i];
            sort(word.begin(), word.end());
            map_arr[word].push_back(strs[i]);
        } 

        for (auto e: map_arr) {
            result.push_back(e.second);
        }
        return result;
    }
};