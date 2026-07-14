// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        int left = -1;
        int right = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                right++;
            } else {
                auto count = right - left;
                if (count > answer) {
                    answer = count;
                }
                left = i;
                right = i;
            }
        }
        auto count = right - left;
        if (count > answer) {
            answer = count;
        }
        return answer;
    }
};
