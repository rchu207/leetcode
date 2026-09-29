// 4065. Rearrange Array by Removing Distinct Values

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> table(101, 0);
        vector<int> ans;

        for (auto& v : nums) {
            table[v]++;
        }

        bool update = true;
        while (update) {
            update = false;
            for (int i = 1; i <= 100; i++) {
                if (table[i] > 0) {
                    ans.push_back(i);
                    table[i]--;
                    update = true;
                }
            }
        }
        return ans;
    }
};
