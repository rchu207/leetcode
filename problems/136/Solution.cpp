// 136. Single Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int result = 0;
    for (auto& v : nums)
        result ^= v;
    return result;
    }
};
