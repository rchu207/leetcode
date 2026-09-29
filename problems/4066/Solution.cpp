// 4066. Maximum Equal Adjacent Pairs After at Most One Replacement

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        // Replacing every x with y turns each adjacent (x, y) or (y, x) pair
        // into an equal pair, and never breaks an existing equal pair.
        // So answer = existing equal pairs + most frequent unordered {a, b} pair.
        int n = nums.size();
        int equalPairs = 0;
        int bestGain = 0;
        std::unordered_map<long long, int> pairCount;
        for (int i = 0; i < n - 1; i++) {
            auto x = nums[i];
            auto y = nums[i + 1];
            if (x == y) {
                equalPairs++;
                continue;
            }
            if (x > y)
                std::swap(x, y);
            long long key = ((long long)(unsigned int)x << 32) | (unsigned int)y;
            bestGain = std::max(bestGain, ++pairCount[key]);
        }
        return equalPairs + bestGain;
    }
};
