class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> answer = nums;
        for (int i = nums.size() - 1; i >= 0; --i) {
            answer.push_back(nums[i]);
        }
        return answer;
    }
};
