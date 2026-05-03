class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        for (int i = 0; i < n - 1; i++) {
            auto parity = (nums[i] + 1) % 2;
            auto count = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % 2 == parity)
                    count++;
            }
            answer[i] = count;
        }
        return answer;
    }
};
