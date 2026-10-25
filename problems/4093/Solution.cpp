// 4093. Maximize Sum After At Most K Digit Rearrangements

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<int> gains;
        gains.reserve(n);
        for (auto& v : nums) {
            sum += v;
            gains.push_back(rearrange(v) - v);
        }

        k = std::min<int>(k, gains.size());
        std::nth_element(gains.begin(), gains.begin() + k, gains.end(), std::greater<int>());
        for (int i = 0; i < k; i++) {
            sum += gains[i];
        }
        return sum;
    }

    int rearrange(int element) {
        vector<int> digits(10);
        while (element >= 10) {
            digits[element % 10]++;
            element = element / 10;
        }
        digits[element % 10]++;

        int value = 0;
        for (int i = 9; i >= 0; i--) {
            while (digits[i] > 0) {
                value *= 10;
                value += i;
                digits[i]--;
            }
        }
        return value;
    }
};
