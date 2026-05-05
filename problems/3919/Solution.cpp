class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        for (int i = 0; i < n; i++) {
            auto leftDiff = (i == 0) ? 2000000001 : (nums[i] - nums[i - 1]);
            auto rightDiff = (i == n - 1) ? 2000000001 : (nums[i + 1] - nums[i]);
            if (rightDiff < leftDiff) {
                closest[i] = i + 1;
            } else {
                closest[i] = i - 1;
            }
        }

        // move right
        vector<int> preRight(n);
        for (int i = 1; i < n; i++) {
            int cost = (closest[i - 1] == i) ? 1 : (nums[i] - nums[i - 1]);
            preRight[i] = preRight[i - 1] + cost;
        }

        // move left
        vector<int> preLeft(n);
        for (int i = n - 2; i >= 0; i--) {
            int cost = (closest[i + 1] == i) ? 1 : (nums[i + 1] - nums[i]);
            preLeft[i] = preLeft[i + 1] + cost;
        }

        // process query
        vector<int> answer;
        for (auto& q : queries) {
            auto l = q[0];
            auto r = q[1];
            if (l <= r) {
                answer.push_back(preRight[r] - preRight[l]);
            } else {
                answer.push_back(preLeft[r] - preLeft[l]);
            }
        }
        return answer;
    }
};