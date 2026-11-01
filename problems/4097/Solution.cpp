// 4097. Minimum Value of Merged Integers

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int answer = mergeIntegers(nums[0], nums[1]);
        for (int i = 2; i < n; i += 2) {
            auto tmp = mergeIntegers(nums[i], nums[i + 1]);
            if (tmp < answer) {
                answer = tmp;
            }
        }
        return answer;
    }

    int mergeIntegers(int a, int b) {
        if (b >= 1000) {
            return a * 10000 + b;
        } else if (b >= 100) {
            return a * 1000 + b;
        } else if (b >= 10) {
            return a * 100 + b;
        } else {
            return a * 10 + b;
        }
    }
};
