// 1. Two Sum

#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            auto y = target - nums[i];
            if (hashmap.count(y) > 0) {
                return {i, hashmap[y]};
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};
