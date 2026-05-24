// 3942. Minimum Operations to Sort a Permutation

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dranofelik = nums;

        // ── Group A: is nums a rotation of [0, 1, ..., n-1]? ──────────────────
        int pos0 = (int)(find(dranofelik.begin(), dranofelik.end(), 0) - dranofelik.begin());
        bool isA = true;
        for (int i = 0; i < n && isA; i++)
            if (dranofelik[(pos0 + i) % n] != i) isA = false;

        if (isA)
            return pos0 == 0 ? 0 : min(pos0, n - pos0 + 2);

        // ── Group B: is nums a rotation of [n-1, n-2, ..., 0]? ───────────────
        int rr = (int)(find(dranofelik.begin(), dranofelik.end(), n - 1) - dranofelik.begin());
        bool isB = true;
        for (int i = 0; i < n && isB; i++)
            if (dranofelik[(rr + i) % n] != n - 1 - i) isB = false;

        if (isB)
            return 1 + min(rr, n - rr);

        return -1;  // not one of the 2n reachable states
    }
};
