class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<int, int> map1, map2;
        for (int i = 0; i < s.length(); ++i) {
            auto it1 = map1.find(s[i]);
            if ( it1 != map1.end()) {
                it1->second += 1;
            } else {
                map1.insert({s[i], 1});
            }

            auto it2 = map2.find(t[i]);
            if (it2 != map2.end()) {
                it2->second += 1;
            } else {
                map2.insert({t[i], 1});
            }
        }
        
        return map1 == map2;
    }
};