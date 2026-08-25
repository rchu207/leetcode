// 3718. Smallest Missing Multiple of K

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> values(101, 0);
        for (auto& v : nums) {
            values[v] = 1;
        }
        int index = k;
        while (index <= 100 && values[index] != 0) {
            index += k;
        }
        return index;
    }
};
