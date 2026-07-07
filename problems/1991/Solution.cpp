// 1991. Find the Middle Index in Array

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        long long leftSum = 0;
        long long rightSum = 0;
        for (int i = 0; i < n; i++) {
            rightSum += nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (leftSum == rightSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
            rightSum -= nums[i];
        }
        return -1;
    }
};
