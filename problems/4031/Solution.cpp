// 4031. Find All Numbers Disappeared in an Array II

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> answer;
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        while (lower <= upper && i < n) {
            if (lower < nums[i]) {
                if (upper <= nums[i] - 1) {
                    answer.push_back({lower, upper});
                    lower = upper + 1;
                } else {
                    answer.push_back({lower, nums[i] - 1});
                    lower = nums[i] + 1;
                }
            } else if (lower == nums[i]) {
                lower = nums[i] + 1;
            }
            i++;
        }

        if (lower <= upper) {
            answer.push_back({lower, upper});
        }

        return answer;
    }
};
