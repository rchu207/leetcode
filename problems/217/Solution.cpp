// 217. Contains Duplicate

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> table;
        for (auto& v : nums) {
            if (table.count(v) > 0) {
                table.erase(v);
            } else {
                table.insert(v);
            }
        }
        auto iter = table.begin();
        return *iter;
    }
};
