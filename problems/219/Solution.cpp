// 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            auto v = nums[i];
            if (hashmap.count(v) > 0) {
                if (i - hashmap[v] <= k)
                    return true;
            }
            hashmap[v] = i;
        }
        return false;
    }
};
