// 3927. Minimize Array Sum Using Divisible Replacements
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen;
        long long sum = 0;

        for (int x : nums) {
            int best = x;
            for (int d = 1; (long long)d * d <= x; d++) {
                if (x % d == 0) {
                    if (seen.count(d)) {
                        best = min(best, d);
                    }
                    if (seen.count(x / d)) {
                        best = min(best, x / d);
                    }
                }
            }
            seen.insert(x);
            sum += best;
        }
        return sum;
    }
};
