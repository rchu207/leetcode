// 3940. Limit Occurrences in Sorted Array

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        int answer = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                count = 1;
                nums[answer] = nums[i];
                answer++;
            } else if (count < k) {
                count++;
                nums[answer] = nums[i];
                answer++;
            }        
        }

        nums.resize(answer);
        return nums;
    }
};
