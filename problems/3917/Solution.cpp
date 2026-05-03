class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int odd = 0;
        int even = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] % 2 == 0)
                even++;
            else
                odd++;
            answer[i] = (nums[i] % 2 == 0) ? odd : even;
        }
        return answer;
    }
};
