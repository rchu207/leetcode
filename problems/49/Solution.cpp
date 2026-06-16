// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (const auto& s : strs) {
            auto key = s;
            std::sort(key.begin(), key.end());
            hashmap[key].push_back(s);
        }
        vector<vector<string>> answer;
        for (const auto& [key, value] : hashmap) {
            answer.push_back(value);
        }
        return answer;
    }
};
