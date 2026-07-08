// 747. Largest Number At Least Twice of Others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int largest = nums[0];
        int answer = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
                answer = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != answer && nums[i] * 2 > largest) {
                return -1;
            }
        }
        return answer;
    }
};
