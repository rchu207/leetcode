// 4083. Minimum Deletions to Make Array Sharp

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] == nums[i]) {
                answer++;
            }
        }

        return answer;
    }
};
