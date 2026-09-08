// 3904. Smallest Stable Index II

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMax;
        vector<int> suffixMin(n);

        prefixMax = nums[0];
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < suffixMin[i + 1]) {
                suffixMin[i] = nums[i];
            } else {
                suffixMin[i] = suffixMin[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > prefixMax)
                prefixMax = nums[i];
            if (prefixMax - suffixMin[i] <= k)
                return i;
        }

        return -1;
    }
};
