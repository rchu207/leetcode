// 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int answer = n + 1;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target && left <= right) {
                auto length = right - left + 1;
                if (length < answer) {
                    answer = length;
                }
                sum -= nums[left];
                left++;
            }
        }
        return (answer <= n) ? answer : 0;
    }
};
